#include <format>
#include <iostream>
#include <set>
#include <string>

struct Person {
	std::string name{} ;
	int age{} ;
	char gender{} ;

	auto operator<=>(const Person &rhs)const {
		auto age_ord = age <=> rhs.age ;
		if(age_ord != 0) {
			return age_ord ;
		}
		auto gen_ord = gender <=> rhs.gender ;
		if(gen_ord != 0) {
			return gen_ord ;
		}
		return name <=> rhs.name ;
	}
};

int main() {
	std::set<Person> people{} ;
	people.insert({"Callie" , 27, 'F'}) ;
	people.insert({"Nancy" , 27, 'F'}) ;
	people.insert({"Lauren", 16, 'F'}) ;
	people.insert({"Lucas", 27, 'M'}) ;
	people.insert({"Kevin", 27, 'M'}) ;
	people.insert({"Max", 27, 'M'}) ;
	people.insert({"Baylee", 22, 'F'}) ;

	for(auto &person : people) {
		std::cout << std::format("{:<8} {:>3}  {}\n", person.name, person.age, person.gender) ;
	}
}
