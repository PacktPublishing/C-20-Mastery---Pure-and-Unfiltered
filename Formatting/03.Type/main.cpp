
#include <format>
#include <iostream>

template<typename...Args>
void println(std::format_string<Args...> fmt,Args&&...args) {
	std::cout << std::format(fmt, std::forward<Args>(args)...) ;
}
int main() {
	auto value = 45 ;
	println("{0:d} {0:b} {0:o} {0:x}\n", value) ;
	println("{0:d} {0:#b} {0:#o} {0:#x} {0:#X} {0:c}\n", value) ;

	auto value_2 = 12345.123456789 ;
	println("{0:f} {0:g} {0:e} {0:a}\n", value_2) ;
	println("{0:f} {0:G} {0:E} {0:A}\n", value_2) ;

	println("{:s}\n", "Hello world") ;

	println("{:p}\n", static_cast<void*>(&value));

}