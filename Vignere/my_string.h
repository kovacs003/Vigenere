#ifndef VIGNOERE_MY_STRING_H
#define VIGNOERE_MY_STRING_H

#include "my_container.h"
#include <stdexcept>

namespace vignere_coding {

class MyString : public MyContainer<char> {
    void remove_string_end();
    void add_string_end();

public:
    MyString();

    template<size_t T>
    MyString(const char (&str)[T])
        : MyContainer<char>(T) {
        size_t pos(0);
        for (; pos < T && str[pos] != '\0' && str[pos] != '\n' && str[pos] != '\r'; ++pos) {
            container[pos] = str[pos];
        }
        size = pos;
        add_string_end();
    }

    MyString(char *&str, const size_t& len);

    void push_back(const char& elem) override;

    size_t get_length() const noexcept;
    const char* get_str() const noexcept;
};

}  // namespace vignere_coding

#endif // VIGNOERE_MY_STRING_H
