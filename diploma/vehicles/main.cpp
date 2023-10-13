#include <iostream>
#include <string>
#include <sstream>

#include <io.h>
#include <fcntl.h>

#include "race.h"
#include "air_race.h"
#include "ground_race.h"
#include "combined_race.h"


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

 Race *race_factory(RaceType race_type)
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


}

int main()
{

    setlocale(LC_ALL, "Russian");

  RaceType race_type;
  double race_distance;

  std::cout << get_greeting();

  std::cout << get_race_selection();
  int value; std::cin >> value;
  race_type = static_cast<RaceType>(value - 1); 

  std::cout << get_distance();
  std::cin >> race_distance;

  Race *race = race_factory(race_type);
  race->set_distance(race_distance);

  std::cout << race->get_race_info() << std::endl;
  std::cout << race->get_racers_selection() << std::endl;
  

  system("pause");

  return 0;

}