#pragma once

#include <string>

#include "enums.h"
#include "vehicle.h"
#include "vehicle_collection.h"

//! Класс Гонка - базовый класс для гонок конкретных типов.
class Race {
public:
	Race(std::string name) :name(name) {}

	//! Возвразщает список доступных к выбору участников. 
	std::string get_racers_selection();

	//! Возвращает информацию о гонке.
	std::string get_race_info();

	//! Устанавливает дистацию гонки.
	void set_distance(double value);

	//! Отмечает тип ТС к участию.
	bool set_racer(int index);

	//! Проверяет, можно ли стартовать.
	bool is_ready();

	//! Запускает гонку и возвращает результат.
	std::string run();

	std::string name;		///< Название гонки.
	double distance = 0;	///< Дистанция.

	int num_of_racers = 0;			///< Число возможных участников (доступных видов ТС).
	Vehicle** racers = nullptr;		///< Массив указателей на объекты-участники.
	int* set_flags = nullptr;		///< Массив с отметкой об участии типа ТС.
};

