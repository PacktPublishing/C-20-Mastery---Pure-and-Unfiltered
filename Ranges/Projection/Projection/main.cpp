#include <algorithm>
#include <format>
#include <iostream>
#include <random>
#include <vector>

struct Identity {
	template<typename T>
	constexpr T&& operator()(T &&e)const noexcept {
		return std::forward<T>(e) ;
	}
};
template<typename Range, typename Functor, typename Projection=Identity>
void ForEach(Range &&range, Functor functor, Projection proj={}) {
	auto beg = range.begin() ;
	auto end = range.end() ;
	while(beg != end) {
		auto && element = std::invoke(proj, *beg++) ;
		functor(element) ;
	}
}
struct Document {
	std::string name{};
	size_t size{};
	std::string type{};
	std::string tag{};
	friend std::ostream& operator <<(std::ostream& out, const Document& doc) {
		return out << std::format("{:<12} {:>6}    {:<8} {:<10}", doc.name, doc.size, doc.type, doc.tag);
	}
	const std::string & GetName()const {
		return name ;
	}
};
int main() {
	/*std::vector<int> data(10) ; ;
	std::ranges::generate(data, []() {
		return std::random_device{}() % 10 ;
	}) ;
	auto printer = [](int x){std::cout << x << ' ';} ;
	ForEach(data, printer) ;*/
		std::vector<Document> docs{
		{"Reports", 5123,"Word","internal"},
		{"Sales", 71591,"Excel","public"},
		{"Revenue", 80153,"Excel","internal"},
		{"Portfolio", 85103,"PDF","public"},
		{"Customers", 70213,"Excel","internal"},
		{"Quotation", 50092,"Word","public"},
	};
	auto printer = [](const auto & x){std::cout << x << '\n';} ;
	//auto names = [](auto &doc){return doc.name ;} ;
	auto kb = [](auto &doc) {
		return std::format("{:>2} kb", doc.size/1024) ;
	} ;
	//ForEach(docs, printer, kb) ;

	auto def = []<typename T>(T &&e)->T&& {
		return std::forward<T>(e) ;
	} ;
	auto upper = [def](const auto &doc) {
		auto name{doc.name} ;
		ForEach(name, [](char &ch) {
			ch = toupper(ch) ;
		}/*, def*/) ;
		return name ;
	};
	ForEach(docs, printer, upper) ;


}