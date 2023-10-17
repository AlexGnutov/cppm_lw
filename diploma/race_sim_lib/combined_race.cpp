#include "combined_race.h"

#include "vehicle.h"
#include "teppich_jet.h"
#include "eagle.h"
#include "broom.h"
#include "camel.h"
#include "super_camel.h"
#include "kentavr.h"
#include "offroad_shoes.h"

CombinedRace::CombinedRace() :Race("Всеобщая гонка")
{
	num_of_racers = 7;

	racers = new Vehicle * [7];
	racers[0] = new Camel();
	racers[1] = new SuperCamel();
	racers[2] = new Kentavr();
	racers[3] = new OffroadShoes();
	racers[4] = new TeppichJet();
	racers[5] = new Eagle();
	racers[6] = new Broom();

	set_flags = new int[7] {0, 0, 0, 0, 0, 0, 0};
}

CombinedRace::~CombinedRace() {
	delete racers[0];
	delete racers[1];
	delete racers[2];
	delete racers[3];
	delete racers[4];
	delete racers[5];
	delete racers[6];
	delete racers;
	delete set_flags;
};