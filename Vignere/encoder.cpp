#include "encoder.h"
#include <stdexcept>

namespace vignere_coding {

Encoder::Encoder(const std::vector<std::string> &table) {
    size_t text_index = 0;
    size_t key_index = 0;

    for (const auto& line : table) {
        for (const auto& code : line) {
            coding_table[text_index][key_index++] = code;
        }
        ++text_index;
        key_index = 0;
    }
}

std::string Encoder::encode_message(const std::string &message, const std::string &keytext) {
    std::string coded_message;
    for (size_t pos = 0; pos < message.length(); ++pos) {
        size_t row_id = -1;
        for (row_id = 0; row_id < ABC_LENGTH; row_id++) {
            if (coding_table[row_id][0] == message.at(pos)) {
                break;
            }
        }

        size_t col_id = -1;
        for (col_id = 0; col_id < ABC_LENGTH; col_id++) {
            if (coding_table[0][col_id] == keytext.at(pos)) {
                break;
            }
        }
        coded_message.push_back(coding_table[row_id][col_id]);

    }
    return coded_message;
}

}  // namespace vignere_coding
