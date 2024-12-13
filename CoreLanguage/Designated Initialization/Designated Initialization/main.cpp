#include <iostream>

struct A {
	int a ;
	int b ;
};
struct B : A {
	int x ;
	int y ;
};
A Foo(A a) {
	return {3,5} ;
}
union Data {
	int x ;
	char y ;
	double z ;
};
void Basics() {
	Data d1{} ;
	Data d2{.x = 10} ;
	Data d3{.y = 'a'} ;
	Data d4{.z = 5.2} ;

	Data d5{.x=10, .y='a'} ;
	
	B a{.x=1, .y=2} ;
	std::cout << a.a << ":" << a.b << '\n' ;
	std::cout << a.x << ":" << a.y << '\n' ;
	Foo({5,6}) ;

	//A obj{.b{2}} ;
	//std::cout << obj.a << ':' << obj.b << '\n' ;
}

struct Department {
	std::string name ;
	std::string manager ;
};

struct Employee {
	std::string name ;
	int id ;
	Department dept{.name = "unallocated"} ;
};
int main() {
	Employee e1{} ;
	Employee e2{.name="Umar"} ;
	Employee e3{.name="Umar", .id=100} ;

	Employee e4{.name="Umar", .dept="Accounts"} ;
	Employee e5{.name="Umar", .dept={.name="HR", .manager="Ayaan"}} ;

	Employee e10{.name="Umar", 5} ;	//Cannot mix DI with non-DI
	Employee e20{.id=100, .name="Umar"} ;//Cannot change the order of DI
	Employee e30{.id=100, .id=200} ; //Duplicated DI
	Employee e40{.id=100, .dept.name="Accounts"} ; //Chained DI not allowed
}