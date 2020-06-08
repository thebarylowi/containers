#pragma once

namespace containers
{

using iterator = int*;

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
		resize_if_needed();
		data[current] = value;
		current++;
	}

	void clear() {
		for (size_t i = 0; i < capacity; ++i) {
			data[i] = 0;
		}
	}

	void shrink_to_fit() {
		iterator temp = new int[current];
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

	void emplace(const int position, int&& value) {
		if (position < current) {
			data[position] = value;
		}
	}

	void assign(size_t count, int value) {
		current = count;
		for (size_t i = 0; i < current; ++i) {
			data[i] = value;
		}
	}

	void emplace_back(int&& value) {
		resize_if_needed();
		data[current] = value;
		current += 1;
	}

	void swap(vec& other) {
		if (current == other.length()) {
			iterator temp = new int[current];
			for (size_t i = 0; i < current; ++i) {
				temp[i] = data[i];
			}

			for (size_t i = 0; i < current; ++i) {
				data[i] = other[i];
				other[i] = temp[i];
			} 

			delete[] temp;
		}
	}

	void resize(size_t count) {
		if (count > current) {
			for (size_t i = current; i < count; ++i) {
				data[i] = 0;
			}
			current = count;
		} else {
			current = count;
		}
	}

	void pop_back() {
		current -= 1;
	}

	int& operator[](const int index) { return data[index]; }
	size_t size() { return capacity; }
	size_t length() { return current; }
	bool empty() { return current == 0; }
	int at(size_t index) { return data[index]; }
	iterator begin() { return data; }
	iterator end() { return data + (current - 1); }
	int& front() { return *begin(); }
	int& back() { return *end(); }

private:
	void resize_if_needed() {
		if (current == capacity) {
			resize();
		}
	}

	void resize() {
		iterator temp = new int[3 * capacity];
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
