#pragma once

namespace containers
{

class vec {
public:
	vec()
		: data(new int[capacity])
	{}

	~vec()
	{
		delete[] data;
	}

	void push_back(int value) {
		if (current == capacity) {
			resize();
		}

		data[current] = value;
		current++;
	}

	void clear() {
		for (size_t i = 0; i < capacity; ++i) {
			data[i] = 0;
		}
	}

	void shrink_to_fit() {
		int* temp = new int[current];
		for (size_t i = 0; i < current; ++i) {
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
		capacity = current;
	}

	void reverse() {
		size_t begin = 0, end = current - 1;
		while (begin < end) {
			int temp = data[begin];
			data[begin] = data[end];
			data[end] = temp;
			begin++;
			end--;
		}
	}

	int& operator[](const int index) { return data[index]; }
	size_t size() { return capacity; }
	size_t length() { return current; }
	bool empty() { return current == 0; }
	int at(size_t index) { return data[index]; }

private:
	void resize() {
		int* temp = new int[3 * capacity];
		for (size_t i = 0; i < capacity; ++i) {
			temp[i] = data[i];
		}

		delete[] data;
		data = temp;
		capacity *= 3;
	}

	size_t capacity = 50;
	size_t current = 0;
	int* data;
};

}
