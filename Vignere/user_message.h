#ifndef USER_MESSAGE_H
#define USER_MESSAGE_H

namespace vignere_coding {

#include <string>

class UserMessage {
    std::string message;
public:
    explicit UserMessage(const std::string &mess);
};

}  // namespace vignere_coding

#endif // USER_MESSAGE_H
