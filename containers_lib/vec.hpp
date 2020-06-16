#pragma once

#include <string>

namespace collections
{

using index = unsigned;
template <typename T>
using iterator = T*;

template <typename T>
class vec
{
public:
	vec() : _data(new T[_capacity]) {}

	~vec() { delete[] _data; }

	T& operator[](const size_t index) { return _data[index]; }

	void push_back(T value)
	{
		resize_if_needed();
		_data[_current] = value;
		_current++;
	}

	void pop_back()
	{
		if (_current != 0)
		{
			_current -= 1;
		}
	}

	void emplace_back(T&& value)
	{
		resize_if_needed();
		_data[_current] = value;
		_current++;
	}

	void reverse()
	{
		size_t begin = 0;
		size_t end = _current - 1;

		while (begin < end)
		{
			T temp = _data[begin];
			_data[begin] = _data[end];
			_data[end] = temp;

			begin++;
			end--;
		}
	}

	void clear()
	{
		for (size_t i = 0; i < _current; ++i)
		{
			_data[i] = 0;
		}
	}

	void shrink_to_fit()
	{
		iterator<T> temp = new T[_current];
		for (size_t i = 0; i < _current; ++i)
		{
			temp[i] = _data[i];
		}

		delete[] _data;
		_data = temp;
		_capacity = _current;
	}

	void assign(const size_t count, const T value)
	{
		_current = count;
		for (size_t i = 0; i < _current; ++i)
		{
			_data[i] = value;
		}
	}

	void resize(size_t count)
	{
		if (count > _current)
		{
			for (size_t i = _current; i < count; ++i)
			{
				_data[i] = 0;
			}
		}
		_current = count;
	}

	void swap(vec& other)
	{
		if (_current == other._current)
		{
			iterator<T> temp = new T[_current];
			for (size_t i = 0; i < _current; ++i)
			{
				temp[i] = _data[i];
			}

			for (size_t i = 0; i < _current; ++i)
			{
				_data[i] = other[i];
				other[i] = temp[i];
			}

			delete[] temp;
		}
	}

	size_t size() { return _current; }
	size_t capacity() { return _capacity; }
	bool empty() { return _current == 0; }
	T at(const index index) { return _data[index]; }
	iterator<T> begin() { return _data; }
	iterator<T> end() { return _data + (_current - 1); }
	T& front() { return *begin(); }
	T& back() { return *end(); }

private:
	void resize_if_needed()
	{
		if (_current == _capacity)
		{
			resize();
		}
	}

	void resize()
	{
		const auto new_capacity = 3 * _capacity;
		iterator<T> temp = new T[new_capacity];
		for (size_t i = 0; i < _capacity; ++i)
		{
			temp[i] = _data[i];
		}

		delete[] _data;
		_capacity = new_capacity;
		_data = temp;
	}

	size_t _current{ 0 };
	size_t _capacity{ 1 };
	T* _data;
};

template<>
void vec<char>::clear()
{
	for (size_t i = 0; i < _current; ++i)
	{
		_data[0] = ' ';
	}
}

template<>
void vec<std::string>::clear()
{
	for (size_t i = 0; i < _current; ++i)
	{
		_data[0] = " ";
	}
}

}