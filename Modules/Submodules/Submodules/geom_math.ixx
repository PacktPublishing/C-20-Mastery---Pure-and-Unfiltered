module;
#include <numbers>
export module poash.geom_math;


export double CircleArea(double radius){
	return std::numbers::pi * radius * radius ;
}