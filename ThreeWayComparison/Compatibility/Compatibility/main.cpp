#include <compare>
#include <iostream>

class Number {
	int m_Number{};
public:
	constexpr Number(int number=0) :m_Number{ number } {

	}
	constexpr int GetNumber()const {
		return m_Number;
	}
	constexpr void SetNumber(int number) {
		m_Number = number;
	}
	friend bool operator == (const Number &lhs, const Number &rhs) {
		std::cout << "operator==\n" ;
		return lhs.m_Number == rhs.m_Number ;
	}
	friend bool operator < (const Number &lhs, const Number &rhs) {
		std::cout << "operator<\n" ;
		return lhs.m_Number < rhs.m_Number ;
	}
};

class Product {
	Number m_Id{} ;
	std::string m_Name{} ;

public:
	Product(int id, const std::string& name)
		: m_Id{id},
		  m_Name{name} {
	}
	std::strong_ordering operator <=>(const Product &rhs)const = default ;
};
int main() {
	Product p1{101, "Keyboard"}, p2{102, "Mouse"} ;

	if(p1 == p2) {
		std::cout << "equal\n" ;
	}
	if(p1 != p2) {
		std::cout << "not equal\n" ;
	}
	if(p1 < p2) {
		std::cout << "less\n" ;
	}
	if(p1 > p2) {
		std::cout << "greater\n" ;
	}
	if(p1 <= p2) {
		std::cout << "less or equal\n" ;
	}
	if(p1 >= p2) {
		std::cout << "greater or equal\n" ;
	}
}

