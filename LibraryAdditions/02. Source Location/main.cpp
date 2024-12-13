#include <filesystem>
#include <source_location>
#include "../print.h"
void Log(std::source_location sl = std::source_location::current()) {
	println("#####################") ;
	println("File : {}", std::filesystem::path{ sl.file_name()}.filename().string()) ;
	println("Function : {}", sl.function_name()) ;
	println("Line/Column : {}/{}", sl.line(), sl.column()) ;
}

void Foo() {
	Log() ;
}
class Test {
public:
	Test() {
		Log() ;
	}
	Test(int x) {
		Log() ;
	}
	static void SFunction() {
		Log() ;
	}
};

int main() {
	//std::source_location sl{std::source_location::current()} ;
	Log() ;
	Test t1{} ;
	Test t2{0} ;

	Test::SFunction() ;

	auto sq = [](int x) {
		Log() ;
		return x * x ; 
	} ;
	sq(9) ;
}
