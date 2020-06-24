#include "stack.hpp"
#include <iostream>
int main() {
	using namespace collections;

	stack<int> a; a.push(1); a.push(2);
	stack<int> b = a;
	a.display();
	const auto a_ = a.top();

	std::cout << *a_;
	b.display();

	return 0;
}