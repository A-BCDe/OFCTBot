#ifndef OFCT_MessageParser_action_hpp
#define OFCT_MessageParser_action_hpp

#include <stack>

#include "grammar.hpp"

namespace OFCT {
	namespace MessageParser {

		enum class PREOPTION {
			None = 0,
			help,
			info,
			roll,
			csat,
			daily,
			pay,
			slot,
			transfer,
			rankingm,
			rankingl,
			mission,
			missioninfo
		};

		using option_stack = std::stack<std::string>;

		template<typename Rule>
		struct message_parsing_action : tao::pegtl::nothing<Rule> {};

#define PREOPTION_ACTION(pref_) template<> \
struct message_parsing_action< preoption_##pref_ > { \
	static void apply0(PREOPTION& po, option_stack&) { \
		po = PREOPTION::##pref_ ; \
	} \
}
		PREOPTION_ACTION(help);
		PREOPTION_ACTION(info);
		PREOPTION_ACTION(roll);
		PREOPTION_ACTION(csat);
		PREOPTION_ACTION(daily);
		PREOPTION_ACTION(pay);
		PREOPTION_ACTION(slot);
		PREOPTION_ACTION(transfer);
		PREOPTION_ACTION(rankingm);
		PREOPTION_ACTION(rankingl);
		PREOPTION_ACTION(mission);
		PREOPTION_ACTION(missioninfo);

#undef PREOPTION_ACTION
		
		template<>
		struct message_parsing_action<param_help_preoption> {
			template<typename Input>
			static void apply(Input const& in, PREOPTION& po, option_stack& os) {
				assert(po == PREOPTION::help);
				assert(os.empty());
				os.push(in.string());
			}
		};

		template<>
		struct message_parsing_action<param_info_username> {
			template<typename Input>
			static void apply(Input const& in, PREOPTION& po, option_stack& os) {
				assert(po == PREOPTION::info);
				assert(os.empty());
				os.push(in.string());
			}
		};

		template<>
		struct message_parsing_action<param_roll_number> {
			template<typename Input>
			static void apply(Input const& in, PREOPTION& po, option_stack& os) {
				assert(po == PREOPTION::roll);
				assert(os.empty());
				os.push(in.string());
			}
		};

		template<>
		struct message_parsing_action<param_slot_bet> {
			template<typename Input>
			static void apply(Input const& in, PREOPTION& po, option_stack& os) {
				assert(po == PREOPTION::slot);
				assert(os.empty());
				os.push(in.string());
			}
		};

		template<>
		struct message_parsing_action<param_slot_times> {
			template<typename Input>
			static void apply(Input const& in, PREOPTION& po, option_stack& os) {
				assert(po == PREOPTION::slot);
				assert(os.size() == 1);
				os.push(in.string());
			}
		};

		template<>
		struct message_parsing_action<param_transfer_cost> {
			template<typename Input>
			static void apply(Input const& in, PREOPTION& po, option_stack& os) {
				assert(po == PREOPTION::transfer);
				assert(os.empty());
				os.push(in.string());
			}
		};

		template<>
		struct message_parsing_action<param_transfer_username> {
			template<typename Input>
			static void apply(Input const& in, PREOPTION& po, option_stack& os) {
				assert(po == PREOPTION::transfer);
				assert(os.size() == 1);
				os.push(in.string());
			}
		};

		template<>
		struct message_parsing_action<param_rankingm_top> {
			template<typename Input>
			static void apply(Input const& in, PREOPTION& po, option_stack& os) {
				assert(po == PREOPTION::rankingm);
				assert(os.empty());
				os.push(in.string());
			}
		};

		template<>
		struct message_parsing_action<param_rankingl_top> {
			template<typename Input>
			static void apply(Input const& in, PREOPTION& po, option_stack& os) {
				assert(po == PREOPTION::rankingl);
				assert(os.size() == 1);
				os.push(in.string());
			}
		};
	}
}

#endif