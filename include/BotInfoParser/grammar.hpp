#ifndef OFCT_BotInfoParser_grammar_hpp
#define OFCT_BotInfoParser_grammar_hpp

#include <tao/pegtl.hpp>

namespace OFCT {
	namespace BotInfoParser {
		namespace {
			struct digit : tao::pegtl::digit {};
			struct digits : tao::pegtl::plus<digit> {};
			struct space : tao::pegtl::space {};
			struct space_s : tao::pegtl::star<space> {};

			struct option_AdminID : tao::pegtl::string<'A', 'd', 'm', 'i', 'n', 'I', 'D'> {};
			struct option_BotToken : tao::pegtl::string<'B', 'o', 't', 'T', 'o', 'k', 'e', 'n'> {};
			struct option_Config : tao::pegtl::string<'C', 'o', 'n', 'f', 'i', 'g'> {};
			struct option_Prefix : tao::pegtl::string<'P', 'r', 'e', 'f', 'i', 'x'> {};
			struct option_ServerID : tao::pegtl::string<'S', 'e', 'r', 'v', 'e', 'r', 'I', 'D'> {};
			struct option_ID_Token : tao::pegtl::sor <
				option_AdminID,
				option_BotToken,
				option_ServerID
			> {};
			struct option : tao::pegtl::sor<
				option_AdminID,
				option_BotToken,
				option_Config,
				option_Prefix,
				option_ServerID
			> {};

			struct info_ID_Token : tao::pegtl::star<tao::pegtl::minus<tao::pegtl::any, tao::pegtl::sor<tao::pegtl::one<';'>, space>>> {};
			struct info_Config : tao::pegtl::seq<
				tao::pegtl::sor <
					tao::pegtl::string<'N', 'o', 'n', 'e'>,
					tao::pegtl::string<'D', 'e', 'b', 'u', 'g'>,
					tao::pegtl::string<'L', 'o', 'g'>
				>,
				tao::pegtl::at<tao::pegtl::sor<tao::pegtl::one<';'>, space>>
			> {};
			struct info_Prefix : tao::pegtl::plus<tao::pegtl::minus<tao::pegtl::any, tao::pegtl::seq<space_s, tao::pegtl::one<';'>, space_s, tao::pegtl::opt<option>>>> {};
			struct info : tao::pegtl::sor<info_ID_Token, info_Config> {};
			struct expression : tao::pegtl::sor <
				tao::pegtl::seq<option_ID_Token, space_s, tao::pegtl::one<'='>, space_s, info_ID_Token>,
				tao::pegtl::seq<option_Config, space_s, tao::pegtl::one<'='>, space_s, info_Config>,
				tao::pegtl::seq<option_Prefix, space_s, tao::pegtl::one<'='>, space_s, info_Prefix>
			> {};
		}
		struct grammar : tao::pegtl::seq<
			tao::pegtl::list<
				expression,
				tao::pegtl::seq<space_s, tao::pegtl::one<';'>, space_s>
			>,
			tao::pegtl::one<';'>,
			space_s,
			tao::pegtl::eolf
		> {};
	}
}

#endif