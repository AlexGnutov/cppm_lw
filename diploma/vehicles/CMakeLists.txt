cmake_minimum_required(VERSION 3.16.0)

project(race_app)

set(DIR vehicles)

set(LIBS 
air_race.cpp
air_race.h
air_vehicle.h
broom.cpp
broom.h
camel.cpp
camel.h
combined_race.cpp
combined_race.h
eagle.cpp
eagle.h
enums.h
ground_race.cpp
ground_race.h
ground_vehicle.cpp
ground_vehicle.h
kentavr.cpp
kentavr.h
main.cpp
offroad_shoes.cpp
offroad_shoes.h
race.cpp
race.h
super_camel.cpp
super_camel.h
teppich_jet.cpp
teppich_jet.h
vehicle.cpp
vehicle.h
vehicle_collection.cpp
vehicle_collection.h )

add_executable(race_app main.cpp ${LIBS})
