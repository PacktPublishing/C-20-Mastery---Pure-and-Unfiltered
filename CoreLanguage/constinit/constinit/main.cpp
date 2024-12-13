#include <iostream>
extern int a ;
int b = a ;
int main() {
	std::cout << "a:" << a << '\n' ;
	std::cout << "b:" << b << '\n' ;
}