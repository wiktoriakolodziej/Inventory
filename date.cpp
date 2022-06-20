#include "date.h";
#include <iostream>
#include <string>

namespace Inventory{
	std::ostream& operator << (std::ostream& os, const Date& d) 
	{
		os  << d.day << "." << d.month << "." << d.year;
		return os;
	}
}