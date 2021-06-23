#pragma once

namespace container
{

template <typename T>
class vector
{
public:
    vector()
        :_data(new T[_capacity])
    {}

    vector(const vector& other)
    {
        delete[] _data;
        // _data = new T[]
    }

    void operator=(const vector& other)
    {
        delete[] _data;
        _data = new T[other._size];

        for (size_t i = 0; i < other._current; ++i)
        {
            _data[i] = other._data[i];
        }
    }

    ~vector()
    {
        delete[] _data;
    }
private:
    T* _data = nullptr;
    size_t _capacity{5};
    size_t _current{0};
};
}