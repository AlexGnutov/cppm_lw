cmake_minimum_required(VERSION 3.23.0)
project(racesim LANGUAGES CXX)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

add_library(racesimlib SHARED)
target_include_directories(racesimlib PRIVATE "{PROJECT_SOURCE_DIR}")
add_subdirectory("race_sim_lib")

add_executable(racesimapp)
target_sources(racesimapp PRIVATE "race_sim_app/main.cpp")
target_link_libraries(racesimapp PRIVATE racesimlib)

install(TARGETS racesimlib FILE_SET HEADERS)
