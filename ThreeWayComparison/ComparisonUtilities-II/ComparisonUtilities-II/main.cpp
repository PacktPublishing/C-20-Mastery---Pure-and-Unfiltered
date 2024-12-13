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
	std::string name{} ;
	Number age{} ;
	char gender{} ;

	auto operator<=>(const Person &rhs)const {
		//auto age_ord = age.GetNumber() <=> rhs.age.GetNumber() ;
		/*std::strong_ordering ordering{} ;
		if(age == rhs.age) {
			ordering = std::strong_ordering::equal ;
		}else if(age < rhs.age) {
			ordering = std::strong_ordering::less ;
		}else {
			ordering = std::strong_ordering::greater ;
		}
		if(ordering != 0) {
			return ordering ;
		}*/

		auto ordering = std::compare_strong_order_fallback(age, rhs.age) ;
		if(ordering != 0) {
			return ordering ;
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
		std::cout << std::format("{:<8} {:>3}  {}\n", person.name, person.age.GetNumber(), person.gender) ;
	}
}
