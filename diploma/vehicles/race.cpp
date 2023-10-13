#include "race.h"

#include <sstream>

void Race::set_distance(double value)
{
	this->distance = value;
}

std::string Race::get_racers_selection()
{
	std::stringstream ss;
	for (int i = 0; i < num_of_races; ++i) {
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

	for (int i = 0; i < num_of_races; ++i) {
		if (set_flags[i] == 1) {
			ss << pre << racers[i];
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

	if (index < 0 || index >= num_of_races) {
		return false;
	}
	set_flags[index] = 1;
	return true;
}
