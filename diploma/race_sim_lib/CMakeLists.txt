target_sources(racesimlib
        PRIVATE
        race.cpp
        air_race.cpp
        ground_race.cpp
        combined_race.cpp

        vehicle.h vehicle.cpp

        air_vehicle.h
        eagle.h eagle.cpp
        broom.h broom.cpp
        teppich_jet.h teppich_jet.cpp

        ground_vehicle.h ground_vehicle.cpp
        offroad_shoes.h offroad_shoes.cpp
        camel.h camel.cpp
        kentavr.h kentavr.cpp
        super_camel.h super_camel.cpp
        PUBLIC FILE_SET HEADERS
        BASE_DIRS ${PROJECT_SOURCE_DIR}
        FILES
        race.h
        air_race.h
        ground_race.h
        combined_race.h
)