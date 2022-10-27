/*
Authors: Brendan Sirls, William Giraldo, Daniel Doerr
Date: 9/10/2020
Purpose: To handle input processing and produce a menu for the user to interact 
with. Functionality extends to handling ticket ownership, rides (and ride costs),
and attendance limits for patrons attending the amusment park.
*/

#include <iostream>
#include <string.h>
#include <limits>
#include <fstream>
#include "Patron.h"
#include "Teacups.h"
#include "Magiccarpet.h"
#include "Worldtour.h"
#include <sstream>

using std::cout;
using std::cin;
using str = std::string;

int numPatrons = 0;
Patron patronList[100];
str targetFile;
std::ifstream inFile;

// Prototypes
void addPatron( Patron newPatron, Patron pList[], int* numPat); 
int readExistingPatrons(Patron pList[], str file); 
Patron createNewPatron(); 
void overwriteFile(Patron pList[], str file, int numPat); 
void modifyPatron(Patron* patron); 
void addTickets(Patron* patron);
void editName(Patron* patron); 
void removePatron(Patron pList[], int index, int* numPat);
void displayPatrons();

// Handlers
void overwriteFile(Patron pList[] = patronList, str file = targetFile, int numPat = numPatrons) 
{
  std::ofstream out;
  out.open(file, std::ofstream::out | std::ofstream::trunc);
  for (int i = 0; i < numPat; i++) 
  {
    out << pList[i].getFirstName() << " " <<
    pList[i].getLastName() << " " << 
    std::to_string(pList[i].getPatronNumber()) << " " <<
    std::to_string(pList[i].getNumTickets()) + "\r\n";
  }
  out.close();
}

void editName(Patron* pat, str message = "") 
{
  // Clears the terminal & Prints options menu options 0-3
  cout << "\x1B[2J\x1B[H" << "1. First Name\r\n2. Last Name\r\n3. Full Name\r\n0. Exit\r\n";
  if(message.length() > 0) cout << message << '\n';
  
  int in; cin >> in;

  //checks input within range
  while(!cin || in > 3 || in < 0)
  {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return editName(pat,"Invalid input, please enter a number 0-3"); 
  }
  
  str name;
  cout << "\x1B[2J\x1B[H" <<"Enter replacement name:\r\n";
  switch(in)
  {
    case 1:
      cin >> name;
      pat -> setFirstName(name);
      break;
    case 2:
      cin >> name;
      pat -> setLastName(name);
      break;
    case 3:
      while(true)
      {
        getline(cin, name);
        int numWords = 0;
        std::istringstream is(name);
        for(str i; is >> i; numWords ++)
        {
          if (numWords == 0) pat -> setFirstName(i);
          if (numWords == 1) pat -> setLastName(i);
          if (numWords > 2) break;
        }
        if(numWords == 2) break;
        cout << "\x1B[2J\x1B[H" <<"Enter a proper name (\"first-name last-name\"):\r\n";
      }
      break;
  }
  overwriteFile();
}

void addPatron(Patron inPat, Patron pList[] = patronList, int* numPat = &numPatrons) 
{
  patronList[numPatrons] = inPat;
  numPatrons++;
  overwriteFile();
}


void addTickets(Patron* patron) {
  // Clears the terminal and asks the user for an input.
  cout << "\x1B[2J\x1B[H" << "How many tickets would you like to add? (0-99)\r\n";
  
  int in; cin >> in;
  while (!cin || in < 0 || in > 99) 
  {
    cout << "Invalid input, please enter a number from 0-99\r\n";
    cin >> in;
  }
  patron -> setNumTickets(patron -> getNumTickets() + in);
	overwriteFile();
} 

// Printing ----------------------------

//Displays the list of patrons by first and last name from the array.
void displayPatrons() 
{
  cout << "\x1B[2J\x1B[H";
  for (int i = 0; i < numPatrons; i++) 
  {
    cout << i + 1 << ". ";
    patronList[i].displayName();
  }
  cout << "0. Exit\n";
}

// Displays options for all function calls and clears the terminal to keep it clean
void displayMenuOption()
{
    // Clears the terminal
    cout << "\x1B[2J\x1B[H" 
    // Prints options menu options 1-4
           << "1. Add Patron\r\n2. Remove Patron\r\n3. Modify Patron\r\n4. View Patron\r\n0. Exit\r\n";
}

//In the event of a file not found error, this will be called to print the error.
void printFileNotFound(){
    cout << "Error: file not found, please enter a valid file for patron list\n";
}

//Prints the list of options for admissions/personal modifications.
void displayModOptions(){
    // Clears the terminal
    cout << "\x1B[2J\x1B[H" << 
    //Prints park modification options
      "1. Add Tickets\r\n2. Purchase Ride Admission\r\n3. Edit Name\r\n0. Exit to Main Menu\r\n";
}

//Prints the list of options out for Rides
void displayRideMenu(){
   // Clears the terminal
    cout << "\x1B[2J\x1B[H" << 
  "1. Teacups\r\n2. Magic Carpet\r\n3. World Tour\r\n0. Exit to Main Menu\r\n";
}

// Menu --------------------------------

int readExistingPatrons(Patron pList[] = patronList, str file = targetFile)
{
  //opens file and reads information from each patron
	inFile.open(file);
  str line, fName, lName, id, tickets;
  for (int i = 0; std::getline(inFile, line); i++)
  {
    std::istringstream is(line);
    is >> fName >> lName >> id >> tickets;

    //Places that information into the patron array
    Patron nPatron(fName, lName, stoi(id), stoi(tickets));
    patronList[i] = nPatron;
    numPatrons ++;
  }
	inFile.close();
  return 0;
}

// Gets user input selecting from a list of patrons
int getPatronOption(str message = "") {
  displayPatrons();
  if(message.length() > 0)
      cout << message << '\n';
  
  int in; cin >> in;
  // Ensures that user input a number that is within menu range
  if (!cin || in < 0 || in > numPatrons)
    {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return getPatronOption("Invalid input, please enter a number from the list");
    }
  //Menu handles input from the user to use the PatronOption menu.
  
  if (in == 0) return 0;
  return in;
}

void addRide(Patron* patron)
{
	int in; str tp;
	do
	{
		displayRideMenu();
	  // Clears the terminal and asks the user for an input.
	  cout << "Select a ride for the patron to spend tickets on\r\n";
		cin >> in;
		while (!cin || in < 0 || in > 3) 
	  {
			displayRideMenu();
			cout << "Select a ride for the patron to spend tickets on\r\n"
	    		 << "Invalid input, please enter a number from 0-3\r\n";
	    cin >> in;
	  }
		if(in !=0)
			if(patron -> getNumTickets() >= 4 - in) // ensuring they have enough tickets for the ride
			{
				patron -> setNumTickets(patron -> getNumTickets() - (4-in));
				switch(in)
				{
          //Switch case for each ride selection
					case 1:
						patron -> addPatronRides(Teacups());
						break;
					case 2:
						patron -> addPatronRides(Magiccarpet());
						break;
					case 3:
						patron -> addPatronRides(Worldtour());
						break;
				}
			}
			else
			{
//Checks for ticket total and prompts user to add more to patron ticket value
				int tp;
				cout << "They do not have enough tickets for the ride, would you like to get more?"
						 << "(1: Yes, 2: No)\r\n";
				cin >> tp;
				while (!cin || in < 1 || in > 2) 
	  		{
					cout << "\x1B[2J\x1B[H" 
					<< "They do not have enough tickets for the ride, would you like to get more?\r\n" 
					<< "Invalid input, please enter 1 or 2\r\n" ;
					cin >> tp;
				}
				if(tp == 1) addTickets(patron);
			}
	}while(in != 0);
	overwriteFile();
} 

//From the getModOption() menu, it moves over to modifying the patron where this method controls which input does what
void modifyPatron(Patron* patron, str message = "") 
{
	// int index = getPatronOption();
  displayModOptions();
  if(message.length() > 0)
    cout << message << '\n';
  
  int in; cin >> in;
  // Ensures that user input a number that is within menu range
    if (!cin || in < 0 || in > 3)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return modifyPatron(patron, "Invalid input, please enter a number 0-3");
    }
	
  switch(in)
  {
    //Switches statement for different function calls
    case 1:
      addTickets(patron);
      break;
    case 2:
			addRide(patron);
      break;
    case 3:
      editName(patron, "");
      break;
  }
}

Patron createNewPatron() 
{
  cout << "\x1B[2J\x1B[H" << "Enter first and last name\r\n";
  
  str inStr, fName, lName;
  int pNum, numTickets, inp;
  
  //While loop checks for 2 words to input for name
  while(true)
  { 
    getline(cin, inStr); std::istringstream is(inStr);
    int numWords = 0;
    for (str i; is >> i; numWords++)
    {
        if (numWords == 0) fName = i;
        if (numWords == 1) lName = i;
        if (numWords > 2) break;
    }
    if (numWords == 2) break;

    //Error message for if two words are not entered
    cout << "\x1B[2J\x1B[H" 
      << "Please enter a valid first and last name.\r\n";
  }
  
  cout << "\x1B[2J\x1B[H" 
    << "Enter patron ID (last four digits of phone number).\r\n";
  cin >> pNum;
  while (!cin || pNum > 9999 || pNum < 1000)
  {
		cin.clear();
//Checks for if value is usable for patron id
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\x1B[2J\x1B[H" 
      << "Invalid patron ID, please enter a valid one. (1000-9999)\r\n";
    cin >> pNum;
  }
//Sets ticket value to entered amount
  cout << "\x1B[2J\x1B[H" <<
		"How many tickets would they like to buy?\r\n";
  cin >> numTickets;
  while (!cin || numTickets > 99 || numTickets < 0)
    {
			cin.clear();
//Checks for valid ticket amount
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "\x1B[2J\x1B[H" 
        << "Invalid number of tickets, please enter a number. (0-99)\r\n";
      cin >> numTickets;
    }
	inp = 0;	
//Adds all information to creating a patron
  Patron nPatron(fName, lName, pNum, numTickets);
	do{addRide(&nPatron);}while(false);
  return nPatron;
}

// Deletes a patron from the patron list and updates the inFile
void removePatron(Patron pList[] = patronList, int index = 0, int* numPat = &numPatrons) 
{
  index = getPatronOption();
  if (index != 0) 
  {
    
    //Iterates to the patron selected
    for (int i = index - 1; i < numPatrons; i++)
    {
      patronList[i] = patronList[i + 1];
    }
    
    //Changes the total number of patrons
    numPatrons--;
    overwriteFile();
  }
}

int getModOption()
{
  return 0;
}

// Displays and asks user for information based on the provided prompts, prints error if neccesary
int getMenuOption(str message = "")
{
    displayMenuOption();
    if(message.length() > 0)
      cout << message << '\n';
    int in; cin >> in;
  
    // Ensures that user input a number that is within menu range
  //
    if (!cin || in < 0 || in > 4)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return getMenuOption("Invalid input, please enter a number 0-4");
    }
		Patron tempP;
	
    //Switch statement handles input from the user to use the meneuOption menu.
    switch (in) 
      {
      case 0:
          return 0;
          break;
      case 1:
					tempP = createNewPatron(); 
					addPatron(tempP);
          break;
      case 2:
          removePatron();
          break;
      case 3:
					int input;
          do
					{
						input = getPatronOption();
						modifyPatron(&patronList[input-1], "");
					}while(input !=0);
          break;
      case 4:
					str pause;
					int in = getPatronOption();
					if(in > 0)
					{
         		patronList[in-1].displayPatronData();
						cout << "Press enter to continue";
						pause = cin.get();
	        	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
          break;
      } 
    return in;
  }

// Main --------------------------------

int main(int argc, char** argv)
{
  if(argc == 2)
	{
    targetFile = argv[1];
		inFile.open(targetFile);
		if(inFile)
		{
			inFile.close();
			readExistingPatrons();
			while(getMenuOption() != 0){}
			inFile.close();
			return 0;
		}
		inFile.close();
	}
	cout << "Error: file not found, please enter a valid file for patron list\n";
  return 0;
}