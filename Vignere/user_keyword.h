#ifndef VIGNOERE_USER_KEYWORD_H
#define VIGNOERE_USER_KEYWORD_H

#include "base_message.h"

namespace vignere_coding {

class UserKeyword : public BaseMessage{
public:
    explicit UserKeyword(const std::string& mess);

    std::string get_with_length();
    std::string get_with_length(const size_t& size);
};

}  // namespace vignere_coding

#endif // VIGNOERE_USER_KEYWORD_H
