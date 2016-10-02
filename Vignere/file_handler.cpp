#include "file_handler.h"
#include <fstream>
#include <stdexcept>

namespace vignere_coding {

FileHandler& FileHandler::get_instance() {
    static FileHandler instance;
    return instance;
}

std::vector<std::string> FileHandler::read_from_file(const std::string &file_name) {
    std::ifstream file_stream(file_name);
    std::vector<std::string> content;
    std::string line;

    if (!file_stream.is_open()) {
        throw std::runtime_error("Nem lehet megnyitni a " + file_name + "fájlt!");
    }

    while(std::getline(file_stream, line)) {
        content.push_back(line);
    }

    file_stream.close();
    return content;
}

void FileHandler::write_to_file(const std::string &file_name, const std::string &data) {
    std::ofstream file_stream(file_name);

    if (!file_stream.is_open()) {
        throw std::runtime_error("Nem lehet megnyitni a " + file_name + "fájlt!");
    }

    file_stream << data;
    file_stream.close();
}


}  // namespace vignere_coding
