#include <compare>
#include <iostream>
#include <format>

class Number {
	int m_Number{};
public:
	constexpr  Number(int number) :m_Number{ number } {

	}
	constexpr int GetNumber()const {
		return m_Number;
	}
	constexpr void SetNumber(int number) {
		m_Number = number;
	}
	std::strong_ordering operator <=>(const Number& rhs)const {
		return m_Number <=> rhs.m_Number ;
	}
};
int main() {
	/*int x{10}, y{1} ;
	auto ordering = x <=> y ;
	std::cout << typeid(ordering).name() << '\n' ;
	if(ordering == std::strong_ordering::less) {
		std::cout << "x < y\n" ;
	}
	if(ordering == std::strong_ordering::greater) {
		std::cout << "x > y\n" ;
	}
	if(ordering == std::strong_ordering::equal) {
		std::cout << "x == y\n" ;
	}
	if(ordering == std::strong_ordering::equivalent) {
		std::cout << "x == y\n" ;
	}
	
	if(ordering == 0) {
		std::cout << "x == y\n" ;
	}
	if(ordering > 0) {
		std::cout << "x > y\n" ;
	}
	if(ordering < 0) {
		std::cout << "x < y\n" ;
	}*/

	Number a{1}, b{2} ;
	auto ordering = a <=> b ;
	std::cout << typeid(ordering).name() << '\n' ;
}