#include "Ride.h"

//Sets values to inherit, getters and setters
Ride::Ride()
{
	name = "";
	heightRestricted = true;
	numTicketsNecessary = 0;
}

Ride::Ride(int numTik, str nm, bool isHR)
{
	numTicketsNecessary = numTik;
	name = nm;
	heightRestricted = isHR;
}

Ride::Ride(const Ride& in)
{
	numTicketsNecessary = in.numTicketsNecessary;
	name = in.name;
	heightRestricted = in.heightRestricted;    
}

// Getters
int Ride::getNumTicketsNecessary() {return numTicketsNecessary;}
str Ride::getRideName() {return name;}
bool Ride::getHeightRestricted() {return heightRestricted;}

// Setters
void Ride::setNumTicketsNecessary(int in) {numTicketsNecessary = in;}
void Ride::setRideName(str in) {name = in;}
void Ride::setHeightRestricted(bool in) {heightRestricted = in;}