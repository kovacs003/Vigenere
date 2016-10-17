#include "user_keyword.h"

namespace  vignere_coding {
UserKeyword::UserKeyword(const MyString& mess)
    : BaseMessage(mess) {
    convert_to_uppercase();
}

MyString UserKeyword::get_with_length() {
    return message;
}

MyString UserKeyword::get_with_length(const size_t &size) {
    char* extended_key = new char[size+1];
    const auto& len = message.get_length();
    for (size_t loop = 0; loop < size; ++loop) {
        extended_key[loop] = message.at(loop%len);
    }

    return MyString(extended_key, size);
}

} // namepsacevignere_coding
