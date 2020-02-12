#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "sleepy_discord/websocketpp_websocket.h"
#include "include/ofct_bot.hpp"
#include "include/BotInfoParser/action.hpp"

ERROR_ENUM get_info_from_file(std::string& bot_token, std::string& server_id, std::string& admin_id, std::string &prefix, OFCT::BotInfoParser::Config& config, std::string const& file_path = "../_BotInfo") {
	using namespace OFCT::BotInfoParser;

	// Get from _BotInfo
	std::string in_file;
	std::ifstream file(file_path);
	if(!file) {
		std::cerr << "Couldn't find path " << file_path << std::endl;
		return ERROR_ENUM::NO_FILE_EXISTS_ERROR;
	}
	file.seekg(0, std::ios::end);
	in_file.resize(file.tellg());
	file.seekg(0, std::ios::beg);
	file.read(&in_file[0], in_file.size());
	file.close();

	// Parse _BotInfo
	Field field;
	FieldMap fm;
	Config cfg;
	
	tao::pegtl::memory_input in(in_file, "");
	if (!tao::pegtl::parse<grammar, bot_parsing_action>(in, field, fm)) {
		return ERROR_ENUM::BOTINFO_FILE_PARSING_ERROR;
	}

	// Done parsing _BotInfo

	if ((bot_token = fm[Field::BotToken]) == "") {
		return ERROR_ENUM::BOTTOKEN_UNDECLARED_ERROR;
	}
	server_id = fm[Field::ServerID];
	admin_id = fm[Field::AdminID];
	if (fm[Field::Config] == "None" || fm[Field::Config] == "") {
		config = Config::None;
	}
	else if (fm[Field::Config] == "Debug") {
		config = Config::Debug;
	}
	else if (fm[Field::Config] == "Log") {
		config = Config::Log;
	}
	prefix = fm[Field::Prefix];

	return ERROR_ENUM::NONE;
}

int main(int argc, char *argv[]) {

	using namespace OFCT::BotInfoParser;

	/* INITIALIZE */

	/* DO NOT MODIFY AFTER INITIALIZING THESE FOUR STRINGS */
	std::string bot_token;
	std::string server_id;
	std::string admin_id;
	std::string prefix;

	Config config = Config::None;

	if(argc < 2) {
		std::cout << "Using token in file '../_BotInfo'." << std::endl;
		int err;
		if(err = (int)get_info_from_file(bot_token, server_id, admin_id, prefix, config)) return err;
	}
	else {
		int err;
		if(strcmp(argv[1], "-f") == 0) {
			if(argc == 2) {
				std::string file_path;

				std::cout << "Enter the relative path of the info file : ";
				std::getline(std::cin, file_path);

				std::cout << "Getting info from " << file_path << "...\n";
				if(err = (int)get_info_from_file(bot_token, server_id, admin_id, prefix, config, file_path)) return err;
				std::cout << std::endl;
			}
			else {
				std::string const file_path = argv[2];

				std::cout << "Getting info from " << argv[2] << "...\n";
				if(err = (int)get_info_from_file(bot_token, server_id, admin_id, prefix, config, file_path)) return err;
				std::cout << std::endl;
			}
		}
		else if(strcmp(argv[1], "-t") == 0) {
			std::cout << "TOKEN ONLY MODE" << std::endl;
			if(argc == 2) {
				std::cout << "Enter the token : ";
				std::cin >> bot_token;
			}
			else {
				bot_token = argv[2];
			}
		}
		else {
			std::cerr << "No such flag exists." << std::endl;
			return (int)ERROR_ENUM::PROGRAM_OPTION_ERROR;
		}
	}

	/* END INITIALIZE */

	OFCT::ofct_bot client(bot_token, 2);
	client.initialize(server_id, admin_id, prefix, config);
	client.run();
}