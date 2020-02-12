cmake_minimum_required(VERSION 3.10.2)
project(OFCTBot_ver2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(sleepy-discord)

set(PEGTL_BUILD_EXAMPLES OFF CACHE BOOL "Nope" FORCE)
set(PEGTL_BUILD_TESTS OFF CACHE BOOL "Nope" FORCE)

add_subdirectory(PEGTL)


add_executable(
    ${PROJECT_NAME}
    main.cpp

    # bot
    include/error.hpp
    include/ofct_bot.hpp
    src/ofct_bot.cpp

    # BotInfo parsing
    include/BotInfoParser/grammar.hpp
    include/BotInfoParser/action.hpp
)

target_link_libraries(${PROJECT_NAME}
    LINK_PUBLIC sleepy-discord
    LINK_PUBLIC taocpp::pegtl
)
