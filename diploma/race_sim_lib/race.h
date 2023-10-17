#pragma once

#ifdef _WIN32
# ifdef LIBRARY_EXPORTS
#   define LIBRARY_API  __declspec( dllexport )
# else
#   define LIBRARY_API  __declspec( dllimport )
# endif
#else
# define LIBRARY_API
#endif

#include <string>
#include "enums.h"
#include "vehicle.h"
#include "vehicle_collection.h"

//! Класс Гонка - базовый класс для гонок конкретных типов.
class Race {
public:
    LIBRARY_API Race(std::string name) :name(name) {}

	//! Возвразщает список доступных к выбору участников. 
    LIBRARY_API std::string get_racers_selection();

	//! Возвращает информацию о гонке.
    LIBRARY_API std::string get_race_info();

	//! Устанавливает дистацию гонки.
    LIBRARY_API void set_distance(double value);

	//! Отмечает тип ТС к участию.
    LIBRARY_API bool set_racer(int index);

	//! Проверяет, можно ли стартовать.
    LIBRARY_API bool is_ready();

	//! Запускает гонку и возвращает результат.
    LIBRARY_API std::string run();

	std::string name;		///< Название гонки.
	double distance = 0;	///< Дистанция.

	int num_of_racers = 0;			///< Число возможных участников (доступных видов ТС).
	Vehicle** racers = nullptr;		///< Массив указателей на объекты-участники.
	int* set_flags = nullptr;		///< Массив с отметкой об участии типа ТС.
};

