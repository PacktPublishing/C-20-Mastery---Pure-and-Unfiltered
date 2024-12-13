#include <iostream>
#include <vector>
//template<typename FloatingType>
//FloatingType Divide(FloatingType a, FloatingType b) {
//	return a/b ;
//}

//template<typename FloatingType,
//	std::enable_if_t<std::is_floating_point_v<FloatingType>> * = nullptr>
//FloatingType Divide(FloatingType a, FloatingType b) {
//	return a/b ;
//}

namespace WithoutConcepts {
	template<typename FloatingType>
	FloatingType Divide(FloatingType a, FloatingType b) {
		static_assert(std::is_floating_point_v<FloatingType>, "Arguments must be floating point");
		return a / b;
	}

	class Type {
	public:
		Type() = default;
		Type(Type&&) = default;
		Type(const Type&) = delete;
	};
	template<typename T,
		std::enable_if_t<std::is_move_constructible_v<T> >* = nullptr>
		void Insert(T&& arg) {
		std::vector<T> v;
		v.emplace_back(std::forward<T>(arg));
	}
}

template<typename FloatingType>
//requires std::is_floating_point_v<FloatingType>
requires std::floating_point<FloatingType>
FloatingType Divide(FloatingType a, FloatingType b) {
	return a/b ;
}


class Type {
public:
	Type() = default;
	Type(Type&&) = delete;
	Type(const Type&) = delete;
};
template<typename T>
void Insert(T&& arg) requires std::move_constructible<T> {
	std::vector<T> v;
	v.emplace_back(std::forward<T>(arg));
}
template<std::move_constructible T>
void EmplaceBack(T&& arg)  {
	std::vector<T> v;
	v.emplace_back(std::forward<T>(arg));
}
//template<typename T>
//requires std::integral<T>
template<std::integral T>
class IntNumber {
	T m_Num{} ;
public:
	IntNumber(T num)
		: m_Num{std::move(num)} {
	}
};
auto Max(std::integral auto a, std::integral auto b) {
	std::cout << "Max abbreviated template\n" ;
	return a > b ? a : b ;
}
template<typename T1>
auto Max(T1 a, T1 b) {
	std::cout << "Max template\n" ;
	return a > b ? a : b ;
}
int main() {
	std::cout << Max(3,5l) << '\n' ;
	IntNumber<int> a{5} ;
	//IntNumber<float> b{6.f} ;
	std::cout << Divide(5.f, 2.f) << '\n' ;

	//Insert(Type{});
}