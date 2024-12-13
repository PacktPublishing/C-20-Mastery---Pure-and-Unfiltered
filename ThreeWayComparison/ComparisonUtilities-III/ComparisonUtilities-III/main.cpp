#include <format>
#include <iostream>
#include <set>
#include <string>
class Number {
	int m_Number{};
public:
	Number() = default;
	Number(int number) :m_Number{ number } {

	}
	int GetNumber()const {
		return m_Number;
	}
	void SetNumber(int number) {
		m_Number = number;
	}
	friend bool operator ==(const Number& lhs, const Number& rhs) {
		return lhs.m_Number == rhs.m_Number;
	}
	friend bool operator <(const Number& lhs, const Number& rhs) {
		return lhs.m_Number < rhs.m_Number;
	}
} ;
struct Person {
	char name[16]{} ;
	Number age{} ;
	char gender{} ;

	auto operator<=>(const Person &rhs)const {
		auto ordering = std::compare_strong_order_fallback(age, rhs.age) ;
		if(ordering != 0) {
			return ordering ;
		}
		auto gen_ord = gender <=> rhs.gender ;
		if(gen_ord != 0) {
			return gen_ord ;
		}
		//return name <=> rhs.name ;
		return std::lexicographical_compare_three_way(std::begin(name), std::end(name),
			std::begin(rhs.name), std::end(rhs.name)) ;
	}
};

int main() {
	Number n1[]{1,2,3}, n2[]{3,4,5} ;

	auto ordering = std::lexicographical_compare_three_way(
		std::begin(n1), std::end(n1),
		std::begin(n2), std::end(n2),
		[](const Number &lhs, const Number &rhs) {
			return std::compare_weak_order_fallback(lhs, rhs) ;
		}
		) ;



	std::set<Person> people{} ;
	people.insert({"Callie" , 27, 'F'}) ;
	people.insert({"Nancy" , 27, 'F'}) ;
	people.insert({"Lauren", 16, 'F'}) ;
	people.insert({"Lucas", 27, 'M'}) ;
	people.insert({"Kevin", 27, 'M'}) ;
	people.insert({"Max", 27, 'M'}) ;
	people.insert({"Baylee", 22, 'F'}) ;

	for(auto &person : people) {
		std::cout << std::format("{:<8} {:>3}  {}\n", person.name, person.age.GetNumber(), person.gender) ;
	}
}
