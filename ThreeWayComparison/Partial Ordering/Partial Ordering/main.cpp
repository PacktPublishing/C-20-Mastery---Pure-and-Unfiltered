#include <compare>
#include <iostream>
class Pair {
	int m_First{} ;
	int m_Second{} ;
public:
	Pair(int first, int second)
		: m_First{first},
		  m_Second{second} {
	}
	std::partial_ordering operator <=>(const Pair &rhs)const {
		if(m_First < rhs.m_First && m_Second < rhs.m_Second) {
			return std::partial_ordering::less ;
		}
		if(m_First > rhs.m_First && m_Second > rhs.m_Second) {
			return std::partial_ordering::greater ;
		}
		if(m_First == rhs.m_First && m_Second == rhs.m_Second) {
			return std::partial_ordering::equivalent ;
		}
		return std::partial_ordering::unordered ;
	}
	bool operator==(const Pair&) const = default ;

};
int main() {
	/*double a{-0.0}, b{+0.0} ;
	auto ordering = a <=> b ;
	std::cout << typeid(ordering).name() << '\n' ;

	if(ordering == std::partial_ordering::equivalent) {
		std::cout << "a equiv b\n" ;
	}
	if(ordering == std::partial_ordering::less) {
		std::cout << "a < b\n" ;
	}
	if(ordering == std::partial_ordering::greater) {
		std::cout << "a > b\n" ;
	}
	if(ordering == std::partial_ordering::unordered) {
		std::cout << "Unordered\n" ;
	}*/

	Pair p1{1,10}, p2{3,4} ;
	if(p1 < p2) {
		std::cout << "less\n" ;
	}else if(p1 > p2) {
		std::cout << "greater\n" ;
	}else 	if(p1 == p2) {
		std::cout << "equal\n" ;
	}else {
		std::cout << "unordered\n" ;
	}
}