carnival: driver.o Patron.o Ride.o Teacups.o Worldtour.o Magiccarpet.o
	g++ -o carnival driver.o Patron.o Ride.o Teacups.o Worldtour.o Magiccarpet.o
Ride.o: 
	g++ -c Ride.cpp
Teacups.o: 
	g++ -c Teacups.cpp
Worldtour.o: 
	g++ -c Worldtour.cpp
Magiccarpet.o: 
	g++ -c Magiccarpet.cpp
Patron.o: 
	g++ -c Patron.cpp
driver.o: 
	g++ -c driver.cpp 
clean:
	rm *.o carnival