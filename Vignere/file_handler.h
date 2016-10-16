#ifndef VIGNOERE_FILE_HANDLER_H
#define VIGNOERE_FILE_HANDLER_H

#include "my_string.h"

namespace vignere_coding {

class FileHandler {
public:
    FileHandler(const FileHandler&) = delete;
    FileHandler(FileHandler&&) = delete;

    static FileHandler& get_instance();

    MyContainer<MyString> read_from_file(const char *file_name);
    void write_to_file(const char *file_name, const MyString &data);

private:
    FileHandler() = default;
};

}  // namespace vignere_coding

#endif // VIGNOERE_FILE_HANDLER_H
