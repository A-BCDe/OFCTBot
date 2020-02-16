#ifndef OFCT_User_user_base_hpp
#define OFCT_User_user_base_hpp

#include <string>

#include "sleepy_discord/websocketpp_websocket.h"

namespace OFCT {
	namespace User {
		template<bool bot>
		class user_base {
			SleepyDiscord::Snowflake id;
			static constexpr bool is_bot = bot;
			std::string username;

		};
	}
}

#endif