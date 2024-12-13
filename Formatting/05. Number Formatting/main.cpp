#include "../print.h"
#include <numbers>
int main() {
	println("{0:},{0:-},{0:+},{0: }",1) ;
	println("{0:},{0:-},{0:+},{0: }",-1) ;

	println("{:#020d}", 12) ;
	println("{:#0{}d}", 12,16) ;
	println("{:#020b}", 12) ;
	println("{:#020x}", 12) ;
	println("{:#020o}", 12) ;

	println("{:.2f}", std::numbers::pi) ;
	println("{:*^10.2f}", std::numbers::pi) ;

	println("{:.5}", "Hello world") ;
}