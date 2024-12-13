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


int main() {
	std::vector<int> data(20);
	std::ranges::generate(data, []() {
		return std::random_device{}() % 100;
		});
	Console::PrintF(data, "vector");

	auto odd = std::views::filter(data, [](int x) {
		return x % 2 != 0;
	}) ;
	Console::PrintF(odd, "odd");

	auto below_50 = std::views::filter(odd, [](int x) {
		return x < 50 ;
	}) ;
	Console::PrintF(below_50, "below_50");

	auto multiplied = std::views::transform(below_50, [](int x) {
		return x *= 2 ;
	}) ;
	Console::PrintF(multiplied, "multiplied");

	auto reverse = std::views::reverse(multiplied) ;
	Console::PrintF(reverse, "reverse");



	//auto reverse = std::views::reverse(
	//	std::views::transform(
	//		std::views::filter(
	//			std::views::filter(data, [](int x) {
	//				return x % 2 != 0;
	//				}), [](int x) {
	//					return x < 50;
	//					}), [](int x) {
	//						return x *= 2;
	//						}));


	auto view = data
	| std::views::filter([](int x) {return x % 2 != 0;})
	| std::views::filter([](int x) {return x < 50;})
	| std::views::transform([](int x) {return x *= 2;})
	| std::views::reverse ;
	Console::PrintF(view, "reverse");
}