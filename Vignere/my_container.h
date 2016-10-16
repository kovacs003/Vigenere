#ifndef VIGNERE_MY_CONTAINER_H
#define VIGNERE_MY_CONTAINER_H

#include <cstdio>

namespace vignere_coding {

template<class Type>
class MyContainer {
protected:
    Type* container;
    size_t capacity;
    size_t size;

public:
    MyContainer();
    explicit MyContainer(const size_t& size);
    virtual ~MyContainer();

    MyContainer(const MyContainer& other);
    MyContainer& operator=(const MyContainer<Type>& other);


    virtual void push_back(const Type& elem);
    Type& operator[](const size_t& pos) const;
    Type& at(const size_t& pos) const;

    Type* get_content() const noexcept;
    size_t get_size() const noexcept;
    size_t get_capacity() const noexcept;

    void swap(MyContainer<Type> &other);

};

}  // namespace vignere_coding {

#endif // VIGNERE_MY_CONTAINER_H
