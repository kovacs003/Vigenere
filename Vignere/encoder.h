#ifndef VIGNOERE_ENCODER_H
#define VIGNOERE_ENCODER_H

#include <string>
#include <vector>

namespace vignere_coding {
static constexpr size_t ABC_LENGTH = 26;

class Encoder {
    char coding_table[ABC_LENGTH][ABC_LENGTH];

public:
    explicit Encoder(const std::vector<std::string>& table);

    std::string encode_message(const std::string& message, const std::string& keytext);
};

}  // namespace vignere_coding

#endif // VIGNOERE_ENCODER_H
