#include <iostream>
#include <map>
#include <set>

int main() {
	std::set<int> s{6,1,8,9} ;
	
	/*if (auto it = s.find(8) ; it != s.end()) {
		std::cout << "Found\n" ;
	}else {
		std::cout << "Not found\n" ;
	}*/

	if (auto found = s.contains(8) ; found) {
		std::cout << "Found\n" ;
	}else {
		std::cout << "Not found\n" ;
	}

	std::map<int, std::string>  emps{
		{100, "Umar"},
		{105, "Raihaan"},
		{303, "Sam"}
	} ;
	
	if (auto exists = emps.contains(106) ;exists) {
		std::cout << "Found\n" ;
	}else {
		std::cout << "Not found\n" ;
	}
}
