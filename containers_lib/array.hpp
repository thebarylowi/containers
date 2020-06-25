#pragma once

#include <utility>
#include <optional>
#include <exception>
#include <stdexcept>

namespace collections
{

template <typename T, size_t element_count>
class array
{
public:
	array()
	{
		if (element_count > 0)
		{
			_data = new T[_size];

			for (size_t i = 0; i < _size; ++i)
			{
				_data[i] = 0;
			}
		}
	}

	array(std::initializer_list<T> args_list)
	{
		if (element_count > 0)
		{
			_data = new T[_size];

			for (const auto& arg : args_list)
			{
				insert(arg);
			}
		}
	}

	~array() = default;

	friend bool operator==(const array<T, element_count>& lhs, const array<T, element_count>& rhs)
	{
		if (lhs.size() != rhs.size())
		{
			return false;
		}

		for (size_t i = 0; i < lhs.size(), i < rhs.size(); ++i)
		{
			if (lhs.at(i) != rhs.at(i))
			{
				return false;
			}
		}
		return true;
	}

	T& at(const size_t index) const
	{
		if (not _data)
		{
			throw std::out_of_range("empty array!");
		}
		return _data[index]; 
	}

	T& operator[](const size_t index) { return _data[index]; }
	const size_t size() const { return _size; }
	bool empty() const { return _size == 0; }
	size_t max_size() const { return sizeof(size_t); }

	std::optional<std::reference_wrapper<T>> front() const
	{
		if (_size == 0)
		{
			return std::nullopt;
		}
		return _data[0];
	}

	std::optional<std::reference_wrapper<T>> back() const
	{
		if (_size == 0)
		{
			return std::nullopt;
		}
		return _data[_size - 1];
	}

	T* data() const
	{
		if (_size == 0)
		{
			return nullptr;
		}
		return _data;
	}

	void fill(const T& value)
	{
		for (size_t i = 0; i < _size; ++i)
		{
			_data[i] = value;
		}
	}

	void swap()
	{
		T* temp = new T[_size];

		for (size_t i = 0; i < _size; ++i)
		{
			temp[_size - 1 - i] = _data[i];
		}

		delete[] _data;
		_data = temp;
	}

private:
	void insert(const T& value)
	{
		_data[_current] = value;
		_current++;
	}

	T* _data = nullptr;
	size_t _current{ 0 };
	const size_t _size = element_count;
};

}
