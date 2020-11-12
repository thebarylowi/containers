import std.core;
import array;

int main() {
	array<int, 10> a{1,2,3,4,5,6,7,8,9,10};
	array<int, 10> b{ 1,2,3,4,5,6,7,8,9,10 };
	a.swap();
	
	if (a == b)
		std::cout << "hello";
	else
		std::cout << "no!";

}