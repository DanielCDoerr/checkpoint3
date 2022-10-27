#include "Magiccarpet.h"

//Sets information for MagicCarpet ride, sets variables for later information like height
Magiccarpet::Magiccarpet()
{
	name = "Magic Carpet";
  numTicketsNecessary = 2;
  heightRestricted = true;
}

Magiccarpet::Magiccarpet(int numTik, str nm, bool isHR)
{
	numTicketsNecessary = numTik;
	name = nm;
	heightRestricted = isHR;
}

Magiccarpet::Magiccarpet(const Magiccarpet& in)
{
	numTicketsNecessary = in.numTicketsNecessary;
	name = in.name;
	heightRestricted = in.heightRestricted;    
}