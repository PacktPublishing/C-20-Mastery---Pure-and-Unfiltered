#include <string_view>
#include <iostream>
enum class Color{Red, Green, Blue};

std::string_view ToString(Color color) {
	switch(color) {
		using enum Color ;
	case Red:
		return "Red" ;
	case Green:
		return "Green" ;
	case Blue:
		return "Blue" ;
	}
	return "unknown color" ;
}

class Socket {
public:
	enum SocketType {
		STREAM,
		DATAGRAM
	};
};

void Create(Socket::SocketType type) {
	
}
int main() {
	using Color::Red ;
	Color c = Red ;
	std::cout << ToString(c) << '\n' ;

	using enum Socket::SocketType ;

	using Socket::STREAM ;
	Create(STREAM) ;
}