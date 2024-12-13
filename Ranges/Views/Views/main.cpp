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

	std::ranges::take_view/*<std::ranges::ref_view<std::vector<int>>>*/ a1{data, 3} ;
	Console::PrintF(a1, "take_view") ;

	std::ranges::drop_view/*<std::ranges::ref_view<std::vector<int>>>*/ a2{data, 3} ;
	Console::PrintF(a2, "drop_view") ;

	using Pair = std::pair<int, std::string> ;
	using VectorPair = std::vector<Pair> ;

	VectorPair numbers{
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"}
	};
	std::ranges::keys_view<std::views::all_t<VectorPair&>> k_view{numbers} ;
	Console::PrintF(k_view, "Keys") ;

	std::ranges::values_view<std::views::all_t<VectorPair&>> v_view{numbers} ;
	Console::PrintF(v_view, "Values") ;

	std::ranges::elements_view<std::views::all_t<VectorPair&>, 1> values{numbers} ;
	Console::PrintF(values, "elements_view") ;

}