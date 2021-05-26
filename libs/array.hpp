#pragma once

#include <cstddef>
#include <iostream>

namespace container
{

template <typename T, std::size_t elements_count>
class array
{
public:
    // TODO: implement full rule of 5
    array()
    {
        _data = new T[_size];
        for (std::size_t i = 0; i < _size; ++i)
        {
            _data[i] = 0;
        }
    }

    array(const array& other)
    {
        const std::size_t otherSize = other.size();
        _data = new T[otherSize];
        for (std::size_t i = 0; i < otherSize; ++i)
        {
            _data[i] = other._data[i]; 
        }
    }

    void operator=(const array& other)
    {
        if (_size == other.size())
        {
            for (std::size_t i = 0; i < _size; ++i)
            {
                _data[i] = other._data[i];
            }
        }
        else
        {
            std::cerr << "not able to assing this array, size of array: " << _size << ", and other array: " << other._size << std::endl;
        }
    }

    T& operator[](const std::size_t index)
    {
        return _data[index];
    }

    ~array()
    {
        delete[] _data;
    }

    std::size_t size() const
    {
        return _size;
    }

    T& at(const std::size_t index) const
    {
        return _data[index];
    }

private:
    T* _data = nullptr;
    std::size_t _current{0};
    const std::size_t _size = elements_count;
};
}