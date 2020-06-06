#pragma once

#include <iostream>
#include "vec.hpp"

namespace helper {

using namespace containers;

void print(vec& arr) {
	for (size_t i = 0; i < arr.length(); ++i) {
		::std::cout << arr[i] << " ";
	}
	::std::cout << "\n";
}
	
}