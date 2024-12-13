#include <type_traits>
#include "../print.h"
const char * GetString() {
	if (std::is_constant_evaluated()) {
		return "Compile-time call" ;
	}
	return "Runtime call" ;
}
consteval const char * GetStringConstEval() {
	if (std::is_constant_evaluated()) {
		return "Compile-time call" ;
	}
	return "Runtime call" ;
}
constexpr const char * GetStringConstExpr() {
	if (std::is_constant_evaluated()) {
		return "Compile-time call" ;
	}
	return "Runtime call" ;
}
int main() {
	constexpr auto s1 = GetStringConstExpr() ;
	println("{}", s1) ;
}
