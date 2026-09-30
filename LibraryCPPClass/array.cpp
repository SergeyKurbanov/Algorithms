#include "array.h"
#include <stdexcept>

Array::Array(size_t size)
    : data_(new Data[size]), size_(size)
{
}

Data* Array::copy_data(const Array& a)
{
    Data* new_data = new Data[a.size_];

    for (size_t i = 0; i < a.size_; ++i)
        new_data[i] = a.data_[i];

    return new_data;
}

Array::Array(const Array &a)
    : data_(copy_data(a)), size_(a.size_)
{
}

Array &Array::operator=(const Array &a)
{
    if (this == &a)
        return *this;

    Data *new_data = copy_data(a);

    delete[] data_;

    data_ = new_data;
    size_ = a.size_;

    return *this;
}

Array::~Array()
{
    delete[] data_;
}

Data Array::get(size_t index) const
{
    if (index >= size_)
        throw std::out_of_range("Array index out of range");

    return data_[index];
}

void Array::set(size_t index, Data value)
{
    if (index >= size_)
        throw std::out_of_range("Array index out of range");

    data_[index] = value;
}

size_t Array::size() const
{
    return size_;
}