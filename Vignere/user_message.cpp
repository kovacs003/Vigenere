#include "user_message.h"
#include <iostream>

namespace vignere_coding {

void UserMessage::replace_localized_character() {
//    for (size_t pos = 0; pos < message.get_length(); ++pos) {
//        auto& letter = message.at(pos);
//            letter = delocalization_table.at(letter);
//    }
}

void UserMessage::remove_invalid_characters() {
    MyString filtered_message;
    for (size_t pos = 0; pos <= message.get_length(); ++pos) {
        if (is_alpha(message.at(pos))) {
            filtered_message.push_back(message.at(pos));
        }
    }
    message.swap(filtered_message);
}

UserMessage::UserMessage(const MyString &mess)
    : BaseMessage(mess) {
    const char spec[] = {'a', 'a', 'e', 'e', 'i', 'i', 'o', 'o', 'o', 'o', 'o', 'o', 'u', 'u', 'u', 'u', 'u', 'u'};
    //{'á', 'Á', 'é', 'É', 'í', 'Í', 'ó', 'Ó', 'ö', 'Ö', 'ő', 'Ő', 'ú', 'Ú', 'ü', 'Ü', 'ű', 'Ű'};
    const char norm[] = {'a', 'a', 'e', 'e', 'i', 'i', 'o', 'o', 'o', 'o', 'o', 'o', 'u', 'u', 'u', 'u', 'u', 'u'};
    delocalization_table.add_arrays(spec, norm);
    replace_localized_character();
    remove_invalid_characters();
    convert_to_uppercase();
}

const MyString& UserMessage::get_message() const {
    return message;
}

size_t UserMessage::get_length() const {
    return message.get_length();
}

}  // namespace vignere_coding
