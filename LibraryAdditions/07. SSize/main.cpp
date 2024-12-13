#include <iostream>
#include <vector>

int main() {
	std::vector<int> v ;
	for (int i = 0 ; i < std::ssize(v)-1 ; ++i) {
		//std::cout << v[i] << ' ' ;
		std::cout << i<< ' ' ;
	}
}
