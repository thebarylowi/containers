#pragma once

#include <iostream>

namespace collections
{

class list
{
public:
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
		auto temp = _head;
		while (temp != _tail and _size != 0)
		{
			delete[] temp;
			temp++;
			_size--;
		}
	}

	int back()
	{
		if (_tail)
		{
			return _tail->_data;
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