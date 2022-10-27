#ifndef TEACUPS_H
#define TEACUPS_H
#include "Ride.h"

class Teacups : public Ride
{
	public:
    Teacups();
		Teacups(int, str, bool);
		Teacups(const Teacups&);
};
#endif