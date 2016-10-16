#include "my_map.h"
#include <stdexcept>

namespace vignere_coding {

template class MyMap<char, char>;
template class MyMap<unsigned char, unsigned char>;
template class MyMap<unsigned short, unsigned short>;
template class MyMap<unsigned short, char>;

template<typename KeyType, typename ValueType>
MyMap<KeyType, ValueType>::MyMap()
    : key(NULL), value(NULL), size(0u) {}


template<typename KeyType, typename ValueType>
MyMap<KeyType, ValueType>::~MyMap() {
    if (key != NULL) {
        delete[] key;
    }
    if (value != NULL) {
        delete[] value;
    }
}

template<typename KeyType, typename ValueType>
int MyMap<KeyType, ValueType>::binary_search(const ValueType& search) {
    unsigned min_pos = 0;
    unsigned max_pos = size-1;
    unsigned pos = (max_pos + min_pos) / 2;
    while (key[pos] != search && min_pos < max_pos) {
        if(key[pos] > search) {
            max_pos = pos - 1;
        }

        if (key[pos] < search) {
            min_pos = pos + 1;
        }

        pos = (max_pos + min_pos) / 2;
    }

    if (key[pos] == search) {
        return pos;
    }

    return -1;
}

template<typename KeyType, typename ValueType>
void MyMap<KeyType, ValueType>::add_new(const KeyType &new_key, const ValueType &new_value) {
    KeyType *temp_key = new KeyType[size+1];
    ValueType *temp_val = new ValueType[size+1];

    size_t added(0);
    for (size_t i = 0; i < size; ++i) {
        if (added == 0 && key[i] > new_key) {
            added = 1;
            temp_key[i] = new_key;
            temp_val[i] = new_value;
        }
        temp_key[i + added] = key[i];
        temp_val[i + added] = value[i];
    }

    ++size;
    if (key != NULL) {
        delete[] key;
    }
    if (value != NULL) {
        delete[] value;
    }
    key = temp_key;
    value = temp_val;
}

template<typename KeyType, typename ValueType>
ValueType& MyMap<KeyType, ValueType>::operator[](const KeyType &search) {
    return at(search);
}

template<typename KeyType, typename ValueType>
ValueType& MyMap<KeyType, ValueType>::at(const KeyType &search) {
    int pos = binary_search(search);
    if (pos != -1) {
        return value[pos];
    }

    throw std::runtime_error("No key!");
}

}  // namespace vignere_coding
