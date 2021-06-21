#pragma once

#include <functional>
#include <optional>

namespace container
{

template <typename T>
class stack
{
public:
    // TODO: add rule of 5!
    stack() = default;

    void operator=(const stack<T>& other) noexcept
    {
        if (_data)
        {
            delete[] _data;
            _size = 0;
        }

        auto* temp = new T[other._size];
        _size = other._size;

        for (size_t i = 0; i < _size; ++i)
        {
            temp[i] = other._data[i];
        }
        _data = temp;
    }

    friend bool operator==(const stack& lhs, const stack& rhs)
    {
        if (lhs._size != rhs._size)
        {
            return false;
        }

        for (size_t i = 0; i < lhs._size; ++i)
        {
            if (lhs._data[i] != rhs._data[i])
            {
                return false;
            }
        }
        return true;
    }

    ~stack() noexcept
    {
        delete[] _data;
    }

    std::optional<std::reference_wrapper<T>> top() const
    {
        if (_data)
        {
            return _data[_size - 1];
        }

        return std::nullopt;
    }

    void push(const T& value)
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

    void emplace(const T&& value)
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
            for (size_t i = 0; i < _size; ++i)
            {
                temp[_size - i - 1] = _data[i];
            }
            delete[] _data;
            _size = new_size;
            _data = temp;
        }
    }

    size_t size() const noexcept
    {
        return _size;
    }

    bool empty() const noexcept
    {
        return _size == 0;
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
    size_t _size{0};
};

}