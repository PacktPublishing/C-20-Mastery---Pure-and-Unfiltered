#include <compare>
#include <iostream>
struct Type{
	int value{} ;
	char array[8]{} ;
	int *ptr{} ;
	auto operator <=>(const Type &rhs)const = default ;
} ;
struct Derived : Type {
	float num{} ;
	//auto operator <=>(const Derived &rhs)const = default ;
};

int main() {
	int num = 100 ;
	/*Type a{.value=100, .array{"C++"}, .ptr{&num}} ;
	Type b{.value=100, .array{"C++"}, .ptr{new int{200}}} ;*/
	Derived a{100, "C++", &num, 0.25f} ;
	Derived b{100, "C++", &num, 0.25f} ;

	std::cout << std::boolalpha ;

	std::cout << "(a < b)  " << (a < b)  <<'\n' ;
	std::cout << "(a > b)  " << (a > b)  <<'\n' ;
	std::cout << "(a <= b) " << (a <= b) <<'\n' ;
	std::cout << "(a >= b) " << (a >= b) <<'\n' ;

	std::cout << "(a == b) " << (a == b) <<'\n' ;
	std::cout << "(a != b) " << (a != b) <<'\n' ;
}