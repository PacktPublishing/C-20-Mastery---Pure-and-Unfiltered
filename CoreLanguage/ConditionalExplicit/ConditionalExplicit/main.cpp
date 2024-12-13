#include <iostream>
#include <optional>
#include <string>
#include <string_view>

void PrintStdString(const std::string &str) {
	std::cout << str ;
}
void PrintOptional(const std::optional<std::string> &op) {
	std::cout << op.value_or("") ;
}

template<typename T>
class String {
	T m_str{} ;
public:
	template<typename U,
		std::enable_if_t<!std::is_convertible_v<U, T>> * = nullptr>
	explicit String(const U &str):m_str{str} {
		
	}
	template<typename U,
		std::enable_if_t<std::is_convertible_v<U, T>> * = nullptr>
	String(const U &str):m_str{str} {
		
	}
	const T & Get()const {
		return m_str ;
	}
};
namespace UsingConcepts {
	template<typename T>
class String {
	T m_str{} ;
public:
	template<typename U>
		requires !std::is_convertible_v<U,T>
	explicit String(const U &str):m_str{str} {
		
	}
	template<typename U>
		requires std::is_convertible_v<U,T>
	String(const U &str):m_str{str} {
		
	}
	const T & Get()const {
		return m_str ;
	}
};
}
namespace ExplicitBool {
		template<typename T>
class String {
	T m_str{} ;
public:
	template<typename U>
	explicit(!std::is_convertible_v<U,T>) String(const U &str):m_str{str} {
		
	}
	const T & Get()const {
		return m_str ;
	}
};
}
void PrintString(const ExplicitBool::String<std::string> &str) {
	std::cout << str.Get() ;
}
int main() {
	using namespace std ;
	ExplicitBool::String<std::string> s1 = "C++" ;
	ExplicitBool::String<std::string> s2 = "C++"s ;
	ExplicitBool::String<std::string> s3 {"C++"sv} ;

	PrintString("C++") ;
	PrintString("C++"s) ;
	//PrintString("C++"sv) ;
}

void Basics() {
	using namespace std ;
	std::string s1 = "C++" ;
	std::string s2 = "C++"s ;
	//std::string s3 = "Hello"sv ;

	PrintStdString("C++") ;
	PrintStdString("C++"s) ;
	//PrintStdString("C++"sv) ;


	//std::optional<std::string> op = "C++"sv ;

	PrintOptional("C++") ;
	PrintOptional("C++"s) ;
	//PrintOptional("C++"sv) ;
	
}
