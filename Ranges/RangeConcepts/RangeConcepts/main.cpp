#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <deque>
#include <random>

void Output() {
	/*using Type = const std::list<int> ;
	using Type = const std::set<int> ;*/
	using Type = std::list<int> ;
	static_assert(std::ranges::output_range<Type,int>) ;
}
void Bidirectional() {
	//using Type = std::forward_list<int> ;
	using Type = std::list<int> ;
	static_assert(std::ranges::bidirectional_range<Type>) ;
}
void RandomAccess() {
	using Type = std::vector<int> ;
	static_assert(std::ranges::random_access_range<Type>) ;
}

void Contiguous() {
	using Type = std::vector<int> ;
	static_assert(std::ranges::contiguous_range<Type>) ;
}

void SizedRange() {
	//using Type = std::forward_list<int> ;
	using Type = std::list<int> ;
	static_assert(std::ranges::sized_range<Type>) ;
}

template<typename T>
requires std::ranges::random_access_range<T>
const typename T::value_type & PickRandom(const T& container) {
	auto index = std::random_device{}() % container.size() ;
	return container[index] ;
}
int main() {
	std::vector<int> data(10) ;
	std::ranges::generate(data, []() {
		return std::random_device{}() % 10 ;
	}) ;

	//std::ranges::sort(data) ;
	//std::ranges::reverse(data) ;
	PickRandom(data) ;

}