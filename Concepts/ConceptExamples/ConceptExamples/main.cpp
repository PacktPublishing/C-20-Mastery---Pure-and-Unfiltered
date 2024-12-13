#include <iostream>
#include <type_traits>
#include <xstring>

template<typename T>
concept Pointer = std::is_pointer_v<T> ;

template<typename T>
concept x86Pointer = Pointer<T> && sizeof(T) == 4;

template<typename T>
requires x86Pointer<T>
void Apply(T ptr) {
	
}

template<typename T>
concept Integral = std::is_integral_v<T> ;

template<typename T>
concept FloatingPoint = std::is_floating_point_v<T> ;

template<typename T>
//concept Arithmetic = Integral<T> || FloatingPoint<T> ;
concept Arithmetic = std::integral<T> || std::floating_point<T> ;
template<Arithmetic T>
//requires Integral<T> || FloatingPoint<T>
auto Sum(T a, T b) {
	return a + b ;
}

template<typename T, typename Callable>
requires std::invocable<Callable>
void PrettyPrint(T arg, Callable callable) {
	callable() ;
	std::cout << arg << '\n' ;
	callable() ;
}

template<typename Callable, typename...Args>
requires std::predicate<Callable, Args>
bool AllOf(Callable callable, Args...args) {
	return (callable(args) && ...) ;
}

bool Even(int x) {
	return x % 2 == 0 ;
}

std::string Odd(int x) {
	return x % 2 == 0? "True":"False" ;
}
template<typename InputIterator, typename Callable>
concept InputIterable = 
	std::predicate<Callable, typename InputIterator::value_type> &&
	std::input_iterator<InputIterator> ;

template<typename InputIterator,typename Callable>
requires InputIterable
InputIterator FindIf(InputIterator beg, InputIterator end, Callable callable) {
	while(beg != end) {
		if(callable(*beg)) {
			break ;
		}
		++beg; 
	}
	return beg ;
}
int main() {
	using namespace std::string_literals ;
	//int x{} ;
	//Apply(&x) ;
	//Sum(3, 9) ;
	//Sum(3.6, 9.3) ;
	//Sum("a"s, "b"s) ;

	/*PrettyPrint(100, [](){std::cout << "---------\n";}) ;
	PrettyPrint(200, 100) ;*/

	std::cout << std::boolalpha ;
	std::cout << AllOf(Odd,41,6,8) << '\n';
	
}