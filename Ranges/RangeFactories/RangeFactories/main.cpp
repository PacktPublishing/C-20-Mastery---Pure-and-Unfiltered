#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <format>
#include <ranges>
#include <sstream>
#include <fstream>
template<std::ranges::range Range>
void Print(Range && range, std::string_view message = "", char separator=' ') {
	std::cout << std::format("{:<12} : [ ", message);
	for(const auto &e : range) {
		std::cout << e << separator ;
	}
	std::cout << " ]\n" ;
}
int main() {
	std::vector<int> data(10) ;
	std::ranges::generate(data, []() {
		return std::random_device{}() % 100 ;
	});
	Print(data, "vector") ;

	auto e = std::views::empty<int> ;
	Print(e, "empty range") ;

	Print(std::views::single(50), "single") ;

	Print(std::views::iota(1, 10), "iota") ;
	Print(std::views::iota(1) | std::views::take(5), "iota") ;

	using namespace std::string_literals ;
	auto str = "This is a string"s ;
	std::istringstream istream{str} ;
	auto stream = std::views::istream<std::string>(istream) ;
	Print(stream, "istream") ;

	std::ifstream input_stream{"data.txt"} ;
	if(!input_stream) {
		std::cout << "Could not open file\n" ;
		return 0;
	}
	stream = std::views::istream<std::string>(input_stream) ;
	Print(stream, "file input stream") ;
}