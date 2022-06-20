#include "complex_object.h"
#include "object.h"
#include <iostream>

namespace Inventory {
	std::ostream& complex_object::to_operator(std::ostream& os) {
		object::to_operator(os);
		os << "  date: " << date;
		return os;
	}


}