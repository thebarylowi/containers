#pragma once

#include <optional>
#include <functional>


namespace collections
{

template <typename T>
class queue
{
public:
	queue() = default;
	~queue() = default;

	void operator=(const queue<T>& other)
	{
		if (_data)
		{
			delete[] _data;
			_size = 0;
		}

		const auto size = other._size;
		T* temp = new T[size];

		for (size_t i = 0; i < size; ++i)
		{
			temp[i] = other._data[i];
		}

		_size = size;
		_data = temp;
	}

	void push(T value)
	{
		if (_data)
		{
			handleAddingNewElementWhenDataExisit(value);
		}
		else
		{
			handleAddingNewElementWhenNoDataExist(value);
		}
	}

	void pop()
	{
		if (_data)
		{
			const auto size = _size - 1;
			T* temp = new T[size];

			for (size_t i = 1; i < _size; ++i)
			{
				temp[i - 1] = _data[i];
			}

			delete[] _data;
			_size = size;
			_data = temp;
		}
	}

	void emplace(T&& value)
	{
		if (_data)
		{
			handleAddingNewElementWhenDataExisit(value);
		}
		else
		{
			handleAddingNewElementWhenNoDataExist(value);
		}
	}

	void swap()
	{
		if (_data)
		{
			T* temp = new T[_size];
			for (size_t i = 0; i < _size; ++i)
			{
				temp[_size - 1 - i] = _data[i];
			}
			delete[] _data;
			_data = temp;
		}
	}

	std::optional<std::reference_wrapper<T>> back()
	{
		if (_data)
		{
			return _data[_size - 1];
		}
		return std::nullopt;
	}

	std::optional<std::reference_wrapper<T>> front()
	{
		if (_data)
		{
			return _data[0];
		}
		return std::nullopt;
	}

	size_t size() { return _size; }
	bool empty() { return _size == 0; }

private:
	void handleAddingNewElementWhenDataExisit(T& value)
	{
		const auto new_size = _size + 1;
		T* temp = new T[new_size];

		for (size_t i = 0; i < _size; ++i)
		{
			temp[i] = _data[i];
		}

		temp[_size] = value;
		delete[] _data;
		_data = temp;
		_size++;
	}

	void handleAddingNewElementWhenNoDataExist(T& value)
	{
		_data = new T[1];
		_data[0] = value;
		_size++;
	}

	T* _data = nullptr;
	size_t _size{ 0 };
};

}
