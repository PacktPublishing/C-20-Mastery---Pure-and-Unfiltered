#include <compare>
#include <iostream>

class String {
	std::string m_Str{} ;
public:
	String(const char *pstr=""):m_Str{pstr}{}
	std::weak_ordering operator <=> (const String &rhs)const {
		auto cmp = Compare(rhs) ;
		if(cmp < 0) {
			return std::weak_ordering::less ;
		}
		if(cmp > 0) {
			return std::weak_ordering::greater ;
		}
		return std::weak_ordering::equivalent ;
	}

	bool operator == (const String &rhs)const {
		return m_Str.size() == rhs.m_Str.size() && Compare(rhs) == 0 ;
	}
	int Compare(const String &rhs)const {
		auto size =std::min(m_Str.size(), rhs.m_Str.size()) ;
		int cmp{} ;
		for(size_t i = 0 ; i < size ; ++i) {
			auto lhs_char = std::tolower(m_Str[i]) ;
			auto rhs_char = std::tolower(rhs.m_Str[i]) ;
			if(lhs_char != rhs_char) {
				cmp = lhs_char < rhs_char ? -1 : +1 ;
				break ;
			}
		}
		if(cmp != 0) {
			return cmp ;
		}
		if(m_Str.size() < rhs.m_Str.size()) {
			return -1 ;
		}
		if(m_Str.size() > rhs.m_Str.size()) {
			return 1 ;
		}
		return 0 ;
	}
};

int main() {
	/*using namespace std::string_literals ;
	auto s1 = "Hello"s ;
	auto s2 = "Hello"s ;
	auto ordering = s1 <=> s2 ;
	std::cout << typeid(ordering).name() << '\n' ;*/

	String s1 = "hello" ;
	String s2 = "he" ;
	if(s1 == s2) {
		std::cout << "Equal\n" ;
	}
	if(s1 != s2) {
		std::cout << "Not Equal\n" ;
	}
	if(s1 <= s2) {
		std::cout << "Less or Equal\n" ;
	}
	if(s1 >= s2) {
		std::cout << "Greater or Equal\n" ;
	}
	if(s1 < s2) {
		std::cout << "Less\n" ;
	}
	if(s1 > s2) {
		std::cout << "Greater\n" ;
	}
}