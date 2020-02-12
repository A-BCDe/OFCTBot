#ifndef OFCT_MessageParser_grammar_hpp
#define OFCT_MessageParser_grammar_hpp

#include <tao/pegtl.hpp>

namespace OFCT {
	namespace MessageParser {
		namespace {
			struct digit : tao::pegtl::digit {};
			struct digits : tao::pegtl::plus<digit> {};
			struct space : tao::pegtl::space {};
			struct spaces : tao::pegtl::plus<space> {};
			struct space_s : tao::pegtl::star<space> {};

			struct preoption_help : tao::pegtl::string<'h', 'e', 'l', 'p'> {};
			struct preoption_info : tao::pegtl::string<'i', 'n', 'f', 'o'> {};
			struct preoption_roll : tao::pegtl::string<'r', 'o', 'l', 'l'> {};
			struct preoption_csat : tao::pegtl::string<'c', 's', 'a', 't'> {};
			struct preoption_daily : tao::pegtl::string<'d', 'a', 'i', 'l', 'y'> {};
			struct preoption_pay : tao::pegtl::string<'p', 'a', 'y'> {};
			struct preoption_slot : tao::pegtl::string <'s', 'l', 'o', 't'> {};
			struct preoption_transfer : tao::pegtl::string<'t', 'r', 'a', 'n', 's', 'f', 'e', 'r'> {};
			struct preoption_rankingm : tao::pegtl::string<'r', 'a', 'n', 'k', 'i', 'n', 'g', 'm'> {};
			struct preoption_rankingl : tao::pegtl::string<'r', 'a', 'n', 'k', 'i', 'n', 'g', 'l'> {};
			struct preoption_mission : tao::pegtl::string<'m', 'i', 's', 's', 'i', 'o', 'n'> {};
			struct preoption_missioninfo : tao::pegtl::string<'m', 'i', 's', 's', 'i', 'o', 'n', 'i', 'n', 'f', 'o'> {};

			struct preoption : tao::pegtl::sor<
				preoption_help,
				preoption_info,
				preoption_roll,
				preoption_csat,
				preoption_daily,
				preoption_pay,
				preoption_slot,
				preoption_transfer,
				preoption_rankingm,
				preoption_rankingl,
				preoption_mission,
				preoption_missioninfo
			> {};

			struct param_help_preoption : tao::pegtl::disable<preoption> {};
			struct param_info_username : tao::pegtl::until<tao::pegtl::eolf> {};
			struct param_roll_number : digits {};
			struct param_slot_bet : digits {};
			struct param_slot_times : digits {};
			struct param_transfer_cost : digits {};
			struct param_transfer_username : tao::pegtl::until<tao::pegtl::eolf> {};
			struct param_rankingm_top : tao::pegtl::string<'t', 'o', 'p'> {};
			struct param_rankingl_top : tao::pegtl::string<'t', 'o', 'p'> {};

			struct cmd_help : tao::pegtl::seq<
				preoption_help,
				tao::pegtl::opt<param_help_preoption>
			> {};
			struct cmd_info : tao::pegtl::seq<
				preoption_info,
				tao::pegtl::opt<spaces, param_info_username>
			> {};
			struct cmd_roll : tao::pegtl::seq<
				preoption_roll,
				tao::pegtl::opt<spaces, digits>
			> {};
			struct cmd_csat : tao::pegtl::seq<preoption_csat> {};
			struct cmd_daily : tao::pegtl::seq<preoption_daily> {};
			struct cmd_pay : tao::pegtl::seq<preoption_pay> {};
			struct cmd_slot : tao::pegtl::seq<
				preoption_slot, spaces,
				param_slot_bet, spaces,
				param_slot_times
			> {};
			struct cmd_transfer : tao::pegtl::seq<
				preoption_transfer, spaces,
				param_transfer_cost, spaces,
				param_transfer_username
			> {};
			struct cmd_rankingm : tao::pegtl::seq<
				preoption_rankingm,
				tao::pegtl::opt<spaces, param_rankingm_top>
			> {};
			struct cmd_rankingl : tao::pegtl::seq<
				preoption_rankingl,
				tao::pegtl::opt<spaces, param_rankingl_top>
			> {};
			struct cmd_mission : tao::pegtl::seq<preoption_mission> {};
			struct cmd_missioninfo : tao::pegtl::seq<preoption_missioninfo> {};

			struct command : tao::pegtl::sor<
				cmd_help,
				cmd_info,
				cmd_roll,
				cmd_csat,
				cmd_daily,
				cmd_pay,
				cmd_slot,
				cmd_transfer,
				cmd_rankingm,
				cmd_rankingl,
				cmd_mission,
				cmd_missioninfo
			> {};
		}
		struct grammar : tao::pegtl::seq<command, tao::pegtl::until<tao::pegtl::eolf>> {};
	}
}

#endif