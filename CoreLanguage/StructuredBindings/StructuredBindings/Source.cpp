#include <string>

struct Point {
	int x ;
	int y ;
};

class Person {
	std::string m_Name ;
	int m_Id ;
public:
	void Foo(const Person &p) {
		auto n = p.m_Name ;
		auto [name, id] = p ;
	}
	friend void Print(const Person &p) ;
};
void Print(const Person &p) {
	auto n = p.m_Name ;
	auto [name,id] = p ;
}

int main() {
	Point p{3,5} ;
	auto [a,b] = p ;
	auto fn = [=] {
		auto a1 = a ;
	};
	//auto _p = p ;
}