#include <iostream>
#include <string>
#include <sstream>

#include "race_sim_lib/race.h"
#include "race_sim_lib/air_race.h"
#include "race_sim_lib/ground_race.h"
#include "race_sim_lib/combined_race.h"


enum class RaceType {
	ground,
	air,
	combined
};

std::string get_greeting() {
	std::stringstream ss;
	ss << "Добро пожаловать в симулятор гонок!" << std::endl;
	return ss.str();
};

std::string get_race_selection()
{
	std::stringstream ss;
	ss << "1. Гонка для наземного транспорта" << std::endl;
	ss << "2. Гонка для воздушного транспорта" << std::endl;
	ss << "3. Гонка для наземного и воздушного транспорта" << std::endl;
	ss << "Выберите тип гонки: ";
	return ss.str();
}

std::string get_distance()
{
	std::stringstream ss;
	ss << "Укажите дистанцию гонки: ";
	return ss.str();
}

std::string get_transport()
{
	std::stringstream ss;
	ss << "0. Закончить регистрацию" << std::endl;
	ss << "Выберите транспорт или введите 0 для завершения регистрации: ";
	return ss.str();
}

Race* race_factory(RaceType race_type)
{
	switch (race_type) {
	case RaceType::ground: {
		return new GroundRace();
	}
	case RaceType::air: {
		return new AirRace();
	}
	case RaceType::combined: {
		return new CombinedRace();
	}
	}
    return nullptr;
}

int main()
{

	setlocale(LC_ALL, "rus");

	RaceType race_type;
	double race_distance;

	std::cout << get_greeting();

	while (true) {

		// Выбор гонки
		std::cout << get_race_selection();
		int value; std::cin >> value;
		race_type = static_cast<RaceType>(value - 1);

		// Установка расстояния
		std::cout << get_distance();
		std::cin >> race_distance;
		std::cout << std::endl;

		Race* race = race_factory(race_type);
        if (race == nullptr) {
            std::cout << "Непредвиденная ошибка" << std::endl;
            return 1;
        }
		race->set_distance(race_distance);

		while (true) {

			if (!race->is_ready()) {
				std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
			}

			int selection = 0;
			std::cout << "1. Зарегистрировать транспорт" << std::endl;

			if (race->is_ready()) {
				std::cout << "2. Начать гонку" << std::endl;
			}

			std::cout << "Выберите действие:";
			std::cin >> selection;

			if (race->is_ready() && selection == 2) {
				break;
			}

			if (selection != 1) {
				continue;
			}

			while (true) {

				std::string racers_list = race->get_racers_selection();
				if (racers_list.length() == 0) {
					std::cout << "Зарегистрировано максимальное число участников." << std::endl;
					break;
				}

				std::cout << race->get_race_info() << std::endl;
				std::cout << racers_list;

				int selection = -1;
				std::cout << get_transport();
				std::cin >> selection;

				std::cout << std::endl;

				if (selection > 0 && selection <= race->num_of_racers) {
					race->set_racer(selection);
				}

				if (selection == 0) {
					break;
				}
			}
		}

		std::string result_text = race->run();

		std::cout << "Результаты гонки:" << std::endl;
		std::cout << result_text << std::endl;

		int decision;
		std::cout << "1. Провести ещё одну гонку" << std::endl;
		std::cout << "2. Выйти" << std::endl;
		std::cin >> decision;

		if (decision == 1) {
			continue;
		}

		break;
	}

	return 0;
}