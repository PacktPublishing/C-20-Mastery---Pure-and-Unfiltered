#include <algorithm>
#include <random>
#include <vector>
#include <iostream>
#include <format>
template<typename Container>
void Print(Container &&container, std::string_view message = "", char separator=' ') {
	std::cout << std::format("{:<12}: [", message) ;
	for(const auto &element : container) {
		std::cout << std::format("{:>3}{}", element, separator) ;
	}
	std::cout << "]\n" ;
}

int main() {
	std::vector<int> data(10) ;
	std::generate(data.begin(), data.end(), []() {
		return std::random_device{}() % 10 ;
	}) ;
	Print(data, "Vector") ;
	std::for_each(data.begin(), data.end(), [](int &element) {
		if(element % 2 != 0) {
			element *= 2 ;
		}
	}) ;
	Print(data, "Doubled") ;

	if(auto pos = std::find(data.begin(), data.end(), 8); pos != data.end()) {
		std::cout << "Found :" << *pos << '\n' ;
	}else {
		std::cout << "Not found!\n" ;
	}

	if(auto pos = std::find_if(data.begin(), data.end(), [](int element) {
		return element >= 5 && element <= 10 ;
	}); pos != data.end()) {
		std::cout << "Between 5 & 10 :" << *pos << '\n' ;
	}else {
		std::cout << "Not found!\n" ;
	}

	std::cout << "\nBetween 5 & 10 : " ;
	std::for_each(data.begin(), data.end(), [](int element) {
		if(element >= 5 && element <= 10) {
			std::cout << element << ' ' ;
		}
	}) ;
	std::cout << "\nFirst 5 elements: " ;
	auto itr = data.begin() ;
	std::advance(itr, 5) ;
	std::for_each(data.begin(),itr, [](int element) {
		std::cout << element << ' ' ;
	}) ;

	std::cout << "\nLast 5 elements : " ;
	itr = data.begin() ;
	std::advance(itr, 5) ;
	std::for_each(itr, data.end(), [](int element) {
		std::cout << element << ' ' ;
	}) ;

	std::sort(data.begin(), data.end()) ;
	Print(data, "\nSorted") ;
}
