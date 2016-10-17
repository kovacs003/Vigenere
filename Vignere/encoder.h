#ifndef VIGNOERE_ENCODER_H
#define VIGNOERE_ENCODER_H

#include "my_string.h"

namespace vignere_coding {
static constexpr size_t ABC_LENGTH = 26;

class Encoder {
    char coding_table[ABC_LENGTH][ABC_LENGTH];

public:
    explicit Encoder(const MyContainer<MyString>& table);

    MyString encode_message(const MyString& message, const MyString& keytext);
};

}  // namespace vignere_coding

#endif // VIGNOERE_ENCODER_H
