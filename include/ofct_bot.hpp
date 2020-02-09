#ifndef OFCT_ofct_bot_hpp
#define OFCT_ofct_bot_hpp

#include "error.hpp"
#include "sleepy_discord/websocketpp_websocket.h"

namespace OFCT {
    class ofct_bot : public SleepyDiscord::DiscordClient {
    public:
        using SleepyDiscord::DiscordClient::DiscordClient;
        void onMessage(SleepyDiscord::Message message) override {
            if (message.startsWith("!help"))
                sendMessage(message.channelID, "Hello! This is OFCTBot. You must be " + message.author.username + ".");
        }
    };
}

#endif