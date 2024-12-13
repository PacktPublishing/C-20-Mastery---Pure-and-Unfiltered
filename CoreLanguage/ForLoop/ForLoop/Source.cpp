#include <iostream>
#include <list>
#include <string>
#include <mutex>
#include <fcntl.h>
#include <io.h>
class Names {
	std::list<std::string> m_Names{} ;

public:
	Names(std::list<std::string> names)
		: m_Names{std::move(names)} {
		std::cout << "Names()\n" ;
	}
	~Names() {
		std::cout << "~Names()\n" ;
	}
	std::list<std::string> & Get() {
		return m_Names ;
	}
};
Names Create() {
	return Names{{"C++", "Java", "C#"}} ;
}
int main() {
	/*std::list<int> arr{1,2,3,4} ;
	for(auto &e : arr) {
		std::cout << e << '\n' ;
	}

	auto && range = arr ;
	auto beg = std::begin(range) ;
	auto end = std::end(range) ;
	for(;beg != end; ++beg) {
		auto &e = *beg;
	}*/
	//auto names = Create() ;
	
	std::cout << "## Loop starts\n" ;
	for(auto names = Create() ;auto &name:names.Get()) {
		std::cout << "## inside loop\n" ;
		std::cout << name << '\n' ;
	}
	std::cout << "## Loop ends\n" ;

	//auto && range = Create().Get() ;

	std::mutex mtx{}; 
	//std::lock_guard lck{mtx} ;
	for(std::lock_guard lck{mtx}; auto x : {1,2,3}) {
		
	}

	
}
