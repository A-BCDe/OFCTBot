#ifndef error_hpp
#define error_hpp

#include <cinttypes>

enum error_enum : int32_t {
    NONE = 0,
    OPTION_ERROR,
    NO_FILE_EXISTS_ERROR
};

#endif