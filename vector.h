#pragma once
#include <vector>
#include "object.h"
#include "complex_object.h"


namespace Inventory {
	class my_vector {
		std::vector <object*> inventory;
	public:
		void create_new();
		void iterate_and_find();
		void change_params();
		void exportt();
		void alerts();
		std::vector <int> show_objects(std::string to_find);
		void delete_object();
		~my_vector() noexcept{
			for (int i = 0; i < inventory.size(); i++) {
				delete inventory[i];
			}
		}
	};
}
