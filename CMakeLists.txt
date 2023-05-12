cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(
    "JSON Beauty"
    VERSION 1.0.0
    DESCRIPTION "A simple command-line tool to beautify input stream"
)

add_executable(jb ./src/main.cpp)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(jb PRIVATE nlohmann_json::nlohmann_json)

set_property(TARGET jb PROPERTY CXX_STANDARD 20)

install(TARGETS jb)