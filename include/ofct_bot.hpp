#ifndef OFCT_ofct_bot_hpp
#define OFCT_ofct_bot_hpp

#include <chrono>
#include <random>
#include <string_view>

#include "error.hpp"
#include "sleepy_discord/websocketpp_websocket.h"
#include "BotInfoParser/action.hpp"
#include "MessageParser/action.hpp"

namespace OFCT {
	class ofct_bot : public SleepyDiscord::DiscordClient {
		std::string_view server_id;
		std::string_view admin_id;
		std::string_view prefix;
		BotInfoParser::Config config;

#define _COMMAND(preop) SleepyDiscord::Message \
	_##preop(SleepyDiscord::Message const& message, OFCT::MessageParser::option_stack &os)

		_COMMAND(help);
		_COMMAND(info);
		_COMMAND(roll);
		_COMMAND(csat);
		_COMMAND(daily);
		_COMMAND(pay);
		_COMMAND(slot);
		_COMMAND(transfer);
		_COMMAND(rankingm);
		_COMMAND(rankingl);
		_COMMAND(mission);
		_COMMAND(missioninfo);

#undef _COMMAND
		SleepyDiscord::Message echo(SleepyDiscord::Message const&);
		SleepyDiscord::Message log(SleepyDiscord::Message const&);

		bool parse(SleepyDiscord::Message const& message);

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