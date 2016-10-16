#include <iostream>
#include "encoder.h"
#include "file_handler.h"
#include "user_keyword.h"
#include "user_message.h"

using namespace vignere_coding;

int main(int , char*[]) {
    char read_text[256];

    std::cout << "Kerem a nyilt szoveget (max. 255 karakter): " << std::endl;
    if (fgets(read_text, 255, stdin) == NULL) {
        std::cout << "Érvenytelen szöveg!" << std::endl;
        return 1;
    }

    const MyString str(read_text);
    UserMessage user_text(str);
    const MyString& open_text = user_text.get_message();
    std::cout << "Az átalakított üzenet: " << std::endl
              << open_text.get_str() << std::endl;

    std::cout << "Kérem a kulcsszót (max. 5 karakter): " << std::endl;
    if (fgets(read_text, 6, stdin) == NULL) {
        std::cout << "Érvenytelen szöveg!" << std::endl;
        return 1;
    }

    const MyString str2(read_text);
    UserKeyword key(str2);
    const auto& full_length = user_text.get_length();
    const MyString& keytext = key.get_with_length(full_length);
    std::cout << "A kulcsszöveg: " << std::endl
              << keytext.get_content() << std::endl;


    try {
        MyContainer<MyString> coding_file
                = FileHandler::get_instance().read_from_file("input/vtabla.dat");
        Encoder coder(coding_file);

        const MyString& coded_message
                = coder.encode_message(open_text, keytext);

        std::cout << "Kódolt szöveg: " << std::endl << coded_message.get_content() << std::endl;
        FileHandler::get_instance().write_to_file("output/kodolt.dat", coded_message);
    }
    catch (std::runtime_error& ex) {
        std::cerr << "Hiba: " << ex.what() << std::endl;
    }
    catch (std::out_of_range& ex) {
        std::cerr << "Nem lehet titkosítani az üzenetet!" << std::endl;
    }

    return 0;
}
