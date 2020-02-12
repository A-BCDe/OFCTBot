#ifndef OFCT_BotInfoParser_action_hpp
#define OFCT_BotInfoParser_action_hpp

#include <iostream>
#include <map>
#include <string>

#include "grammar.hpp"

namespace OFCT {
	namespace BotInfoParser {
		enum class Field {
			None = 0,
			AdminID,
			BotToken,
			ServerID,
			Config,
			Prefix
		};

		enum class Config {
			None = 0,
			Debug,
			Log
		};

		using FieldMap = std::map<Field, std::string>;

		template<typename Rule>
		struct bot_parsing_action : tao::pegtl::nothing<Rule> {};

		template<>
		struct bot_parsing_action<option_AdminID> {
			static void apply0(Field& option, FieldMap&) {
				option = Field::AdminID;
				std::cout << "AdminID : ";
			}
		};

		template<>
		struct bot_parsing_action<option_BotToken> {
			static void apply0(Field& option, FieldMap&) {
				option = Field::BotToken;
				std::cout << "BotToken : ";
			}
		};

		template<>
		struct bot_parsing_action<option_ServerID> {
			static void apply0(Field& option, FieldMap&) {
				option = Field::ServerID;
				std::cout << "ServerID : ";
			}
		};

		template<>
		struct bot_parsing_action<option_Config> {
			static void apply0(Field& option, FieldMap&) {
				option = Field::Config;
				std::cout << "Config : ";
			}
		};
		
		template<>
		struct bot_parsing_action<option_Prefix> {
			static void apply0(Field& option, FieldMap&) {
				option = Field::Prefix;
				std::cout << "Prefix : ";
			}
		};

		template<>
		struct bot_parsing_action<info_ID_Token> {
			template<typename Input>
			static void apply(Input const& in, Field& option, FieldMap& fm) {
				assert(option == Field::AdminID || option == Field::BotToken || option == Field::ServerID);
				fm[option] = in.string();
				std::cout << in.string() << std::endl;
			}
		};

		template<>
		struct bot_parsing_action<info_Config> {
			template<typename Input>
			static void apply(Input const& in, Field& option, FieldMap& fm) {
				assert(option == Field::Config);
				fm[option] = in.string();
				std::cout << in.string() << std::endl;
			}
		};

		template<>
		struct bot_parsing_action<info_Prefix> {
			template<typename Input>
			static void apply(Input const& in, Field& option, FieldMap& fm) {
				assert(option == Field::Prefix);
				fm[option] = in.string();
				std::cout << in.string() << std::endl;
			}
		};

		template<>
		struct bot_parsing_action<grammar> {
			static void apply0(Field&, FieldMap& fm) {
				std::cout << "Parsing complete!" << std::endl;
			}
		};
	}
}

#endif