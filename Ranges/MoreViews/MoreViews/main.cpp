#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>
#include <format>
#include <random>
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

namespace Join {
	void Without() {
		std::vector<std::string> words{ "C++ ", "is ", "a ", "general ", "purpose ", "programming ", "language" };
		Console::Print(words, "Words", Console::Separator::NONE);

		std::string line{};
		std::for_each(words.begin(), words.end(), [&line](const auto& word) {
			std::for_each(word.begin(), word.end(), [&line](char ch) {
				line.push_back(ch);
			});
		});
		Console::Print(line, "Flattened", Console::Separator::NONE);
	}
	void With() {
		//std::vector<std::string> words{ "C++ ", "is ", "a ", "general ", "purpose ", "programming ", "language" };
		std::vector<std::string> words{ "C++", "is", "a", "general", "purpose", "programming", "language" };
		Console::Print(words, "Words", Console::Separator::NONE);
		//auto flattened = std::views::join(words) ;
		//join_with is provided in C++23
		auto flattened = std::views::join_with(words, ' ') ;
		Console::Print(flattened, "Flattened", Console::Separator::NONE) ;
	}

}

namespace Split {
	void Without() {
		std::string line = "C++ is a general purpose programming language";
		std::vector<std::string> words{};
		std::istringstream str_input{ line };
		std::string word{};
		while (str_input >> word) {
			words.emplace_back(word);
		}
		Console::Print(words, "Split", Console::Separator::DOT);
	}
	void With() {
		using namespace std::string_view_literals ;
		std::string line = "C++ is a general purpose programming language";
		auto split = std::views::split(line, " "sv) ;
		std::vector<std::string> words{} ;
		for(const auto &inner_range : split) {
			std::string word{} ;
			for(auto ch : inner_range) {
				std::cout << ch ;
				word.push_back(ch) ;
			}
			words.push_back(word) ;
			std::cout << '\n' ;
		}
		//std::ranges_to is part of C++23
		auto vec = std::ranges::to<std::vector<std::string>>(split) ;
		Console::Print(vec, "vector<std::string>", Console::Separator::NEWLINE) ;
	}
}

namespace Filter {
	void Without() {
		std::vector<int> data(10);
		std::ranges::generate(data, []() {
			return std::random_device{}() % 100;
		});
		Console::PrintF(data, "vector");
		std::vector<int> filtered{} ;
		std::ranges::copy_if(data, std::back_inserter(filtered), [](int x) {
			return !(x>=40 && x<=60) ;
		});
		Console::PrintF(filtered, "Filtered") ;
	}
	void With() {
		std::vector<int> data(10);
		std::ranges::generate(data, []() {
			return std::random_device{}() % 100;
		});
		Console::PrintF(data, "vector");
		auto filtered = std::views::filter(data, [](int x) {
			return !(x >= 40 && x <= 60) ;
		}) ;
		std::ranges::for_each(filtered, [](int &x) {
			x /= 10 ;
		}) ;
		Console::PrintF(filtered, "Filtered") ;
		Console::PrintF(data, "Modified");
	}
}

namespace TakeWhile {
	void Without() {
		using namespace std::literals ;
		auto str = "C++ Language,Bjarne Stroustrup"s ;
		Console::Print(str, "String", Console::Separator::NONE);
		auto pos = str.find(',') ;
		if(pos == std::string::npos) {
			return ;
		}
		auto itr = str.begin() ;
		while(pos != 0) {
			std::cout << *itr++ ;
			--pos ;
		}

	}
	void With() {
		using namespace std::literals ;
		auto str = "C++ Language,Bjarne Stroustrup"s ;
		Console::Print(str, "String", Console::Separator::NONE);
		auto view = std::views::take_while(str, [](char ch) {
			return ch != ',' ;
		}) ;
		Console::Print(view, "String", Console::Separator::NONE);
		
	}
}

namespace DropWhile {
	void Without() {
		using namespace std::literals ;
		auto str = "    C++ Language,Bjarne Stroustrup"s ;
		Console::Print(str, "With spaces", Console::Separator::NONE);
		auto pos = std::ranges::find_if_not(str, isspace);
		std::string str2{pos, str.end()} ;
		Console::Print(str2, "Without spaces", Console::Separator::NONE);
		
	}
	void With() {
		using namespace std::literals ;
		auto str = "    C++ Language,Bjarne Stroustrup"s ;
		Console::Print(str, "With spaces", Console::Separator::NONE);
		auto view = std::views::drop_while(str, isspace) ;
		Console::Print(view, "No spaces", Console::Separator::NONE) ;
	}
}

namespace Transform {
	void Without() {
		using namespace std::literals ;
		auto str = "C++ Language,Bjarne Stroustrup"s ;
		Console::Print(str, "Default", Console::Separator::NONE);

		std::ranges::for_each(str, [](char ch) {
			std::cout << (char)toupper(ch) ;
		}) ;
	}
	void With() {
		using namespace std::literals ;
		auto str = "C++ Language,Bjarne Stroustrup"s ;
		Console::Print(str, "Default", Console::Separator::NONE);
		auto upper = std::views::transform(str, [](char ch) {
			return (char)toupper(ch) ;
		}) ;
		Console::Print(upper, "Upper case", Console::Separator::NONE) ;

	}
}

int main() {
	Transform::With() ;
}