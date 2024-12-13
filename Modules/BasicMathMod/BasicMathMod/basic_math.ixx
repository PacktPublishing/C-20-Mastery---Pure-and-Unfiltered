module; //Global module fragment
#include <numbers>

export module poash.basicmath;

int Sum(int x,int y){
	return x + y ;
}
export int Add(int x,int y){
	return Sum(x,y) ;
}

double Square(double value){
	return value * value ;
}

export namespace CircleAlgorithms{
double Area(double radius){
	return std::numbers::pi * Square(radius) ;
}
}

