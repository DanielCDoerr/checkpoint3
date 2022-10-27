#ifndef WORLDTOUR_H
#define WORLDTOUR_H
#include "Ride.h"

class Worldtour : public Ride
{
	public:
    Worldtour();
		Worldtour(int, str, bool);
		Worldtour(const Worldtour&);
};
#endif