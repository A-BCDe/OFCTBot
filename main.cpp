#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "sleepy_discord/websocketpp_websocket.h"
#include "include/ofct_bot.hpp"

int32_t get_token_from_file(std::string &_token, std::string const &file_path = "../_BotToken.txt") {
    std::ifstream file(file_path);
    if(!file) {
        std::cerr << "Couldn't find path " << file_path << std::endl;
        return NO_FILE_EXISTS_ERROR;
    }
    file.seekg(0, std::ios::end);
    _token.resize(file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&_token[0], _token.size());
    file.close();
    return NONE;
}

int main(int argc, char *argv[]) {

    /* INITIALIZE */

    std::string _token;
    if(argc < 2) {
        std::cout << "Using token in file '../_BotInfo.txt'." << std::endl;
        int32_t err;
        if(err = get_token_from_file(_token)) return err;
    }
    else {
        int32_t err;
        if(strcmp(argv[1], "-f") == 0) {
            if(argc == 2) {
                std::string file_path;

                std::cout << "Enter the relative of the info file : ";
                std::getline(std::cin, file_path);

                std::cout << "Getting info from " << file_path << "...\n";
                if(err = get_token_from_file(_token, file_path)) return err;
                std::cout << std::endl;
            }
            else {
                std::string const file_path = argv[2];

                std::cout << "Getting info from " << argv[2] << "...\n";
                if(err = get_token_from_file(_token, file_path)) return err;
                std::cout << std::endl;
            }
        }
        else if(strcmp(argv[1], "-t") == 0) {
            std::cout << "TOKEN ONLY MODE" << std::endl;
            if(argc == 2) {
                std::cout << "Enter the token : ";
                std::cin >> _token;
            }
            else {
                _token = argv[2];
            }
        }
        else {
            std::cerr << "No such flag exists." << std::endl;
            return OPTION_ERROR;
        }
    }

    /* END INITIALIZE */

    OFCT::ofct_bot client(_token, 2);
	client.run();
}