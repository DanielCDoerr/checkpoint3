#ifndef RIDE_H
#define RIDE_H
#include <string>
using str = std::string;

class Ride
{
  protected:
  int numTicketsNecessary;
  str name;
  bool heightRestricted;

  public:
	Ride();
  Ride(int numTik, str nm, bool isHR);
  Ride(const Ride& in);

  // Getters
  int getNumTicketsNecessary();
  str getRideName(); 
  bool getHeightRestricted(); 

  // Setters
  void setNumTicketsNecessary(int in); 
  void setRideName(str in); 
  void setHeightRestricted(bool in); 
};
#endif