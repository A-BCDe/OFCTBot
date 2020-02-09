#ifndef OFCT_ofct_bot_hpp
#define OFCT_ofct_bot_hpp

#include <random>
#include <string_view>

#include "error.hpp"
#include "sleepy_discord/websocketpp_websocket.h"

namespace OFCT {
    class ofct_bot : public SleepyDiscord::DiscordClient {
        static constexpr char* prefix = "!";
        SleepyDiscord::Message help(SleepyDiscord::Message const&);
        SleepyDiscord::Message help(SleepyDiscord::Message const&, std::string_view);
        SleepyDiscord::Message roll(SleepyDiscord::Message const&, unsigned long long);
        SleepyDiscord::Message log(SleepyDiscord::Message const&);

        std::vector<std::string_view> parse(std::string const& input);
    public:
        using SleepyDiscord::DiscordClient::DiscordClient;
        void onMessage(SleepyDiscord::Message message) override;
    };
}

#endif