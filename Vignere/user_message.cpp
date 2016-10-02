#include "user_message.h"
#include <iostream>
namespace vignere_coding {

void UserMessage::replace_localized_character() {
    for (auto& letter : message) {
        if (delocalization_table.count(letter) > 0) {
            letter = delocalization_table.at(letter);
        }
    }
}

void UserMessage::remove_invalid_characters() {
    std::string filtered_message;
    for(auto it = message.cbegin(); it != message.cend(); ++it) {
        if (is_alpha(*it)) {
            filtered_message.push_back(*it);
        }
    }
    message.swap(filtered_message);
}

UserMessage::UserMessage(const std::string &mess)
    : BaseMessage(mess) {
    replace_localized_character();
    remove_invalid_characters();
    convert_to_uppercase();
}

std::string UserMessage::get_message() const {
    return message;
}

int UserMessage::get_length() const {
    return message.length();
}

}  // namespace vignere_coding
