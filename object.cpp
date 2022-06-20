#include "object.h"
#include <iostream>



namespace Inventory {
	bool object::find(const std::string& to_find) {
		for (int i = 0; i < name.size(); i++) {
			if (name.size() - i - to_find.size() < 0)
				break;
			if (name[i] == to_find[0]) {
				int j = 0;
				int last_i = i;
				for (; j < to_find.size(); j++) {
					if (last_i + j < name.size() && name[j + last_i] == to_find[j]) {
						i++;
						continue;
					}
					i--;
					break;
				}
				if (j == to_find.size())
					return true;
			}
		}
		if (isdigit(to_find[1])) {
			int _code = stoi(to_find);
			if (_code == code)
				return true;
		}
		return false;
	}
	void object::print() {
		std::cout << "name: " << name << "   total price: " << quantity * price << "   quantity: " << quantity;
		std::cout << "   price: " << price << "   code: " << code;
		
		return;
	}
	void object::change_name(const std::string& new_name) {
		name = new_name;
		return;
	}
	void object::change_price(double new_price) {
		price = new_price;
		return;
	}
	void object::change_quantity(int new_quantity) {
		quantity = new_quantity;
		return;
	}
	std::ostream& object::to_operator(std::ostream& os) {
		os << "name: " << name << "   total price: " << quantity * price << "   quantity: " << quantity;
		os << "   price: " << price << "   code: " << code;
		return os;
	}
	std::ostream& operator<<(std::ostream& os,object& c)
	{
		return c.to_operator(os);
	}
	
}

