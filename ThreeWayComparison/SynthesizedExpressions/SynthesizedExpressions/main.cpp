#include <iostream>
#include <compare>

class Number {
	int m_Number{};
public:
	constexpr Number() = default;
	constexpr Number(int number) :m_Number{ number } {

	}
	constexpr int GetNumber()const {
		return m_Number;
	}
	constexpr void SetNumber(int number) {
		m_Number = number;
	}
	auto operator <=>(const Number& rhs)const = default;


};

int main() {
	constexpr Number x{ 5 }, y{ 5 };
	std::cout << std::boolalpha;

	//Relational Operators
	std::cout << "x < 8  ? " << (x < 8)  << ' ' << (x <=> 8 < 0) <<'\n' ;
	std::cout << "8 < x  ? " << (8 < x)  << ' ' << (0 < x <=> 8) <<'\n' ;

	//Equality Operators
	std::cout << "x == 5 ? " << (x == 5) << ' ' << (x == 5) <<'\n' ;
	std::cout << "5 == x ? " << (5 == x) << ' ' << (x == 5) <<'\n' ;

	std::cout << "x != 5 ? " << (x != 5) << ' ' << !(x == 5) << '\n' ;
	std::cout << "5 != x ? " << (5 != x) << ' ' << !(x == 5)<< '\n' ;
	//////////////////////////////////////////////
}