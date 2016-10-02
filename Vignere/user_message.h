#ifndef VIGNOERE_USER_MESSAGE_H
#define VIGNOERE_USER_MESSAGE_H

#include <map>
#include "base_message.h"

namespace vignere_coding {

class UserMessage : public BaseMessage {
    void replace_localized_character();
    void remove_invalid_characters();
    const std::map<char, char> delocalization_table =
        {{'á', 'a'}, {'Á', 'a'},
         {'é', 'e'}, {'É', 'e'},
         {'í', 'i'}, {'Í', 'i'},
         {'ó', 'o'}, {'Ó', 'o'},
         {'ö', 'o'}, {'Ö', 'o'},
         {'ő', 'o'}, {'Ő', 'o'},
         {'ú', 'u'}, {'Ú', 'u'},
         {'ü', 'u'}, {'Ü', 'u'},
         {'ű', 'u'}, {'Ű', 'u'}};

    inline bool is_alpha(const char& letter) const noexcept {
        return ('a' <= letter && letter <= 'z')
                    || ('A' <= letter && letter <= 'Z');
    }

public:
    explicit UserMessage(const std::string &mess);

    std::string get_message() const;
    int get_length() const;
};

}  // namespace vignere_coding

#endif // VIGNOERE_USER_MESSAGE_H
