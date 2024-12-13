#include <iostream>

consteval int Sum(int x,int y) {
	return x + y;
}
constexpr int Subtract(int x,int y){
    return x - y;
}
int Product(int x,int y){
    return x * y;
}
consteval int Operate(int x,int y, char ch){
    switch(ch){
        case 'A':
        return Sum(x,y) ;
        case 'S':
        return Subtract(x,y) ;
        case 'P':
        return Product(x,y) ;
    }
    return 0 ;
}
int main() {
	std::cout << Sum(3,5) << '\n' ;
	const int a = 5 ;
	std::cout << Sum(3,a) << '\n' ;
	
    std::cout << Operate(1,2, 'A') << '\n' ;
    std::cout << Operate(1,2, 'S') << '\n' ;
    std::cout << Operate(1,2, 'P') << '\n' ;

}