#include "file_handler.h"
#include <cstdio>
#include <stdexcept>
#include <string>

namespace vignere_coding {

FileHandler& FileHandler::get_instance() {
    static FileHandler instance;
    return instance;
}

MyContainer<MyString> FileHandler::read_from_file(const char *file_name) {
    FILE *input_file;
    input_file = fopen(file_name, "r+");

    if (input_file == NULL) {
        throw std::runtime_error("Nem lehet megnyitni a " + std::string(file_name) + "fájlt!");
    }

    MyContainer<MyString> content;
    char line[256];

    while(fgets(line, 255, input_file) != NULL) {
        const MyString str(line);
        content.push_back(str);
    }

    fclose(input_file);
    return content;
}

void FileHandler::write_to_file(const char *file_name, const MyString &data) {
    FILE *output_file;
    output_file = fopen(file_name, "w");

    if (output_file == NULL) {
        throw std::runtime_error("Nem lehet megnyitni a " + std::string(file_name) + "fájlt!");
    }

    const char* str = data.get_str();
    fputs(str, output_file);

    fclose(output_file);
}


}  // namespace vignere_coding
