#pragma once

#include <iostream>

#include "vec.hpp"


namespace helper {

template<typename T>
void print_vec(const ::collections::vec<T>& arr) {
	for (size_t i = 0; i < arr.size(); ++i) {
		::std::cout << arr[i] << " ";
	}
	::std::cout << "\n";
}
	
}