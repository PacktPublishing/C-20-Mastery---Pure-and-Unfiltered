#include <array>
#include <numeric>
#include <span>
#include <vector>
#include "../print.h"
template<typename T, std::size_t size>
void PrintSpan(std::span<T, size> sp,std::string_view message="", std::size_t max = size) {
	print("{:<20}[", message) ;
	for (std::size_t i = 0 ; i < sp.size() ; ++i) {
		print(" {}{}", sp[i],(i == (sp.size() -1)? "" : ",")) ;
		if (i == max) {
			print(" ...") ;
			break ;
		}
	}
	println(" ]") ;
}
void StaticExtent() {
	int a[]{1,2,3,4,5} ;
	std::array arr{1,2,3,4,5} ;
	std::vector vec{1,2,3,4,5} ;

	std::span s1{a} ;
	std::span s2{arr} ;
	std::span<int,5> s3{vec} ;
	std::span<int, 3> s4{vec.data(), 3} ;

	//s1 = s2 ;
	//s1 = s4 ;
	a[0] = 100 ;
	s1[0] = 100 ;
	println("{}", s1[0]) ;

	std::span<const int, 5> s5{a} ;
	//s5[0] = 100 ;
}
void DynamicExtent() {
	int a[]{1,2,3,4,5} ;
	std::array arr{1,2,3,4,5} ;
	std::vector vec{1,2,3,4,5} ;

	std::span<int> s1{} ;
	std::span<int> s2{a} ;
	std::span<int> s3{a, 3} ;
	std::span<int> s4{arr} ;

	std::span s5{std::data(a),3} ;
	std::span s6{std::data(a)+2,3} ;

	std::span s7{std::data(arr),3} ;
	std::span s8{std::data(arr)+2,3} ;

	std::span s9{std::data(vec),3} ;
	std::span s10{std::data(vec)+2,3} ;


	s1 = s2 ;
	s3 = s4 ;
}
void PrettyPrinting() {
	int a[]{1,2,3,4,5} ;
	std::array arr{1,2,3,4,5} ;
	std::vector vec{1,2,3,4,5} ;

	{
		println("Static") ;

		std::span s1{a} ;
		std::span s2{arr} ;
		std::span<int,5> s3{vec} ;
		std::span<int, 3> s4{vec.data(), 3} ;

		PrintSpan(s1) ;
		PrintSpan(s2) ;
		PrintSpan(s3) ;
		PrintSpan(s4) ;
	}

	{
		println("Dynamic") ;
		std::span<int> s1{} ;
		std::span<int> s2{a} ;
		std::span<int> s3{a, 3} ;
		std::span<int> s4{arr} ;

		PrintSpan(s1) ;
		PrintSpan(s2) ;
		PrintSpan(s3) ;
		PrintSpan(s4) ;
	}
	std::vector<std::string> langs{"C++", "C", "Java", "C#", "Python", "Ruby", "Php"} ;
	std::span s_langs{langs} ;
	langs.push_back("Perl") ;
	PrintSpan(s_langs,"", 5) ;
}

void Subspans() {
	std::vector<int> v(10) ;
	std::iota(v.begin(), v.end(), 1) ;
	std::span s1{v} ;
	PrintSpan(s1, "Original") ;

	auto s1_d = s1.first(3) ;
	PrintSpan(s1_d, "D: first 3") ;
	PrintSpan(s1.last(3), "D: last 3") ;

	PrintSpan(s1.first<3>(), "F: first 3") ;
	PrintSpan(s1.last<3>(), "F: last 3") ;

	PrintSpan(s1.subspan(3), "D: From index 3") ;
	PrintSpan(s1.subspan(3,4), "D: 4 from index 3") ;
	PrintSpan(s1.subspan<3,4>(), "F: 4 from index 3") ;
}
int main() {
	//StaticExtent() ;
	//PrettyPrinting() ;
	Subspans() ;
}
