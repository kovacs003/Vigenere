#include "my_container.h"
#include "my_string.h"

namespace vignere_coding {

template class MyContainer<char>;
template class MyContainer<MyString>;

template<class Type>
MyContainer<Type>::MyContainer()
    : container(new Type[2]), capacity(2), size(0) { }

template<class Type>
MyContainer<Type>::MyContainer(const size_t &size)
    : container(new Type[size]), capacity(size), size(0) { }

template<class Type>
MyContainer<Type>::~MyContainer() {
    delete[] container;
}

template<class Type>
MyContainer<Type>::MyContainer(const MyContainer &other)
    : capacity(other.get_capacity()),
      size(other.get_size()) {
    container = new Type[capacity];
    const auto& tmp_cont = other.get_content();
    for (size_t pos = 0; pos < size; ++pos) {
        container[pos] = tmp_cont[pos];
    }
}

template<class Type>
MyContainer<Type>& MyContainer<Type>::operator=(const MyContainer<Type>& other) {
    capacity = other.get_capacity();
    size = other.get_size();

    delete[] container;
    container = new Type[capacity];
    const auto& tmp_cont = other.get_content();
    for (size_t pos = 0; pos < size; ++pos) {
        container[pos] = tmp_cont[pos];
    }

    return *this;
}

template<class Type>
void MyContainer<Type>::push_back(const Type &elem) {
    if (size == capacity) {
        capacity *= 2;
        Type* tmp_cont = new Type[capacity];
        for (size_t loop = 0; loop < size; ++loop) {
            tmp_cont[loop] = container[loop];
        }
        delete[] container;
        container = tmp_cont;
    }
    container[size++] = elem;
}

template<class Type>
Type& MyContainer<Type>::operator[](const size_t &pos) const {
    return at(pos);
}

template<class Type>
Type& MyContainer<Type>::at(const size_t &pos) const {
    if (pos > size - 1) {
        throw std::out_of_range("Rossz pozíció:" + std::to_string(pos));
    }

    return container[pos];
}

template<class Type>
Type* MyContainer<Type>::get_content() const noexcept {
    return container;
}

template<class Type>
size_t MyContainer<Type>::get_size() const noexcept {
    return size;
}

template<class Type>
size_t MyContainer<Type>::get_capacity() const noexcept {
    return capacity;
}

template<class Type>
void MyContainer<Type>::swap(MyContainer<Type> &other) {
    const auto& capacity_ = other.get_capacity();
    const auto& size_ = other.get_size();
    const auto& other_cont = other.get_content();
    Type* container_ = new Type[size_];
    for (size_t pos = 0; pos < size_; ++pos) {
        container_[pos] = other_cont[pos];
    }

    other = *this;

    delete[] container;
    container = container_;
    capacity = capacity_;
    size = size_;
}

}  // namespace vignere_coding
