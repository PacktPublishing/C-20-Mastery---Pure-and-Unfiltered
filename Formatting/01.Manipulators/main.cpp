#include <iostream>
#include <bitset>
#include <iomanip>

void F() {
	
}
void B()noexcept {
	
}

int main() {
	std::cout << std::boolalpha ;
	std::cout << "noexcept?" << noexcept(F()) << std::endl;
	std::cout << std::noboolalpha ;
	std::cout << "noexcept?" << noexcept(B()) << std::endl;
	auto value = 128u ;
	std::cout << "Default :" << value << std::endl ;
	std::cout << "Octal   :" << std::oct << value << std::endl ;
	std::cout << "Hex     :" << std::hex << value << std::endl ;
	std::cout << "Binary  :" << std::bitset<8>{ value }<< std::endl ;

	std::cout << std::showbase ;
	std::cout << std::setfill('*') ;
	std::cout << std::setw(10) << std::left << "Default" << ":" << std::setw(10) << std::right	<< std::dec << value << '\n' ;
	std::cout << std::setw(10) << std::left << "Octal" << ":" << std::setw(10)	 << std::right	<< std::oct << value << '\n' ;
	std::cout << std::setw(10) << std::left << "Hex" << ":" << std::setw(10)	 << std::right	<< std::hex << value << '\n' ;
	std::cout << std::setw(10) << std::left << "Binary" << ":" << std::setw(10)	 << std::right	<< std::bitset<8>{ value } << '\n' ;
}