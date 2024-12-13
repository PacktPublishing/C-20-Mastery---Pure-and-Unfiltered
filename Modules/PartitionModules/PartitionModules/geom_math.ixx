module;
#include <numbers>
export module poash.math:geom_math;


export double CircleArea(double radius){
	return std::numbers::pi * radius * radius ;
}