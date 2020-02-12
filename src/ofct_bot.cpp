#include "../include/ofct_bot.hpp"

#include <iostream>

namespace OFCT {
	SleepyDiscord::Message ofct_bot::help(SleepyDiscord::Message const& message) {
		return sendMessage(message.channelID, "Hello! This is OFCTBot from help. You must be " + message.author.username + ".");
	}
	SleepyDiscord::Message ofct_bot::help(SleepyDiscord::Message const& message, std::string_view about) {
		return sendMessage(message.channelID, "Hello! This is OFCTBot from help applied. You must be " + message.author.username + ".");
	}

	SleepyDiscord::Message ofct_bot::roll(SleepyDiscord::Message const& message, unsigned long long face) {
		return sendMessage(message.channelID, "Hello! This is OFCTBot from roll. You must be " + message.author.username + ".");
	}

	SleepyDiscord::Message ofct_bot::echo(SleepyDiscord::Message const& message) {
		assert(!message.author.bot);
		return sendMessage(message.channelID, message.author.username + "#" + message.author.discriminator +" : " + message.content);
	}

	SleepyDiscord::Message ofct_bot::log(SleepyDiscord::Message const& message) {
		return sendMessage(message.channelID, "Hello! This is OFCTBot from log. You must be " + message.author.username + ".");
	}

	void ofct_bot::parse(SleepyDiscord::Message const& message) {
		// test
		if (!message.author.bot) echo(message);
		return;
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