#pragma once
#include "object.h"
#include <vector>


using namespace Inventory;
void info();
double set_price();
int set_amount();
std::string set_date();
void save_in_file(object* p);