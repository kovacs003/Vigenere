#ifndef VIGNOERE_MY_MAP_H
#define VIGNOERE_MY_MAP_H

#include <cstdio>

namespace vignere_coding {

template <typename Type, unsigned int Size>
inline unsigned int get_size(const Type (&)[Size]) {
    return Size;
}

template<typename KeyType, typename ValueType>
class MyMap {
    KeyType* key;
    ValueType* value;
    unsigned int size;

    int binary_search(const ValueType& search);

public:
    MyMap();
    ~MyMap();

    template<size_t T>
    void add_arrays(const KeyType (&keys)[T], const ValueType (&values)[T]) {
        for(size_t loop = 0; loop < T; ++loop) {
            add_new(keys[loop], values[loop]);
        }
    }

    void add_new(const KeyType& key, const ValueType& new_value);
    ValueType& operator[](const KeyType& search);
    ValueType& at(const KeyType& search);
};

}  // namespace vignere_coding

#endif // VIGNOERE_MY_MAP_H
