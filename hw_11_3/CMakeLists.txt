cmake_minimum_required(VERSION 3.22.0)

project(app)

include_directories(greeter leaver app)

add_library(greeter_lib STATIC greeter/greeter.h greeter/greeter.cpp)
add_library(leaver_lib SHARED leaver/leaver.h leaver/leaver.cpp)

add_executable(app app/main.cpp)

target_link_libraries(app greeter_lib leaver_lib)