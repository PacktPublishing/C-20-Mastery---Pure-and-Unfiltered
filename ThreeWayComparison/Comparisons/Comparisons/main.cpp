#include <utility>
#include <compare>
class Number {
	int m_Number{} ;
public:
	constexpr Number()=default ;
	constexpr Number(int number):m_Number{number} {
		
	}
	constexpr int GetNumber()const {
		return m_Number ;
	}
	constexpr void SetNumber(int number) {
		m_Number = number ;
	}
	auto operator <=>(const Number &rhs)const = default ;
	/*friend constexpr bool operator ==(const Number &lhs, const Number &rhs)noexcept {
		return lhs.m_Number == rhs.m_Number ;
	}
	
	friend constexpr bool operator <(const Number &lhs, const Number &rhs)noexcept {
		return lhs.m_Number < rhs.m_Number ;
	}
	friend constexpr bool operator !=(const Number &lhs, const Number &rhs)noexcept {
		return !(lhs == rhs) ;
	}
	friend constexpr bool operator >(const Number &lhs, const Number &rhs)noexcept {
		return !(lhs < rhs) ;
	}
	friend constexpr bool operator <=(const Number &lhs, const Number &rhs)noexcept {
		return !(rhs < lhs) ;
	}
	friend constexpr bool operator >=(const Number &lhs, const Number &rhs)noexcept {
		return !(lhs < rhs) ;
	}*/

};

int main() {
	//using namespace std::rel_ops ;
	constexpr Number x{5}, y{6} ;
	bool result{} ;
	result = x < y ;
	result = x <= y ;
	result = x >= y ;
	result = x > y ;
	result = x == y ;
	result = x != y ;

	result = x < 3 ;
	result = 3 < x ;

	constexpr auto res = x < y ;
	constexpr auto eq = x == y ;
	constexpr auto gt = x > y ;
	static_assert(noexcept(x.operator<=>(x)) == true) ;
}