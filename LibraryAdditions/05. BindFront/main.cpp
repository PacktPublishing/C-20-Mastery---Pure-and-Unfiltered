#include <functional>
#include <vector>
#include "../print.h"


class Handler {
public:
	void OnUpdate(int id) {
		println("Update received!") ;
	}
};

int main() {
	std::vector v{2,2,7,9,4} ;
	/*auto it = std::ranges::find_if(v, [](int x) {
		return 2 != x ;
	}) ;*/
	//auto it = std::ranges::find_if(v, 
		//std::bind( std::not_equal_to<int>{}, 2, std::placeholders::_1)) ;
	auto it = std::ranges::find_if(v,
		std::bind_front(std::not_equal_to<int>{}, 2)) ;
	if (it != v.end()) {
		println("Found {}", *it) ;
	}
	Handler handler{} ;
	auto u_handler = std::bind_front(&Handler::OnUpdate, handler) ;
	u_handler(100) ;
	auto u_handler2 = std::bind_front(&Handler::OnUpdate, handler, 100) ;
	u_handler2() ;

}
