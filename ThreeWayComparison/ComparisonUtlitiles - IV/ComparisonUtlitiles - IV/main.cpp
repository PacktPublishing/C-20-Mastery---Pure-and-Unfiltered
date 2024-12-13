#include <string>
#include <compare>
#include <format>
#include <iostream>
#include <set>

class Weather {
	double m_Celsius{} ;
	double m_Humidity{} ;
	std::string m_City{} ;

public:
	Weather(double celsius, double humidity, const std::string& city)
		: m_Celsius{celsius},
		  m_Humidity{humidity},
		  m_City{city} {
	}
	double GetTemperature()const {
		return m_Celsius ;
	}
	double GetHumidity()const {
		return m_Humidity ;
	}
	const std::string &GetCity()const {
		return m_City ;
	}
	auto  operator <=> (const Weather &rhs)const {
		auto city_ordering = m_City <=> rhs.m_City ;
		if(city_ordering != 0) {
			return city_ordering ;
		}
		return std::strong_order(m_Celsius, rhs.m_Celsius) ;
		/*auto temp_ord = m_Celsius <=> rhs.m_Celsius ;
		if(temp_ord == 0) {
			return std::strong_ordering::equal ;
		}
		if(temp_ord < 0) {
			return std::strong_ordering::less ;
		}
		return std::strong_ordering::greater ;*/
	}
};

int main() {
	std::set<Weather> weather_info{} ;
	weather_info.insert({32, 45, "Mumbai"}) ;
	weather_info.insert({25, 30, "Srinagar"}) ;
	weather_info.insert({38, 45, "Delhi"}) ;
	weather_info.insert({27, 61, "Tokyo"}) ;

	for(auto &w : weather_info) {
		std::cout << std::format("{:<10} {:<3} {:<3}\n", 
			w.GetCity(), 
			w.GetTemperature(),
			w.GetHumidity()) ; 
	}
}
