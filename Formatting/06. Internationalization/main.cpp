#include "../print.h"

int main() {
	std::locale::global(std::locale("en_US.UTF-8")) ;
	println("{}", std::locale().name()) ;
	println("{:L}", 1'000'000) ;
	std::cout << std::format(std::locale("en_IN.UTF-8"), "{:L}\n", 1'000'000) ;
}