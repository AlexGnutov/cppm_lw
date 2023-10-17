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

//! ����� ����� - ������� ����� ��� ����� ���������� �����.
class Race {
public:
    LIBRARY_API Race(std::string name) :name(name) {}

	//! ����������� ������ ��������� � ������ ����������. 
    LIBRARY_API std::string get_racers_selection();

	//! ���������� ���������� � �����.
    LIBRARY_API std::string get_race_info();

	//! ������������� �������� �����.
    LIBRARY_API void set_distance(double value);

	//! �������� ��� �� � �������.
    LIBRARY_API bool set_racer(int index);

	//! ���������, ����� �� ����������.
    LIBRARY_API bool is_ready();

	//! ��������� ����� � ���������� ���������.
    LIBRARY_API std::string run();

	std::string name;		///< �������� �����.
	double distance = 0;	///< ���������.

	int num_of_racers = 0;			///< ����� ��������� ���������� (��������� ����� ��).
	Vehicle** racers = nullptr;		///< ������ ���������� �� �������-���������.
	int* set_flags = nullptr;		///< ������ � �������� �� ������� ���� ��.
};

