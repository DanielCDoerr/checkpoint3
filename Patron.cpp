#include "Patron.h"

Patron::Patron(str fn, str ln, int id, int tik, int numR, Ride rList[])
{
  //Takes list information and puts it into array in order of: name, id, ticket number
	fName = fn;
	lName = ln;
	patronNumber = id;
	numTickets = tik;
	for(int i = 0; i < numR; i++) 
		patronRides[i] = rList[i];
}

Patron::Patron(str fn, str ln, int id, int tik)
{
	fName = fn;
	lName = ln;
	patronNumber = id;
	numTickets = tik;
}

Patron::Patron(const Patron& in)
{
	fName = in.fName;
	lName = in.lName;
	patronNumber = in.patronNumber;
	numTickets = in.numTickets;
}

Patron::Patron() 
{
	fName = "";
	lName = "";
	patronNumber = 0;
	numRides = 0;
	numTickets = -0;
}
//Displays patron information from text file
void Patron::displayPatronData() {
	cout << "\x1B[2J\x1B[H" 
		<< fName << " " << lName << ":\n" 
		<< "Number: " << patronNumber << "\n" 
		<< "Number of Rides: " << numRides << "\n"
		<< "Ticket count: " << numTickets << "\n" 
		<< "Rides: ";
//Inherts rides that the patron has been on, for final checkpoint
	for(Ride i : patronRides)
		{
			cout << i.getRideName()	<< ' ';
		}
	cout << '\n';
	}
void Patron::displayName() {cout << fName << " " << lName << '\n';}

// Getters
str Patron::getLastName() {return lName;}
str Patron::getFirstName() {return fName;}
int Patron::getPatronNumber() {return patronNumber;}
int Patron::getNumTickets() {return numTickets;}
Ride* Patron::getPatronRides() {return &patronRides[0];}

// Setters
void Patron::setLastName(str ln) {lName = ln;}
void Patron::setFirstName(str fn) {fName = fn;}
void Patron::setPatronNumber(int id) {patronNumber = id;}
void Patron::setNumTickets(int numTik) {numTickets = numTik;}
void Patron::addPatronRides(Ride in) 
{
	patronRides[numRides] = in;
	numRides ++;
}