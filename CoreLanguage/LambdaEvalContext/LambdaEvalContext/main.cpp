#include <memory>
#include <set>
#include <string>
int Sum(int x,int y) ;
template<typename T>
using Ptr = std::unique_ptr<T, decltype([](T *p){delete p;})> ;

struct Name {
	std::string m_Name{} ;

	Name(std::string name)
		: m_Name{std::move(name)} {
	}
};
int main() {
	//Sum(3,5) ;

	auto &type = typeid(Sum) ;
	auto isNoExcept = noexcept(Sum(0,0)) ;
	decltype(Sum) add ;

	//decltype([](){}) f ;

	auto lambda_deleter = [](auto *p) {
		delete p ;
	};
	std::unique_ptr<int,decltype(lambda_deleter)> p1{new int, lambda_deleter} ;

	std::unique_ptr<int, decltype([](auto *p){delete p;})> p2{new int} ;

	Ptr<int> pInt{new int} ;
	Ptr<float> pFloat{new float} ;

	auto name_comp = [](const auto &n1, const auto &n2) {
		return n1.m_Name < n2.m_Name ;
	};
	std::set<Name,decltype(name_comp)> names{
		{Name{"Umar"}, Name{"Ayaan"}}
	} ;

	std::set<Name,decltype([](const auto &n1, const auto &n2) {
		return n1.m_Name < n2.m_Name ;
	})> names1{
		{Name{"Umar"}, Name{"Ayaan"}}
	} ;

	using NameSet = std::set<Name,decltype([](const auto &n1, const auto &n2) {
		return n1.m_Name < n2.m_Name ;
	})>;
	NameSet nm{Name{"Umar"}, Name{"Ayaan"}} ;
}