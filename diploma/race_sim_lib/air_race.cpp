#include "air_race.h"

#include "vehicle.h"
#include "teppich_jet.h"
#include "eagle.h"
#include "broom.h"

AirRace::AirRace() :Race("Воздушная гонка")
{
	num_of_racers = 3;

	racers = new Vehicle * [3];
	racers[0] = new TeppichJet();
	racers[1] = new Eagle();
	racers[2] = new Broom();

	set_flags = new int[3] {0, 0, 0};
}

AirRace::~AirRace() {
	delete racers[0];
	delete racers[1];
	delete racers[2];
	delete racers;
	delete set_flags;
};