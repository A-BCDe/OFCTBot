#include "../include/ofct_bot.hpp"

namespace OFCT {
	SleepyDiscord::Message ofct_bot::help(SleepyDiscord::Message const& message) {
		return sendMessage(message.channelID, "Hello! This is OFCTBot from help. You must be " + message.author.username + ".");
	}
	SleepyDiscord::Message ofct_bot::help(SleepyDiscord::Message const& message, std::string_view about) {
		return sendMessage(message.channelID, "Hello! This is OFCTBot from help applied. You must be " + message.author.username + ".");
	}

	SleepyDiscord::Message ofct_bot::roll(SleepyDiscord::Message const& message, unsigned long long face) {
		return sendMessage(message.channelID, "Hello! This is OFCTBot. You must be " + message.author.username + ".");
	}

	SleepyDiscord::Message ofct_bot::log(SleepyDiscord::Message const& message) {
		return sendMessage(message.channelID, "Hello! This is OFCTBot. You must be " + message.author.username + ".");
	}

	std::vector<std::string_view> ofct_bot::parse(std::string const& input) {
		return std::vector<std::string_view>();
	}

	void ofct_bot::onMessage(SleepyDiscord::Message message) {
		
		// Check if the message starts with prefix.
		if (!message.startsWith(prefix)) return;

		auto v = parse(message.content);
		
		// Check if the input has the right grammar
		if (v.empty()) return;

		SleepyDiscord::Message msg;

		if (v[0] == "help") {
			if (v.size() == 1) {
				msg = help(message);
			}
			else {
				msg = help(message, v[1]);
			}
		}
		
		
	}
}