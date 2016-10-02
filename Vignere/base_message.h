#ifndef VIGNOERE_BASE_MESSAGE_H
#define VIGNOERE_BASE_MESSAGE_H

#include <string>

namespace vignere_coding {
class BaseMessage {
protected:
    std::string message;

    explicit BaseMessage(const std::string& mess)
        : message(mess) {}

    void convert_to_uppercase() {
        const auto& diff_between_cases
                = 'A' - 'a';

        for (auto& letter : message) {
            if ('a' <= letter && letter <= 'z') {
                letter += diff_between_cases;
            }
        }
    }
};

}  // namespace vignere_coding

#endif // VIGNOERE_BASE_MESSAGE_H
