#include "race.h"

#include <sstream>

void Race::set_distance(double value)
{
	this->distance = value;
}

std::string Race::get_racers_selection()
{
	std::stringstream ss;

	for (int i = 0; i < num_of_racers; ++i) {
		if (set_flags[i] == 0) {
			ss << (i + 1) << ". " << racers[i]->name << std::endl;
		}
	}
	return ss.str();
}

std::string Race::get_race_info()
{
	std::stringstream ss;

	ss << name << ".";
	ss << " Расстояние: " << distance << std::endl;

	std::string pre = "Зарегистрированы: ";

	for (int i = 0; i < num_of_racers; ++i) {
		if (set_flags[i] == 1) {
			ss << pre << racers[i]->name;
			pre = ", ";
		}
	}

	if (pre == ", ") {
		ss << std::endl;
	}

	return ss.str();
}

bool Race::set_racer(int index)
{
	--index;

	if (index < 0 || index >= num_of_racers) {
		return false;
	}
	set_flags[index] = 1;
	return true;
}

//! Проверяет, можно ли стартовать.
bool Race::is_ready()
{
	int sum = 0;
	for (int i = 0; i < num_of_racers; ++i) {
		if (set_flags[i] == 1) {
			sum += 1;
		}
	}
	return (sum >= 2);
}

//! Запускает гонку и возвращает результат.
std::string Race::run()
{
	double* race_results = new double[num_of_racers];

	for (int i = 0; i < num_of_racers; ++i) {
		if (set_flags[i] == 1) {
			race_results[i] = racers[i]->get_travel_time(distance);
		}
		else {
			race_results[i] = 0;
		}
	}

	// here we sort result
	int* sorted_idxs = new int[num_of_racers];
	for (int i = 0; i < num_of_racers; ++i) {
		sorted_idxs[i] = i;
	}

	for (int i = 0; i < num_of_racers; ++i) {

		double min = race_results[i];
		int idx = i;

		for (int k = i + 1; k < num_of_racers; ++k) {
			if (race_results[k] < min) {
				min = race_results[k];
				idx = k;
			}
		}

		if (idx != i) {
			double tmp = race_results[i];
			race_results[i] = race_results[idx];
			race_results[idx] = tmp;

			int tmp_idx = sorted_idxs[i];
			sorted_idxs[i] = sorted_idxs[idx];
			sorted_idxs[idx] = tmp_idx;
		}
	}

	std::stringstream ss;

	int row = 1;
	for (int i = 0; i < num_of_racers; ++i) {

		if (race_results[i] == 0) continue;

		ss << row << "." << racers[sorted_idxs[i]]->name << ". Время:" << race_results[i] << std::endl;
		row++;
	}

	delete[] race_results;
	delete[] sorted_idxs;

	return ss.str();
}
