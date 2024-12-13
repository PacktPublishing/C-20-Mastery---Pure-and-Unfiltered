#include <utility>
#include <compare>
#include <iostream>
#include <format>

struct Type {
	size_t length{} ;
	char array[5]{};
	auto operator<=>(const Type &rhs)const=default ;
	/*bool operator==(const Type &rhs)const {
		auto lhs_length = strlen(array)	 ;
		auto rhs_length = strlen(rhs.array) ;
		if(lhs_length == rhs_length && strcmp(array, rhs.array) == 0) {
			return true ;
		}
		return false ;
	}*/
};

int main() {
	int num = 5;
	std::string s1, s2 ;
	s1 == s2 ;
	Type a{3,"C++"};
	Type b{4,"C++!"};
	std::cout << std::boolalpha ;
	std::cout << "(a == b) " << (a == b) << '\n';
	std::cout << "(a != b) " << (a != b) << '\n';
}
