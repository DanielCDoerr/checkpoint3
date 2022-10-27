#ifndef PATRON_H
#define PATRON_H
#include <iostream>
#include <string>
#include "Teacups.h"
#include "Worldtour.h"
#include "Magiccarpet.h"

using str = std::string;
using std::cout;

class Patron
{
    private:
    Ride patronRides[100];
    int patronNumber;
    int numRides;
    int numTickets;
    str fName;
    str lName;

    public:
    Patron(str fn, str ln, int id, int tik, int numR, Ride rList[]);
    Patron(str fn, str ln, int id, int tik);
    Patron(const Patron& in);
    Patron();

    // Display
    void displayPatronData();
		void displayName();

    // Getters
    str getLastName();
    str getFirstName();
    int getPatronNumber();
    int getNumTickets();
    Ride* getPatronRides();

    // Setters
    void setLastName(str ln);
    void setFirstName(str fn);
    void setPatronNumber(int id); 
    void setNumTickets(int numTik);
    void addPatronRides(Ride in); 
};
#endif