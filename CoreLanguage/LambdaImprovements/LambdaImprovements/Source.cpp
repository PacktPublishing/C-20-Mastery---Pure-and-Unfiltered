#include <iostream>
#include <list>
#include <string>
#include <vector>

class Person {
	std::string m_Name{} ;
public:
	Person(std::string name)
		: m_Name{std::move(name)} {
	}
	auto GetPrintOperation(int id) {
		return [=]() {
			std::cout << id << ':' << m_Name << '\n' ;
		};
	}
};

auto GetOperation(const char *pName) {
	Person person{pName} ;
	return person.GetPrintOperation(100) ;
}
void ImplicitThisCapture() {
	auto op = GetOperation("Umar Lone") ;
	op() ;
}

int main() {
	using namespace std::string_literals ;
	auto m1 = [](int x,int y){return x >y ? x : y;} ;
	std::cout << m1(3,5) << '\n' ;

	auto m2 = [](auto x, auto y){return x > y ? x : y;} ;
	std::cout << m2(3.2f, 8) << '\n' ;
	std::cout << m2("Hello"s, "World"s) << '\n' ;

	//auto m3 = [](auto x, decltype(x)y){return x > y ? x : y;} ;
	auto m3 = []<typename T>(T x, T y){return x > y ? x : y;} ;
	//std::cout << m3(8, 3.2f) << '\n' ;

	auto printArray = []<typename T, size_t size>(T (&x)[size]) {
		std::cout << typeid(x).name() << '\n' ;
		std::cout << "Size:" << size<< '\n' ;
	} ;
	int arr[]{1,2,3} ;
	printArray(arr) ;

	auto useVec = []<typename T>(const std::vector<T> &vec) {
		std::cout << vec.size() << '\n' ;
		/*using Container = std::decay_t<decltype(vec)> ;
		using Type = typename Container::value_type ;
		Type var{} ;*/
		T var{} ;
	};
	std::vector v{1,2,3} ;
	useVec(v) ;

	[](auto&&...args) {
		return Foo(std::forward<decltype(args)>(args)...) ;
	};
	[]<typename...Args>(Args&&...args){
		return Foo(std::forward<Args>(args)...) ;
	};

	
}

template<typename Callable, typename...Args>
auto InvokeWrapper(Callable c, Args...args) {
	return [c=std::move(c),args=std::move( args...)] {
		return std::invoke(c,args...) ;
	};
}