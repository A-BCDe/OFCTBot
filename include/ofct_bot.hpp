#ifndef OFCT_ofct_bot_hpp
#define OFCT_ofct_bot_hpp

#include <random>
#include <string_view>

#include "error.hpp"
#include "sleepy_discord/websocketpp_websocket.h"
#include "BotInfoParser/action.hpp"

namespace OFCT {
	class ofct_bot : public SleepyDiscord::DiscordClient {
		std::string_view server_id;
		std::string_view admin_id;
		std::string_view prefix;
		BotInfoParser::Config config;

		SleepyDiscord::Message help(SleepyDiscord::Message const&);
		SleepyDiscord::Message help(SleepyDiscord::Message const&, std::string_view);
		SleepyDiscord::Message roll(SleepyDiscord::Message const&, unsigned long long);

		SleepyDiscord::Message echo(SleepyDiscord::Message const&);

		SleepyDiscord::Message log(SleepyDiscord::Message const&);

		void parse(SleepyDiscord::Message const& message);

	public:
		void initialize(std::string const& server_id, std::string const& admin_id, std::string const& prefix, BotInfoParser::Config config);

		using SleepyDiscord::DiscordClient::DiscordClient;
		// onReady is not implemented in the library properly yet.
		//void onReady(std::string* rawjson);
		void onServer(SleepyDiscord::Server server) override;
		void onMessage(SleepyDiscord::Message message) override;
	};
}

#endif