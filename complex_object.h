#pragma once
#include "object.h"
#include "date.h"

namespace Inventory {

	class complex_object : public object {
		Date date;
	public:
		complex_object(const std::string name, const double price, const std::string date, const int quantity = 1) : object(name, price, quantity), date(date) {

		}
		void print() {
			object::print();
			std::cout << "   date: " << date;
		}
		int compare() {
			return difftime( this->date.ToTime_t(), time(NULL));
		}
		std::ostream& to_operator(std::ostream& os);
		

	};
}
