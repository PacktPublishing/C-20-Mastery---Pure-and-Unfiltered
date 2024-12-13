
#include <format>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

template<typename Container>
void PrintF(Container&& container, std::string_view message = "", char separator = ' ') {
	std::cout << std::format("{:<12}: [", message);
	for (const auto& element : container) {
		std::cout << std::format("{:>3}{}", element, separator);
	}
	std::cout << "]\n";
}
template<typename Container>
void PrintUD(Container&& container, std::string_view message = "", char separator = ' ') {
	std::cout << std::format("======= {} =======\n", message);
	for (const auto& element : container) {
		std::cout << element << separator;
	}
	std::cout << '\n';
}
struct Document {
	std::string name{};
	size_t size{};
	std::string type{};
	std::string tag{};
	friend std::ostream& operator <<(std::ostream& out, const Document& doc) {
		return out << std::format("{:<12} {:>6}    {:<8} {:<10}", doc.name, doc.size, doc.type, doc.tag);
	}
	auto operator <=>(const Document&)const = default;
};
struct BackedupDocuments {
	std::vector<Document> docs{} ;
	void operator()(Document &other) {
		if(other.type == "Word") {
			docs.push_back(other) ;
			//Perform the conversion
			other.type = "PDF" ;
		}
	}
};

void ForEach(std::vector<Document> & docs) {
		/*auto doc_backup = std::for_each(docs.begin(), docs.end(), BackedupDocuments{}) ;
	PrintUD(doc_backup.docs, "Backup", '\n') ;

	PrintUD(docs, "Original", '\n') ;*/

	/*std::ranges::in_fun_result*//*<std::vector<Document>::iterator, BackedupDocuments>*/
	/*auto result	*/

	//std::ranges::for_each_result result = std::ranges::for_each(docs, BackedupDocuments{}) ;

	auto [itr, fnObj]= std::ranges::for_each(docs, BackedupDocuments{}) ;
	assert(itr == docs.end()) ;
	PrintUD(fnObj.docs, "Backup", '\n') ;

	PrintUD(docs, "Original", '\n') ;
}

void InOutCopy(std::vector<Document> &docs) {
	std::vector<Document> copies(9) ;
	copies.emplace_back("Budgeting", 80123,"Excel","internal") ;
	copies.emplace_back("Expenses", 21798,"Excel","internal") ;
	copies.emplace_back("Tax", 78312,"Excel","internal") ;
	//auto itr = std::copy_if(docs.begin(), docs.end(), copies.begin(), [](const Document &doc) {
	//	return doc.type == "Excel" ;
	//}) ;
	//if(itr != copies.end()) {
	//	std::cout << *(itr-1) << '\n' ;
	//}

	//PrintUD(copies,"Copies", '\n') ;

	auto [in, out] = std::ranges::copy_if(docs, copies.begin(), [](const Document &doc) {
		return doc.type == "Excel" ;
	}) ;
	assert(in == docs.end()) ;
	//if(itr != copies.end()) {
	//	std::cout << *(itr-1) << '\n' ;
	//}

	PrintUD(copies,"Copies", '\n') ;


}

void MinMaxResult(std::vector<Document> docs) {
	/*auto [min, max] = std::minmax_element(docs.begin(), docs.end(), [](const auto &d1, const auto &d2) {
		return d1.size < d2.size ;
	}) ;
	std::cout << *min << '\n' ;
	std::cout << *max << '\n' ;*/

	auto [min, max] = std::ranges::minmax_element(docs, [](const auto &d1, const auto &d2) {
		return d1.size < d2.size ;
	}) ;
	std::cout << *min << '\n' ;
	std::cout << *max << '\n' ;
}

int main() {
	std::vector<Document> docs{
			{"Reports", 5123,"Word","internal"},
			{"Sales", 71591,"Excel","public"},
			{"Revenue", 80153,"Excel","internal"},
			{"Portfolio", 85103,"PDF","public"},
			{"Customers", 70213,"Excel","internal"},
			{"Quotation", 5092,"Word","public"},
	};
	InOutCopy(docs) ;




}