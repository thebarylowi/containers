#include <iostream>

#include "vec.hpp"

void print_vec(containers::vec& arr) {
		std::cout << arr[0] << " ";
		std::cout << arr[1] << " ";
		std::cout << std::endl;
}

int main() {
	using namespace containers;

	vec a; a.push_back(1); a.push_back(2);
	print_vec(a);
	vec b; b.push_back(10); b.push_back(20);
	print_vec(b);
	a.swap(b);
	print_vec(a); print_vec(b);
}