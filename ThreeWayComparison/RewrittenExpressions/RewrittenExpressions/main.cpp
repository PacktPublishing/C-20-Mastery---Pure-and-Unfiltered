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
	std::cout << "x < y  ? " << (x < y) << ' ' << (x <=> y < 0) << ' ' << (0 < y <=> x) << '\n';
	std::cout << "x > y  ? " << (x > y) << ' ' << (x <=> y > 0) << ' ' << (0 < y <=> x) << '\n' ;
	std::cout << "x <= y ? " << (x <= y) <<' ' << (x <=> y <= 0)<< ' ' << (0 <= y <=> x)<< '\n' ;
	std::cout << "x >= y ? " << (x >= y) <<' ' << (x <=> y >= 0)<< ' ' << (0 >= y <=> x)<< '\n' ;
	//////////////////////////////////////////////

	//Equality Operators
	std::cout << "x == y ? " << (x == y) << ' ' << (y == x) << '\n';
	std::cout << "x != y ? " << (x != y) << ' ' << !(y == x) <<'\n';
	//////////////////////////////////////////////
}