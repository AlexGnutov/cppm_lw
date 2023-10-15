#include "ground_race.h"

#include "vehicle.h"
#include "camel.h"
#include "super_camel.h"
#include "kentavr.h"
#include "offroad_shoes.h"

GroundRace::GroundRace() :Race("Наземная гонка")
{
	num_of_racers = 4;

	racers = new Vehicle * [4];
	racers[0] = new Camel();
	racers[1] = new SuperCamel();
	racers[2] = new Kentavr();
	racers[3] = new OffroadShoes();

	set_flags = new int[4] {0, 0, 0, 0};
};

GroundRace::~GroundRace()
{
	delete racers[0];
	delete racers[1];
	delete racers[2];
	delete racers[3];
	delete racers;

	delete set_flags;
};