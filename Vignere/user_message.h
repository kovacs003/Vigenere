#ifndef VIGNERE_USER_MESSAGE_H
#define VIGNERE_USER_MESSAGE_H

#include "base_message.h"
#include "my_map.h"

namespace vignere_coding {

class UserMessage : public BaseMessage {
    void replace_localized_character();
    void remove_invalid_characters();
    MyMap<char, char> delocalization_table;

    inline bool is_alpha(const char& letter) const noexcept {
        return ('a' <= letter && letter <= 'z')
                    || ('A' <= letter && letter <= 'Z');
    }

public:
    explicit UserMessage(const MyString &mess);

    const MyString& get_message() const;
    size_t get_length() const;
};

}  // namespace vignere_coding

#endif // VIGNERE_USER_MESSAGE_H
