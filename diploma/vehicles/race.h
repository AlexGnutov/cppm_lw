#pragma once

#include <string>

#include "enums.h"
#include "vehicle.h"
#include "vehicle_collection.h"

//! ����� ����� - ������� ����� ��� ����� ���������� �����.
class Race {
public:
	Race(std::string name) :name(name) {}

	//! ����������� ������ ��������� � ������ ����������. 
	std::string get_racers_selection();

	//! ���������� ���������� � �����.
	std::string get_race_info();

	//! ������������� �������� �����.
	void set_distance(double value);

	//! �������� ��� �� � �������.
	bool set_racer(int index);

	//! ���������, ����� �� ����������.
	bool is_ready();

	//! ��������� ����� � ���������� ���������.
	std::string run();

	std::string name;		///< �������� �����.
	double distance = 0;	///< ���������.

	int num_of_racers = 0;			///< ����� ��������� ���������� (��������� ����� ��).
	Vehicle** racers = nullptr;		///< ������ ���������� �� �������-���������.
	int* set_flags = nullptr;		///< ������ � �������� �� ������� ���� ��.
};

