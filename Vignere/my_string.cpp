#include "my_string.h"

namespace vignere_coding {

MyString::MyString()
    : MyContainer() {
    add_string_end();
}

MyString::MyString(char*& str, const size_t& len)
    : MyContainer() {
      container = str;
      capacity = len;
      size = len;
      add_string_end();
}

void MyString::push_back(const char &elem) {
    remove_string_end();
    MyContainer::push_back(elem);
    add_string_end();
}

size_t MyString::get_length() const noexcept {
    return size-1;
}

const char* MyString::get_str() const noexcept {
    return container;
}

void MyString::remove_string_end() {
    --size;
}

void MyString::add_string_end() {
    MyContainer::push_back('\0');
}

}  // namespace vignere_coding
