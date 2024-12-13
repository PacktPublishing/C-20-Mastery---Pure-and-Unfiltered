#include <string>
#include <vector>
#include <algorithm>
#include <format>
#include <iostream>
#include <random>
#include <ranges>
#include <sstream>

struct Console {
	enum class Separator { NONE, SPACE, NEWLINE, TAB, DASH, DOT, PLUS };
	static std::string_view GetSeparator(Separator separator) {
		std::string_view sv{};
		switch (separator) {
			using enum Separator;
		case NONE:
			sv = "";
			break;
		case SPACE:
			sv = " ";
			break;
		case NEWLINE:
			sv = "\n";
			break;
		case TAB:
			sv = "\t";
			break;
		case DASH:
			sv = "-";
			break;
		case DOT:
			sv = ".";
			break;
		case PLUS:
			sv = "+";
			break;
		}
		return sv;
	}
	template<typename Container>
	static void PrintF(Container&& container, std::string_view message = "", Separator separator = Separator::SPACE) {
		std::cout << std::format("{:<12}: [", message);
		for (const auto& element : container) {

			std::cout << std::format("{:>3}{}", element, GetSeparator(separator));
		}
		std::cout << "]\n";
	}
	template<typename Container>
	static void Print(Container&& container, std::string_view message = "", Separator separator = Separator::SPACE) {
		if (!message.empty()) {
			std::cout << std::format("======= {} =======\n", message);
		}
		for (const auto& element : container) {
			std::cout << element << GetSeparator(separator);
		}
		std::cout << '\n';
	}
};

void UsingAlgorithms() {
	std::vector<int> data(20);
	std::ranges::generate(data, []() {
		return std::random_device{}() % 100;
	});
	Console::PrintF(data, "vector");

	std::vector<int> intermediate{data.begin(), data.begin()+5} ;
	Console::PrintF(intermediate, "take 5");

	std::vector<int> odd{} ;
	std::copy_if(intermediate.begin(), intermediate.end(), std::back_inserter(odd), [](int x) {
		return x % 2 != 0 ;
	}) ;
	Console::PrintF(odd, "odd");
}
int main() {
	std::vector<int> data(20);
	std::ranges::generate(data, []() {
		return std::random_device{}() % 100;
	});
	Console::PrintF(data, "vector");

	//auto take_5 = std::views::take(data, 5) ;
	//Console::PrintF(take_5, "take_5");

	//auto odd = std::views::filter(take_5, [](int x){return x % 2 != 0;}) ;
	//Console::PrintF(odd, "odd");


	auto odd = std::views::filter(
		std::views::take(data, 5), 
		[](int x) {
 			return x % 2 != 0;
		}) ;

	for(auto element : odd) {
		std::cout << element << ' ' ;
	}



}