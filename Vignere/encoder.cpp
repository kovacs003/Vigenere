#include "encoder.h"
#include <stdexcept>

namespace vignere_coding {

Encoder::Encoder(const MyContainer<MyString> &table) {
    size_t text_index = 0;
    size_t key_index = 0;

    for (size_t pos = 0; pos < table.get_size(); ++pos) {
        const auto& line = table.at(pos);
        for (size_t loop = 0; loop < line.get_size(); ++loop) {
            const auto& code = line.at(loop);
            coding_table[text_index][key_index++] = code;
        }
        ++text_index;
        key_index = 0;
    }
}

MyString Encoder::encode_message(const MyString &message, const MyString &keytext) {
    MyString coded_message;
    for (size_t pos = 0; pos < message.get_size(); ++pos) {
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
