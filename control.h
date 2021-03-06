/*This header file includes the control class which has fucntions to add set the serach values passed to it by the userInterface and use those values to compare against the drivers vectorGames and call
print function of the print class when games are found. The artifact was implemented on 4/23/2021 by Kimbelry Hernandez and designed by all group members 
including Kimberly Hernandez, Sohail Adhikari, Parth Patel, John Houston
*/



#include "gameClass.h"
#include "driver.h"
#include "print.h"
#include<vector>
#include <string>
using namespace std;
#ifndef control_h
#define control_h


class control
{

	//variables to initialize control object 

private:
	string hardware;
	string genre;
	int price;
	int rating;
	int year;
	string gameAttribute;
	// check the way the function names are capitlized in userface
public:
	control();
	void createSSH(int value); // function to receive hardware input from use
	void createSSGe(int value); // function to receive Genre input from user  
	void createSSP(int value);  // function to receive price input from user 
	void createSSR(int value);  //function to receive Rating input from user
	void createSSY(string value); //function to receive Year input from user
	void createSSGA(int value); // function to receive attribute input from user
	void compare(driver driverObj);


	control()
	{
		hardware = "no";
		general = "no";
		price = -1;
		rating = -1;
		year = -1;
		gameAttribute = "no";
	}


	void createSSH(int value)   // function to receive hardware input from user if any 
	{


		if (value == 1)
			Hardware = "XB";

		if (value == 2)
			Hardware = "PS";
		if (value == 3)
			Hardware = "NI";
		if (value == 4)
			Hardware = "PC";
	}


	void createSSGe(int value)   // function to receive Genre input from user 
	{
		// check  wording for how we input classics rpg
		if (value == 1)
			genre = "classics";
		if (value == 2)
			genre = "RPG";
		if (value == 3)
			genre = "strategy";
		if (value == 4)
			genre = "FPS";
		if (value == 5)
			Genre = "action";
	}


	void createSSP(int value)        // function to receive price input from user
	{
		Price = value;
	}

	createSSR(int value)       //function to receive Rating input from user 
	{
		Ratings = value;

	}

	createSSY(string value)     //function to receive Year input from user 
	{
		year = value;
	}

	createSSGA(int value)       // function to receive attribute input from 
	{

		if (value == 1)
			gameAttribute = "gN";
		if (value == 2)
			gameAttribute = "hH";
		if (value == 3)
			gameAttribute = "rT";
		if (value == 4)
			gameAttribute = "2D";
		if (value == 5)
			gameAttribute = "3D";
		if (value == 6)
			gameAttribute = "tB";
		if (value == 7)
			gameAttribute = "fY";

	}



	compare(driver driverObj)// this function takes the driver object and uses its games vector to search for games //that fit the search criteria and calls the print function for them.
	{
		// declare and initialise variables for size  to the size of the games vector

		int size;
		Size = driverObj.getVectorSize();

		// create and inshiles flags for each seachvalue and ishilize them all to false.


		bool flagH = false, flagGe = false, flagP = false, flagR = false, flagY = false, flagGa = false;

		//create print object

		print printObj;


		for (int x = 0; x < size; x++)     // For loop to compare user values to games
		{
			//if not searching for hardware flag=true

			if (hardware == "no")
				flagH = true;// if hardware is being searched for and is a match flag=true

			else if (string hardware == driverObj.getGamesVector[x].hardware)
				flagH = true;//if not searching for genre flag=true


			if (genre == "no")
				flagGe = True;// if genre is being searched for and is a match flag=true

			else if (genre == driverObj.getGamesVector[x].genre)
				flagGe = true;//if not searching for price flag=true

			if (price == -1)
				flagP = true; 	// if price  is being searched for and is a match flag=true

			else if (price <= driverObj.getGamesVector[x].price)
				flagP = true;//if not searching for ratings flag=true

			if (rating == "no")
				flagR = True;// if ratings is being searched for and is a match flag=true

			else if (rating == driverobj.getGamesVector[x].rating)
				flagR = rating;//if not searching for year flag=true

			if (year == -1)
				flagY = True;// if year is being searched for and is a match flag=true

			else if (year == obj.getGamesVector[x].year)
				flagY = rating;//if not searching for attribute flag=true

			if (attribute == "no")
				flagGa = True;// if attribute is being searched for and is a match flag=true

			else if (attribute >= obj.getGamesVector[x].genre.attribute)
				flagGa = rating;//print if all values true

			if (flagH && flagGe && flagP && flagR && flagY && flaga)
				printObj.printgame(driverObj.getGamesVector[x]);// calls print function from print object to print the game/

		}

}



#endif















