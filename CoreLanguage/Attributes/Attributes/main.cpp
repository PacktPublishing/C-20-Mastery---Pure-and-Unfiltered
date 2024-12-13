struct DbInfo {
	[[nodiscard("DbInfo object not used")]]DbInfo(){}
};

[[nodiscard("Database operation details lost")]] DbInfo Get() { 
	DbInfo info ;
	return info ;
}

[[nodiscard("Potential memory leak")]] void *RawAlloc(size_t size) {
	return operator new(size) ;
}

[[nodiscard("Token not captured")]] int Register() {
	return 100 ;
}
void Deregister(int token) {
	
}

enum class [[nodiscard("Error codes must not be ignored")]]
ErrorCode{SUCCESS, FAILURE, WARNING};

ErrorCode CreateComponent() {
	return ErrorCode::FAILURE ;
}

void Foo(const DbInfo &db) {
	
}
int main() {
	Get() ;
	RawAlloc(100) ;
	Register() ;
	CreateComponent() ;

	Foo(DbInfo{}) ;
}
