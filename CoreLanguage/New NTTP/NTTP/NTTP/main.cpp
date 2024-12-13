#include <iostream>
template<int n>
void PrintInt() {
	std::cout << n << '\n' ;
}

template<float f>
void PrintFloat() {
	std::cout << f << '\n' ;
}
template<size_t size>
struct FixedString {
	char m_Str[size] ;
	constexpr FixedString(const char(&str)[size]) {
		std::copy(str, str+size, m_Str) ;
	}
	constexpr size_t Size()const {
		return size ;
	}
	constexpr const char * Str()const {
		return m_Str ;
	}
};

template<FixedString fs>
void Print() {
	static_assert(fs.Size() < 10) ;
	std::cout << fs.Str() << '\n' ;
}

int main() {
	PrintInt<5>() ;
	PrintFloat<3.2f>() ;
	Print<"Hello World">() ;
}