#pragma once

#include <optional>
#include <functional>
#include <iostream>

namespace collections
{

template <typename T>
class stack
{
public:
	stack() = default;
	~stack() {}

	void operator=(const stack<T>& other)
	{
		if (_data)
		{
			delete[] _data;
			_size = 0;
		}

		T* temp = new T[other._size];
		_size = other._size;

		for (size_t i = 0; i < other._size; ++i)
		{
			temp[i] = other._data[i];
		}
		_data = temp;
	}

	void push(T value)
	{
		if (_data)
		{
			handleAddingNewElementWhenStackIsNotEmpty(value);
		}
		else
		{
			handleAddingNewElementWhenStackIsEmpty(value);
		}
	}

	void emplace(T&& value)
	{
		if (_data)
		{
			handleAddingNewElementWhenStackIsNotEmpty(value);
		}
		else
		{
			handleAddingNewElementWhenStackIsEmpty(value);
		}
	}

	void pop()
	{
		if (_data)
		{
			const auto new_size = _size - 1;
			T* temp = new T[new_size];

			for (size_t i = 0; i < new_size; ++i)
			{
				temp[i] = _data[i];
			}

			delete[] _data;
			_data = temp;
			_size--;
		}
	}

	void swap()
	{
		if (_data)
		{
			T* temp = new T[_size];

			for (size_t i = 0; i < _size; ++i)
			{
				temp[_size - i - 1] = _data[i];
			}

			delete[] _data;
			_data = temp;
		}
	}

	std::optional<std::reference_wrapper<T>> top()
	{
		if (_data)
		{
			return _data[_size - 1];
		}
		return std::nullopt;
	}

	bool empty() { return _size == 0; }
	size_t size() { return _size; }

	void display()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			std::cout << _data[i] << " ";
		}
	}

private:
	void handleAddingNewElementWhenStackIsNotEmpty(T value)
	{
		T* temp = new T[_size + 1];
		for (size_t i = 0; i < _size; ++i)
		{
			temp[i] = _data[i];
		}
		delete[] _data;
		temp[_size] = value;
		_data = temp;
		_size++;
	}

	void handleAddingNewElementWhenStackIsEmpty(T value)
	{
		_size = 1;
		T* temp = new T[_size];
		temp[0] = value;
		_data = temp;
	}

	T* _data = nullptr;
	size_t _size{ 0 };
};

}
