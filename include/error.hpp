#ifndef error_hpp
#define error_hpp

#include <cinttypes>

enum class ERROR_ENUM : int {
    NONE = 0,
    PROGRAM_OPTION_ERROR,
    NO_FILE_EXISTS_ERROR,
    BOTINFO_FILE_PARSING_ERROR,
    BOTTOKEN_UNDECLARED_ERROR,
    PREFIX_UNDECLARED_ERROR
};

#endif