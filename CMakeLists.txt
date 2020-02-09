cmake_minimum_required(VERSION 3.14)
project(OFCTBot_ver2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(sleepy-discord)



add_executable(
    ${PROJECT_NAME}
    main.cpp
    include/error.hpp
    include/ofct_bot.hpp
)

target_link_libraries(${PROJECT_NAME} sleepy-discord)