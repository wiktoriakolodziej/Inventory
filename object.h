#pragma once
#include <string> // strlen()
#include <cstdlib> //rand()
#include <ctime> //time()

#include <iostream>

#include "date.h"



namespace Inventory{
	class object {
		std::string name;
		int quantity, code;
		double price;
		

	public:
		object(const std::string name, const double price, const int quantity = 1) : name(name), price(price), quantity(quantity) {
			srand(time(NULL));
			code = RAND_MAX % rand();

			
		}
		bool find(const std::string& to_find);
		void virtual print();
		virtual std::ostream& to_operator(std::ostream& os);	
		void change_name(const std::string& new_name);
		void change_price(double new_price);
		void change_quantity(int new_quantity);
		std::string print_name() {

			return name;
		}
		bool operator ==(const object& c) {
			return (name == c.name && price == c.price && quantity == c.quantity && code == c.code);
		}
		object& operator = (const object& c) {
			if (*this == c)
				return *this;
			name = c.name;
			price = c.price;
			quantity = c.quantity;
			code = c.code;
			return *this;
		}
		int virtual compare() {
			return -1;
		}
		friend std::ostream& operator << (std::ostream& os, object& c);
		
	};
	

	
}

