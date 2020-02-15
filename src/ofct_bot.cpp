#include "../include/ofct_bot.hpp"

#include <iostream>

namespace OFCT {

#define _COMMAND_FUNCTION_DEF(preop) SleepyDiscord::Message \
	ofct_bot::_##preop(SleepyDiscord::Message const& message, OFCT::MessageParser::option_stack& os)

	_COMMAND_FUNCTION_DEF(help) {
		if (os.empty()) {
			return sendMessage(message.channelID,
				std::string("This is OFCT Bot! Command prefix is ") + prefix.data() + ".\\n" +
				"The following are the commands:\\n" +
				"help : shows this message.\\n" +
				"help <command> : shows the help about the command.\\n"
				"info : shows your info.\\n" +
				"info <username> : shows the info about the specific user.\\n" +
				"roll : rolls a die with face 1 to 100.\\n" +
				"roll <number> : rolls a die with face 1 to <number>.\\n" +
				"csat : shows the time left until College SAT.\\n" +
				"daily : gives you the daily experience (20).\\n" +
				"pay : withdraws all the money from your account.\\n" +
				"slot <bet> <times> : rolls a slot machine for a given bet for a given number of times.\\n" +
				"transfer <amount> <username> : give away given amount of money to the specific user from your account.\\n" +
				"rankingm : shows the rank of money in the account of 9 users near you.\\n" +
				"rankingm top : shows the top 9 ranking of money of users.\\n" +
				"rankingl : shows the rank of experience of 9 users near you.\\n" +
				"rankingl top : shows the top 9 ranking of experience of users.\\n" +
				"mission : analyzes your recent play within 24 hours and gives you the experience in the mission period.\\n" +
				"missioninfo : shows the progress of your mission.\\n"
			);
		}
		else {
			assert(os.size() == 1);
			auto const cmd = os.top(); os.pop();
			if (cmd == "help") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "help [command]\\n" +
					"The command shows the usage of which commands are available." +
					"If you additionally add the [command] next to the command, the message of how to use the command will appear."
				);
			}
			else if (cmd == "info") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "info [username]\\n" +
					"The command shows the info of you or the user mentioned, such as experience, etc.."
				);
			}
			else if (cmd == "roll") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "roll [number]\\n" +
					"The command rolls the die with faces 1 to the given number.\\n" +
					"Default number is 100."
				);
			}
			else if (cmd == "csat") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "csat\\n" +
					"The command shows the date left until the College SAT."
				);
			}
			else if (cmd == "daily") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "daily\\n" +
					"The command gives you the experience."
				);
			}
			else if (cmd == "pay") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "pay\\n" +
					"The command withdraws the money from your account for you."
				);
			}
			else if (cmd == "slot") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "slot <bet> <times>\\n" +
					"The command runs a slot machine for a given amount of times with a given bet from your account."
				);
			}
			else if (cmd == "transfer") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "transfer <amount> <username>\\n" +
					"The command sends your money to other user."
				);
			}
			else if (cmd == "rankingm") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "rankingm (top)\\n" +
					"The command shows your money ranking and 8 more users near you.\\n" +
					"If you add \'top\', then the command will show top 9 users."
				);
			}
			else if (cmd == "rankingl") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "rankingl (top)\\n" +
					"The command shows your experience ranking and 8 more users near you.\\n" +
					"If you add \'top\', then the command will show top 9 users."
				);
			}
			else if (cmd == "mission") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "mission\\n" +
					"The command analyzes your recent(~24h) play to give you experience in the mission period."
				);
			}
			else if (cmd == "missioninfo") {
				return sendMessage(message.channelID,
					std::string("Usage : ") + prefix.data() + "missioninfo\\n" +
					"The command shows the progress of your mission."
				);
			}
			return sendMessage(message.channelID, "You called help, but something unexpected happened!");
		}
	}
	_COMMAND_FUNCTION_DEF(info) {
		return sendMessage(message.channelID, "You called info!");
	}
	_COMMAND_FUNCTION_DEF(roll) {
		return sendMessage(message.channelID, "You called roll!");
	}
	_COMMAND_FUNCTION_DEF(csat) {
		return sendMessage(message.channelID, "You called csat!");
	}
	_COMMAND_FUNCTION_DEF(daily) {
		return sendMessage(message.channelID, "You called daily!");
	}
	_COMMAND_FUNCTION_DEF(pay) {
		return sendMessage(message.channelID, "You called pay!");
	}
	_COMMAND_FUNCTION_DEF(slot) {
		return sendMessage(message.channelID, "You called slot!");
	}
	_COMMAND_FUNCTION_DEF(transfer) {
		return sendMessage(message.channelID, "You called transfer!");
	}
	_COMMAND_FUNCTION_DEF(rankingm) {
		return sendMessage(message.channelID, "You called rankingm!");
	}
	_COMMAND_FUNCTION_DEF(rankingl) {
		return sendMessage(message.channelID, "You called rankingl!");
	}
	_COMMAND_FUNCTION_DEF(mission) {
		return sendMessage(message.channelID, "You called mission!");
	}
	_COMMAND_FUNCTION_DEF(missioninfo) {
		return sendMessage(message.channelID, "You called missioninfo!");
	}

#undef _COMMAND_FUNCTION_DEF

	SleepyDiscord::Message ofct_bot::echo(SleepyDiscord::Message const& message) {
		assert(!message.author.bot);
		return sendMessage(message.channelID, message.author.username + "#" + message.author.discriminator +" : " + message.content);
	}

	SleepyDiscord::Message ofct_bot::log(SleepyDiscord::Message const& message) {
		return sendMessage(message.channelID, "Hello! This is OFCTBot from log. You must be " + message.author.username + ".");
	}

	bool ofct_bot::parse(SleepyDiscord::Message const& message) {
		assert(message.startsWith(prefix.data()));

		// test
		if (!message.author.bot) echo(message);
		std::string s = message.content.substr(prefix.length());
		
		if (config != OFCT::BotInfoParser::Config::None) {
			std::cout << message.author.username + " :\n" + message.content << std::endl;
		}

		std::string const input = [&message]() {
			auto const& msg = message.content;
			int i=msg.length() - 1;
			for (; msg[i] == ' ' || msg[i] == '\n'; i--);
			return msg.substr(1, i);
		}();

		using OFCT::MessageParser::PREOPTION;
		using OFCT::MessageParser::option_stack;

		PREOPTION po = PREOPTION::None;
		option_stack os;

		tao::pegtl::memory_input in(input, "");
		if (!tao::pegtl::parse<OFCT::MessageParser::grammar, OFCT::MessageParser::message_parsing_action>(in, po, os)) {
			return false;
		}

		switch (po) {
#define _CASE(preop) case PREOPTION::##preop: _##preop(message, os); break
			_CASE(help);
			_CASE(info);
			_CASE(roll);
			_CASE(csat);
			_CASE(daily);
			_CASE(pay);
			_CASE(slot);
			_CASE(transfer);
			_CASE(rankingm);
			_CASE(rankingl);
			_CASE(mission);
			_CASE(missioninfo);
#undef _CASE
		default:
			return false;
		}

		return true;
	}

	void ofct_bot::initialize(std::string const& server_id, std::string const& admin_id, std::string const& prefix, BotInfoParser::Config config) {
		std::cout << (this->server_id = server_id) << std::endl;
		std::cout << (this->admin_id = admin_id) << std::endl;
		std::cout << (this->prefix = prefix) << std::endl;
		std::cout << (int)(this->config = config) << std::endl;
	}

	void ofct_bot::onMessage(SleepyDiscord::Message message) {
		// Check if the message starts with prefix.
		if (!message.startsWith(prefix.data())) return;

		parse(message);
	}

	void ofct_bot::onServer(SleepyDiscord::Server server) {
		std::cout << "Connecting to " << server.name << ": " << server.ID.string() << " ..." << std::endl;

		// TEST
		// Currently supports one server per program only
		try {
			// server ID should not be explicitly shown in the code.
			if (server.ID.string() == server_id) {
				std::cout << "Correct server. Welcome!\n";
			}
			else if (server_id == "") {
				std::cout << "Server not set. We recommend you to set server ID.\n";
			}
			else {
				std::cout << "Not connecting.\n";
				quit();
				return;
			}
			for (auto const& channel : server.channels) {
				if (channel.type == SleepyDiscord::Channel::ChannelType::SERVER_TEXT) {
					sendMessage(channel, "boo!");
				}
			}
		}
		catch (std::exception & e) {
			std::cout << "Failed to connect!\n";
			std::cout << e.what() << std::endl;
			return;
		}
	}
}