#include <iostream>
#include <string_view>
#include <format>
#include <random>
#include <vector>
#include <ranges>

struct Console {
	enum class Separator { NONE, SPACE, NEWLINE, TAB };
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
		}
		return sv ;
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
		if(!message.empty()) {
			std::cout << std::format("======= {} =======\n", message);
		}
		for (const auto& element : container) {
			std::cout << element << GetSeparator(separator);
		}
		std::cout << '\n';
	}
};

int main() {
	std::vector<int> data(10);
	std::ranges::generate(data, []() {
		return std::random_device{}() % 100;
	});
	Console::PrintF(data, "vector");

	auto a1 = std::ranges::views::take(data, 3) ;
	Console::PrintF(a1, "take_view") ;

	auto a2 = std::views::drop(data,3) ;
	Console::PrintF(a2, "drop_view") ;

	using Pair = std::pair<int, std::string> ;
	using VectorPair = std::vector<Pair> ;

	VectorPair numbers{
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"}
	};
	auto k_view = std::views::keys(numbers) ;
	Console::PrintF(k_view, "Keys") ;

	auto v_view = std::views::values(numbers) ;
	Console::PrintF(v_view, "Values") ;

	auto values = std::views::elements<1>(numbers) ;
	Console::PrintF(values, "elements_view") ;

}