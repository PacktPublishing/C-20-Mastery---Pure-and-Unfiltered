#include <string>
#include <filesystem>
#include <iostream>

void Foo(const char *p) {
	std::cout<< p ;
}
void Foo(const char8_t *p) {
	
}
int main() {
	char ch = u8'a' ;
	const char8_t *p = u8"Hello" ;
	std::u8string str{u8"World"} ;

	Foo("Narrow string") ;
	Foo((const char *)u8"utf-8") ;

	std::filesystem::path pcurrent{u8"./"} ;
	auto pt = pcurrent.u8string() ;
	
}
