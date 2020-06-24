#pragma once

#include <iostream>
#include <optional>

namespace collections
{

class list
{
public:
	list() = default;

	list(const list& other)
	{
		const auto size = other._size;
		auto head = other._head;

		if (head)
		{
			for (size_t i = 0; i < size; ++i)
			{
				push_back(head->_data);
				head = head->_next;
			}
		}
	}

	friend bool operator==(const list& lhs, const list& rhs)
	{
		if (lhs._size == rhs._size)
		{
			auto rhead = rhs._head;
			auto lhead = lhs._head;

			while (rhead != rhs._tail and rhead->_next != nullptr)
			{
				if (rhead->_data != lhead->_data)
				{
					std::cout << rhead->_data << " " << lhead->_data;
					return false;
				}
				rhead = rhead->_next;
				lhead = lhead->_next;
			}
		}
		return true;
	}

	void operator=(const list& other)
	{
		clear();
		const auto size = other._size;
		auto head = other._head;

		if (head)
		{
			for (size_t i = 0; i < size; ++i)
			{
				push_back(head->_data);
				head++;
			}
		}
	}

	void push_back(int value)
	{
		node* temp = new node(value);
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

	std::optional<int> back()
	{
		if (_tail)
		{
			return _tail->_data;
		}
		return std::nullopt;
	}

	std::optional<int> front()
	{
		if (_head)
		{
			return _head->_data;
		}
		return std::nullopt;
	}

	void assign(size_t count, int value)
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
		node* temp = _head;
		while (temp)
		{
			std::cout << temp->_data << " ";
			temp = temp->_next;
		}
		std::cout << std::endl;
	}

private:
	struct node
	{
		node(int value)
			: _data(value)
		{}

		node* _next{ nullptr };
		int _data;
	};

	node* _head{ nullptr };
	node* _tail{ nullptr };
	size_t _size{ 0 };
};

}
