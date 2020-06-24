#pragma once

#include <iostream>
#include <optional>

namespace collections
{

template <typename T>
class list
{
public:
	list() = default;

	list(const list<T>& other)
	{
		auto head = other._head;
		if (head)
		{
			for (size_t i = 0; i < other._size; ++i)
			{
				push_back(head->_data);
				head = head->_next;
			}
		}
	}

	friend bool operator==(const list<T>& lhs, const list<T>& rhs)
	{
		if (lhs._size == rhs._size)
		{
			auto rhead = rhs._head;
			auto lhead = lhs._head;

			while (rhead != rhs._tail and rhead->_next != nullptr and
				   lhead != lhs._tail and lhead->_next != nullptr)
			{
				if (rhead->_data != lhead->_data)
				{
					return false;
				}
				rhead = rhead->_next;
				lhead = lhead->_next;
			}
		}
		return true;
	}

	void operator=(const list<T>& other)
	{
		clear();
		auto head = other._head;

		if (head)
		{
			for (size_t i = 0; i < other._size; ++i)
			{
				push_back(head->_data);
				head = head->_next;
			}
		}
	}

	void push_back(T value)
	{
		const auto temp = new node(value);
		if (_head == nullptr)
		{
			_head = _tail = temp;
		}
		else
		{
			_tail->_next = temp;
			_tail = temp;
		}
		_size++;
	}

	void clear()
	{
		delete[] _head;
		_head = _tail = nullptr;
		_size = 0;
	}

	std::optional<T> back()
	{
		if (_tail)
		{
			return _tail->_data;
		}
		return std::nullopt;
	}

	std::optional<T> front()
	{
		if (_head)
		{
			return _head->_data;
		}
		return std::nullopt;
	}

	void assign(size_t count, T value)
	{
		for (size_t i = 0; i < count; ++i)
		{
			push_back(value);
		}
	}

	size_t size() { return _size; }
	bool empty() { return _size == 0; }

	void display_list()
	{
		auto temp = _head;
		while (temp)
		{
			std::cout << temp->_data << " ";
			temp = temp->_next;
		}
		std::cout << std::endl;
	}

private:
	template <typename T>
	struct node
	{
		node(T value)
			: _data(value)
		{}

		node* _next{ nullptr };
		T _data;
	};

	node<T>* _head{ nullptr };
	node<T>* _tail{ nullptr };
	size_t _size{ 0 };
};

}
