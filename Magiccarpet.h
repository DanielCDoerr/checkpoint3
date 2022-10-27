#ifndef MAGICCARPET_H
#define MAGICCARPET_H
#include "Ride.h"

class Magiccarpet : public Ride
{
	public:
    Magiccarpet();
		Magiccarpet(int, str, bool);
		Magiccarpet(const Magiccarpet&);
};
#endif