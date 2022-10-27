#include "Worldtour.h"

//Sets information for WorldTour ride, sets variables for later information like height
Worldtour::Worldtour()
{
	name = "World Tour";
  numTicketsNecessary = 1;
  heightRestricted = false;
}

Worldtour::Worldtour(int numTik, str nm, bool isHR)
{
	numTicketsNecessary = numTik;
	name = nm;
	heightRestricted = isHR;
}

Worldtour::Worldtour(const Worldtour& in)
{
	numTicketsNecessary = in.numTicketsNecessary;
	name = in.name;
	heightRestricted = in.heightRestricted;  
}