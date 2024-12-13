#include <algorithm>
#include <deque>
#include <vector>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <array>
#include <string_view>
#include "../print.h"
template<typename Range>
void PrettyPrint(const Range& range, std::string_view message = "", std::size_t max = 10) {
	print("{:<20}[", message);
	using it_cat = typename std::iterator_traits<typename Range::iterator>::iterator_category;
	std::size_t max_size{};
	if constexpr (std::is_same_v<it_cat, std::forward_iterator_tag>) {
		max_size = std::distance(range.begin(), range.end()) - 1;
	}
	else {
		max_size = range.size() - 1;
	}
	std::size_t i{};
	for (const auto& e : range) {
		print(" {}{}", e, (i == max_size ? "" : ","));
		if (i == (max)) {
			print(", ...");
			break;
		}
		++i;
	}
	println(" ]");
}

void PreCpp20() {
	std::array arr{ 1,2,3,2,2,4,2,7,2,9 };

	std::vector<int> vec{ std::begin(arr), std::end(arr) };
	PrettyPrint(vec, "vector");
	auto r_vec = std::ranges::remove(vec, 2);
	vec.erase(r_vec.begin(), r_vec.end()) ;
	PrettyPrint(vec, "vector erased");
	
	std::list<int> t_list{ std::begin(arr), std::end(arr) };
	PrettyPrint(t_list, "list");
	t_list.remove(2) ;
	PrettyPrint(t_list, "list erased");
	
	std::forward_list<int> f_list{ std::begin(arr), std::end(arr) };
	PrettyPrint(f_list, "forward_list");

	std::deque<int> dq{ std::begin(arr), std::end(arr) };
	PrettyPrint(dq, "deque");

	std::set<int> st{ std::begin(arr), std::end(arr) };
	PrettyPrint(st, "set");
	st.erase(2) ;
	PrettyPrint(st, "set erased");
	
	std::multiset<int> ms{ std::begin(arr), std::end(arr) };
	PrettyPrint(ms, "multiset");
	ms.erase(2) ;
	PrettyPrint(ms, "multiset erased");

	std::unordered_set<int> us{ std::begin(arr), std::end(arr) };
	PrettyPrint(us, "unordered_set");
	us.erase(2) ;
	PrettyPrint(us, "unordered_set erased");

	std::unordered_multiset<int> ums{ std::begin(arr), std::end(arr) };
	PrettyPrint(ums, "unordered_multiset");
	ums.erase(2) ;
	PrettyPrint(ums, "unordered_multiset erased");
}
int main() {
	std::array arr{ 1,2,3,2,2,4,2,7,2,9 };

	std::vector<int> vec{ std::begin(arr), std::end(arr) };
	PrettyPrint(vec, "vector");
	std::erase(vec, 2) ;
	PrettyPrint(vec, "vector erased");
	
	std::list<int> t_list{ std::begin(arr), std::end(arr) };
	PrettyPrint(t_list, "list");
	std::erase(t_list, 2) ;
	PrettyPrint(t_list, "list erased");
	
	std::forward_list<int> f_list{ std::begin(arr), std::end(arr) };
	PrettyPrint(f_list, "forward_list");
	f_list.remove(2) ;
	PrettyPrint(f_list, "forward_list erased");

	std::deque<int> dq{ std::begin(arr), std::end(arr) };
	PrettyPrint(dq, "deque");
	std::erase(t_list, 2) ;
	PrettyPrint(dq, "deque erased");

	std::set<int> st{ std::begin(arr), std::end(arr) };
	PrettyPrint(st, "set");
	//st.erase(2) ;
	std::erase_if(st, [](int x) {
		return x == 2 ;
	});
	PrettyPrint(st, "set erased");
	
	std::multiset<int> ms{ std::begin(arr), std::end(arr) };
	PrettyPrint(ms, "multiset");
	//ms.erase(2) ;
	std::erase_if(ms, [](int x) {
		return x == 2 ;
	});
	PrettyPrint(ms, "multiset erased");

	std::unordered_set<int> us{ std::begin(arr), std::end(arr) };
	PrettyPrint(us, "unordered_set");
	us.erase(2) ;
	PrettyPrint(us, "unordered_set erased");

	std::unordered_multiset<int> ums{ std::begin(arr), std::end(arr) };
	PrettyPrint(ums, "unordered_multiset");
	ums.erase(2) ;
	PrettyPrint(ums, "unordered_multiset erased");


}