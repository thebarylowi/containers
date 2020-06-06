#include <iostream>

#include "vec.hpp"
#include "helper_func.hpp"

int main() {
	using namespace helper;
	using namespace containers;

	vec arr;
	arr.push_back(1); arr.push_back(2); arr.push_back(3);
	helper::print(arr);
	arr.reverse();
	helper::print(arr);
}