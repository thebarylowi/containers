#pragma once

#include <cstddef>
#include <iostream>
#include <algorithm>
#include <optional>
#include <functional>
#include <limits>
#include <initializer_list>

namespace container
{

template <typename T, std::size_t elements_count>
class array
{
public:
    array()
    {
        _data = new T[_size];
        for (std::size_t i = 0; i < _size; ++i)
        {
            _data[i] = 0;
        }
    }

    array(std::initializer_list<T> args)
    {
        if (elements_count != 0)
        {
            _data = new T[_size];

            for (const auto& arg : args)
            {
                insert(arg);
            }
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

    array(array&& other)
    {
        _data = other._data;
        _size = other._size;

        other._data = nullptr;
        _size = 0;
    }

    array& operator=(const array& other)
    {
        if (_size == other.size())
        {
            _size = other.size();
            _data = new T[_size];
            std::copy(other._data, other._data + _size, _data);
        }
        else
        {
            std::cerr << "not able to assing this array, size of array: " << _size << ", and other array: " << other._size << std::endl;
        }
        return *this;
    }

    T& operator[](const std::size_t index)
    {
        return _data[index];
    }

    friend bool operator==(const array<T, elements_count>& lhs, const array<T, elements_count>& rhs)
    {
        for (size_t i = 0; i < lhs._size; ++i)
        {
            if (lhs.at(i) != rhs.at(i))
            {
                return false;
            }
        }
        return true;
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

    bool empty() const
    {
        return _size == 0;
    }

    std::optional<std::reference_wrapper<T>> front() const
    {
        if (_size == 0)
        {
            return std::nullopt;
        }
        return _data[0];
    }

    std::size_t max_size() const
    {
        return std::numeric_limits<std::size_t>::max();
    }

    std::optional<std::reference_wrapper<T>> back() const
    {
        if (_size == 0)
        {
            return std::nullopt;
        }
        return _data[_size - 1];
    }

    T* begin() noexcept
    {
        return _data;
    }

    T* end() noexcept
    {
        return _data + _size;
    }

private:
    void insert(const T& value)
    {
        _data[_current] = value;
        _current++;
    }

    T* _data = nullptr;
    std::size_t _size = elements_count;
    std::size_t _current{0};
};
}