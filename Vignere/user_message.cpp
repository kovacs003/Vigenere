#include "user_message.h"
#include <iostream>

namespace vignere_coding {

constexpr char UserMessage::spec_prefix1;
constexpr char UserMessage::spec_prefix2;

void UserMessage::replace_localized_character() {
    for (size_t pos = 0; pos < message.get_length(); ++pos) {
        auto& letter = message.at(pos);
        if ((letter == spec_prefix1 || letter == spec_prefix2) &&
                pos < message.get_length() - 1) {
            auto& next_char = message.at(++pos);
            next_char = delocalization_table.at(next_char);
        }
    }
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
    //                     Á     á     É    é      Í    í      Ó     ó     Ö     ö     Ő     ő    Ú      ú     Ü     ü     Ű     ű
    const char spec[] = {0x81, 0xa1, 0x89, 0xa9, 0x8d, 0xad, 0x93, 0xb3, 0x96, 0xb6, 0x90, 0x91, 0x9a, 0xba, 0x9c, 0xbc, 0xb0, 0xb1};
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
