
#include <format>
#include <iostream>
template<typename...Args>
void print(std::format_string<Args...> fmt,Args&&...args) {
	std::cout << std::format(fmt, std::forward<Args>(args)...) ;
}

template<typename...Args>
void println(std::format_string<Args...> fmt,Args&&...args) {
	print(fmt, std::forward<Args>(args)...) ;
	std::cout << '\n';
}

