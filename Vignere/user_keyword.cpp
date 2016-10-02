#include "user_keyword.h"

namespace  vignere_coding {
UserKeyword::UserKeyword(const std::string &mess)
    : BaseMessage(mess) {
    if (message.back() == '\n') {
        message.pop_back();
    }
    convert_to_uppercase();
}

std::string UserKeyword::get_with_length() {
    return get_with_length(message.length());
}

std::string UserKeyword::get_with_length(const size_t &size) {
    std::string extended_key = message;
    while (extended_key.length() < size) {
        extended_key.append(message);
    }
    while (extended_key.length() > size) {
        extended_key.pop_back();
    }

    return extended_key;
}

} // namepsacevignere_coding
