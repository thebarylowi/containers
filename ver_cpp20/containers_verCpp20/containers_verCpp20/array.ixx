export module array;

import std.core;

export template <typename T, size_t element_count> class array {
public:

	array() {
		if (element_count > 0) {
			_data = new T[_size];

			for (size_t i = 0; i < _size; ++i) {
				_data[i] = 0;
			}
		}
	}

	array(std::initializer_list<T> args) {
		if (element_count > 0) {
			_data = new T[_size];

			for (const auto& arg : args) {
				insert(arg);
			}
		}
	}

	~array() {
		delete[] _data;
	}

	T& operator[](const size_t index) {
		return _data[index];
	}

	T& at(const size_t index) const {
		if (not _data) {
			throw std::out_of_range("this array is empty!");
		}
		else {
			return _data[index];
		}
	}

	friend bool operator==(const array<T, element_count>& lhs, const array<T, element_count>& rhs) {
		if (lhs.size() != rhs.size()) {
			return false;
		}
		else {
			for (size_t i = 0; i < element_count; ++i) {
				if (lhs.at(i) != rhs.at(i)) {
					return false;
				}
			}
			return true;
		}
	}

	const size_t size() const {
		return _size;
	}

	const size_t max_size() const {
		return sizeof(size_t);
	}

	bool empty() const {
		return _size == 0;
	}

	void print() const { 
		for (size_t i = 0; i < _size; ++i) {
			std::cout << _data[i] << " ";
		}
	}

	std::optional<std::reference_wrapper<T>> front() const {
		if (_size == 0) {
			return std::nullopt;
		}
		else {
			return _data[0];
		}
	}

	std::optional<std::reference_wrapper<T>> back() const {
		if (_size == 0) {
			return std::nullopt;
		}
		else {
			return _data[_size - 1];
		}
	}

	std::optional<T*> data() const {
		if (_size == 0) {
			return std::nullopt;
		}
		else {
			return _data;
		}
	}

	void fill(const T& value) {
		for (size_t i = 0; i < _size; ++i) {
			_data[i] = value;
		}
	}

	void swap() {
		T* temp = new T[_size];

		for (size_t i = 0; i < _size; ++i) {
			temp[_size - 1 - i] = _data[i];
		}

		delete[] _data;
		_data = temp;
	}
	
private:
	void insert(const T& value) {
		_data[_current] = value;
		_current++;
	}

	T* _data = nullptr;
	size_t _current{ 0 };
	const size_t _size = element_count;
};