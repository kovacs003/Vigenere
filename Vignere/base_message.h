#ifndef VIGNOERE_BASE_MESSAGE_H
#define VIGNOERE_BASE_MESSAGE_H

#include "my_string.h"

namespace vignere_coding {
class BaseMessage {
protected:
    MyString message;

public:
    explicit BaseMessage(const MyString& mess)
        : message(mess) {}

    virtual ~BaseMessage() = default;

    void convert_to_uppercase() {
        const auto& diff_between_cases
                = 'A' - 'a';

        for (size_t loop = 0; loop < message.get_size(); ++loop) {
            auto& letter = message[loop];
            if ('a' <= letter && letter <= 'z') {
                letter += diff_between_cases;
            }
        }
    }
};

}  // namespace vignere_coding

#endif // VIGNOERE_BASE_MESSAGE_H
