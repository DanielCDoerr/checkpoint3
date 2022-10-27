#include "Teacups.h"

//Sets information for teacup ride, sets variables for later information like height
Teacups::Teacups()
{
	name = "Teacups";
  numTicketsNecessary = 3;
  heightRestricted = false;
}

Teacups::Teacups(int numTik, str nm, bool isHR)
{
	numTicketsNecessary = numTik;
	name = nm;
	heightRestricted = isHR;
}

Teacups::Teacups(const Teacups& in)
{
	numTicketsNecessary = in.numTicketsNecessary;
	name = in.name;
	heightRestricted = in.heightRestricted;   
}