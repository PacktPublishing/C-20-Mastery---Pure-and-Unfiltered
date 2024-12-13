#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <syncstream>
std::mutex m{} ;
void WriteStream(int id) {
	for (int i = 0; i < 10; ++i) {
		//std::lock_guard lock{m} ;
		std::osyncstream s_out{std::cout} ;
		/*s_out << "The " << "quick " << "brown "
		<< "fox " << "jumps " << "over " << "the "
		<< "lazy " << "dog " << '\n';*/

		s_out << "[" << std::this_thread::get_id() << "]" << " Thread #"
<< id << " is currently executing iteration -> " << "{" << i << "}" << '\n' ;
	}
}
int main() {
	std::vector<std::jthread> threads{} ;
	for (int i = 0 ; i < 5 ; ++i) {
		threads.emplace_back(WriteStream, i) ;
	}
}
