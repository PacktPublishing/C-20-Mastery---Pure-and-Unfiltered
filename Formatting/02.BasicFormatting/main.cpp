#include <format>
#include <iostream>

int main() {
	std::string fmt = std::format("{} {}\n",1,2) ;
	std::cout << fmt ;
	std::cout << std::format("{1} {0}\n", 1,2);
	std::cout << std::format("{0} + {0} = {1}\n", 1,2);

	std::string text = "Hello world" ;
	std::cout << std::format("{{ {} }} is empty?{}", text, text.empty()) ;
}
