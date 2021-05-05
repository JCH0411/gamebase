/*This header file includes the control class which has fucntions to add set the serach values passed to it by the userInterface and use those values to compare against the drivers vectorGames and call
print function of the print class when games are found. The artifact was implemented on 4/23/2021 by Kimbelry Hernandez and designed by all group members 
including Kimberly Hernandez, Sohail Adhikari, Parth Patel, John Houston
*/



#include "gameClass.h"
#include "driver.h"
#include "printClass.h"
#include<vector>
#include <string>
using namespace std;
#ifndef CONTROL_H
#define CONTROL_H
#pragma once
#pragma warning(disable: 4430)

class control
{

	private:
	string hardware; //variables to initialize control object 
	string genre;
	int price;
	int rating;
	int year;
	string gameAttribute;
	
	public:
	
	control()
	{
		hardware = "no";
		genre = "no";
		price = -1;
		rating = -1;
		year = -1;
		gameAttribute = "no";
	}


	void createSSH(int value)   // function to receive hardware input from user if any 
	{


		if (value == 1)
			hardware = "XB";
		if (value == 2)
			hardware = "PC";
		if (value == 3)
			hardware = "PS";
		if (value == 4)
			hardware = "NI";
	}


	void createSSGe(int value)   // function to receive Genre input from user 
	{
		
		// check  wording for how we input classics rpg
		if (value == 1)
			genre = "Classic";
		if (value == 2)
			genre = "RPG";
		if (value == 3)
			genre = "Strategy";
		if (value == 4)
			genre = "FPS";
		if (value == 5)
			genre = "Action";
	}


	void createSSP(int value)        // function to receive price input from user
	{
		price = value;
	}

	void createSSR(int value)       //function to receive Rating input from user 
	{
		rating = value;

	}

	void createSSY(int value)     //function to receive Year input from user 
	{
		year = value;
	}

	void createSSGA(int value)       // function to receive attribute input from 
	{

		if (value == 1)
			gameAttribute = "guns";
		if (value == 2)
			gameAttribute = "hand to hand";
		if (value == 3)
			gameAttribute = "real time";
		if (value == 4)
			gameAttribute = "2D";
		if (value == 5)
			gameAttribute = "turn based";
		if (value == 6)
			gameAttribute = "fantasy";

	}



	void compare(driver driverObj)// this function takes the driver object and uses its games vector to search for games //that fit the search criteria and calls the print function for them.
	{	

		
		// declare and initialise variables for size  to the size of the games vector

		int size;
		size = driverObj.getVectorSize();

		// create and inshiles flags for each seachvalue and ishilize them all to false.


		

		//create print object

		printClass printObj;
		bool gameFound = false;  //bool value to test for any games found in user search

		for (int x = 0; x < size; x++)     // For loop to compare user values to games
		{
			bool flagH = false, flagGe = false, flagP = false, flagR = false, flagY = false, flagGA = false;
			//if not searching for hardware flag=true

			if (hardware == "no")
				flagH = true;// if hardware is being searched for and is a match flag=true

			else if (driverObj.compareHardware(hardware, x))
				flagH = true;//if not searching for genre flag=true

			if (genre == "no")
				flagGe = true;// if genre is being searched for and is a match flag=true

			else if (driverObj.compareGenre(genre, x))
				flagGe = true;//if not searching for price flag=true

			if (price == -1)
				flagP = true; 	// if price  is being searched for and is a match flag=true

			else if (driverObj.comparePrice(price,x))
				flagP = true;//if not searching for ratings flag=true

			if (rating == -1)
				flagR = true;// if ratings is being searched for and is a match flag=true

			else if (driverObj.compareRateing(rating, x))
				flagR = true;//if not searching for year flag=true

			if (year == -1)
				flagY = true;// if year is being searched for and is a match flag=true

			else if (driverObj.compareYear(year, x))
				flagY = true;//if not searching for attribute flag=true

			if (gameAttribute == "no")
				flagGA = true;// if attribute is being searched for and is a match flag=true

			else if (driverObj.compareGameAttribute(gameAttribute, x))
				flagGA = true;//print if all values true

			if (flagH && flagGe && flagP && flagR && flagY && flagGA)
			{
				printObj.printgame(driverObj, x);// calls print function from print object to print the game/
				gameFound = true;

			}
			
		}	
			if(!gameFound)    //tetsing if any search criteris was able to locate a game for the user
		    cout << "Sorry your search criteria did not find any games Please try again!! " << endl;

		hardware = "no";
		genre = "no";
		price = -1;
		rating = -1;
		year = -1;
		gameAttribute = "no";
			


	}


};
#endif
