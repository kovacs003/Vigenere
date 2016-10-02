#ifndef VIGNOERE_FILE_HANDLER_H
#define VIGNOERE_FILE_HANDLER_H

#include <string>
#include <vector>

namespace vignere_coding {

class FileHandler {
public:
    FileHandler(const FileHandler&) = delete;
    FileHandler(FileHandler&&) = delete;

    static FileHandler& get_instance();

    std::vector<std::string> read_from_file(const std::string& file_name);
    void write_to_file(const std::string& file_name, const std::string& data);

private:
    FileHandler() = default;
};

}  // namespace vignere_coding

#endif // VIGNOERE_FILE_HANDLER_H
