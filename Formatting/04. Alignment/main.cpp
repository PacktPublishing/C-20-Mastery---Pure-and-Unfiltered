#include "../print.h"
#include <vector>
struct Employee {
	int id;
	std::string name;
	std::string language;
};

void PrintTable() {
	std::vector<Employee> emps{
		{100, "Bjarne", "C++"},
		{200, "James", "Java"},
		{50, "Anders", "C#"},
		{250, "Dennis", "C"}
	} ;
	for (const auto & emp : emps) {
		println("{1:>5}{0:5c}{2:<10}{0:5c}{3:-^15}",' ', emp.id, emp.name, emp.language) ;
	}
}
int main() {
	PrintTable() ;
	println("{:3}",1) ;
	println("{:3}",12) ;
	println("{:3}",123) ;

	println("{0:20} {0}", "Hello world") ;

	/*println("{:>3}",1) ;
	println("{:>3}",12) ;
	println("{:>3}",123) ;*/

	println("{:*<3}",1) ;
	println("{:*<3}",12) ;
	println("{:*<3}",123) ;
	println("{0:*>20} {0}", "Hello world") ;

	println("{0:=^20}", "Hello world") ;

}