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

	friend auto operator <=>(const Number& lhs, const Number& rhs){
		std::cout << "operator<=> " ;
		return lhs.m_Number <=> rhs.m_Number ;
	}
	friend bool operator ==(const Number &lhs, const Number &rhs){
		std::cout << "operator== " ;
		return lhs.m_Number == rhs.m_Number ;
	}
};

int main() {
	Number x{ 5 }, y{ 5 };
	std::cout << std::boolalpha;
	//Rewritten expressions
	std::cout << "x < y  ? " << (x < y) << '\n';	//(x <=> y <  0) 
	std::cout << "x > y  ? " << (x > y) << '\n';	//(x <=> y >  0) 
	std::cout << "x <= y ? " << (x <= y) << '\n';	//(x <=> y <= 0)
	std::cout << "x >= y ? " << (x >= y) << '\n';	//(x <=> y >= 0)

	std::cout << "x == y ? " << (x == y) << '\n';	// (y==x)
	std::cout << "x != y ? " << (x != y) << '\n';	//!(x == y) or !(y == x)
	std::cout << "x != 5 ? " << (x != 5) << '\n';	//!(x == 5)

	//Synthesized expressions
	std::cout << "5 == x ? " << (5 == x) << '\n';	// (x == 5)
	std::cout << "5 != x ? " << (5 != x) << '\n';	//!(x == 5)
}