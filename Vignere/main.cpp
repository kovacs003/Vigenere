#include <cstdio>
#include <iostream>
#include "encoder.h"
#include "file_handler.h"
#include "user_keyword.h"
#include "user_message.h"


int main(int , char*[]) {
    char read_text[256];

    std::cout << "Kerem a nyilt szoveget (max. 255 karakter): " << std::endl;
    if (fgets(read_text, 255, stdin) == NULL) {
        std::cout << "Érvenytelen szöveg!" << std::endl;
        return 1;
    }

    vignere_coding::UserMessage text(read_text);
    const std::string& open_text = text.get_message();
    std::cout << "Az átalakított üzenet:" << std::endl
              << open_text << std::endl;

    std::cout << "Kérem a kulcsszót (max. 5 karakter): " << std::endl;
    if (fgets(read_text, 6, stdin) == NULL) {
        std::cout << "Érvenytelen szöveg!" << std::endl;
        return 1;
    }

    vignere_coding::UserKeyword key(read_text);
    const std::string& keytext = key.get_with_length(text.get_length());
    std::cout << "A kulcsszöveg:" << std::endl
              << keytext << std::endl;


    try {
        std::vector<std::string> coding_file
                = vignere_coding::FileHandler::get_instance().read_from_file("input/vtabla.dat");
        vignere_coding::Encoder coder(coding_file);

        const std::string& coded_message
                = coder.encode_message(open_text, keytext);

        std::cout << "Kódolt szöveg: " << std::endl << coded_message << std::endl;
        vignere_coding::FileHandler::get_instance().write_to_file("output/kodolt.dat", coded_message);
    }
    catch (std::runtime_error& ex) {
        std::cerr << "Hiba: " << ex.what() << std::endl;
    }
    catch (std::out_of_range& ex) {
        std::cerr << "Nem lehet titkosítani az üzenetet!" << std::endl;
    }

    return 0;
}
