// include the /h file to use the vector of games and to access the variables in the game //object

#include <iostream>
#include "driver.h"
#include "gameClass.h"
#include "control.h"
#include "printClass.h"
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#pragma once
#pragma warning(disable: 4430)



class userInterface // this class is incharge of displaying menu’s and accepting users input
{
private:

	// value to hold admin input for password

	int password;

	

public:

	driver driverObj; //creates the driver object that will populate all the games so the user may search or update them
	control searchObj; //creating the control object so the user may pass it with the driver object 
   

	userInterface()
	{

		password = 12345678;     // admin password that gets initialized every time program runs this is a temporary value.

		dispM();
	}


	// display main menu
	void dispM()
	{

		// Here we will introduce the first menu for the user to select how they would like to search for games

		cout << "Welcome to GameBase Please select how you would like to search for a game" << endl;
		cout << "For admin please select option 8" << endl;

		char again = 'N';
		do
		{

			// user input for menu selection
			int x;

			cout << "------------Search selections------------" << endl;   // user interface main menu
			cout << "1. Genre" << endl;
			cout << "2. Game attributes" << endl;
			cout << "3. Year released" << endl;
			cout << "4. Ratings" << endl;
			cout << "5. Price" << endl;
			cout << "6. Hardware" << endl;
			cout << "7. Search by any attribute" << endl;
			cout << "8. Admin" << endl;
			cin >> x;
			cout << "\n";

			while (x < 1 || x > 8)  //main menu user input validation
			{
				cout << "That was an invalid input from the menu. Please enter a correct menu selection value: ";
				cin >> x;
			}

			switch (x)
			{
				//switch to jump function regarding user input

			case 1: dispGe(); 	searchObj.compare(driverObj);
				break;
			case 2: dispGA();	searchObj.compare(driverObj);
				break;
			case 3: dispY();	searchObj.compare(driverObj);
				break;
			case 4: dispR();	searchObj.compare(driverObj);
				break;
			case 5: dispP();	searchObj.compare(driverObj);
				break;
			case 6: dispH();	searchObj.compare(driverObj);
				break;
			case 7: dispMulti(); searchObj.compare(driverObj);
				break;
			case 8: dispAD();    //This is admin login with password protection 
				break;
			}

			cout << "Would you like to return to the main menu or quit? Please enter Y for main menu or N to quit: ";
			cin >> again;
			cin.ignore();
			cout << "\n";

		} while (again == 'y' || again == 'Y'); //This is the end of the inside of main class

		

	}


	void dispGA()  //function to display attribute selection
	{
		
		int attribute;
		cout << "what attribute would you like to choose?: " << endl;
		cout << "1 - Guns" << endl;
		cout << "2 - Hand to Hand" << endl;
		cout << "3 - Real Time" << endl;
		cout << "4 - 2D" << endl;
		cout << "5 - Turn Based" << endl;
		cout << "6 - Fantasy" << endl;
		cout << "enter a value 1 - 6" << endl;

		cin >> attribute;
		cout << "\n";

		while (attribute < 1 || attribute > 6)
		{
			cout << "That was an incorrect input Please select the correct choice 1-6!!" << endl;
			cin >> attribute;
			

		}
		searchObj.createSSGA(attribute);
	}


	void dispH()  //function to display hardware selection 
	{
		int hardware;

		cout << "Do you want to search for" << endl;
		cout << "1 - xbox" << endl;
		cout << "2 - Personal Computer" << endl;
		cout << "3 - Playstation" << endl;
		cout << "4 - nintendo" << endl;
		cout << "Enter a value from 1 - 4" << endl;

		cin >> hardware;
		cout << "\n";

		while (hardware < 1 || hardware > 4)
		{
			cout << "That was an incorrect input Please select the correct choice of 1-4!!" << endl;
			cin >> hardware;
		}

		searchObj.createSSH(hardware);

	}

	void dispGe()  // function to display genre selection 
	{
		int genre;

		cout << " Do you want to search for " << endl;
		cout << " 1 - Classic " << endl;
		cout << " 2 - rpg " << endl;
		cout << " 3 - strategy " << endl;
		cout << " 4 - FPS " << endl;
		cout << " 5 - action " << endl;
		cout << " Enter an value from 1 - 5 " << endl;

		cin >> genre;
		cout << "\n";

		while (genre < 1 || genre > 5)
		{	
			cout << "That was an incorrect input Please select the correct choice of 1-5!!" << endl;
			cin >> genre;
		}
		searchObj.createSSGe(genre);

	}


	void dispY()  //function to display the year selection
	{
		int year;

		cout << " * NOTE * : The result shown will be the games released in that particular year or more recent than 1980 " << endl;
		cout << " Enter the year you want to search for: " << endl;

		cin >> year;
		cout << "\n";

		while (year < 1980)
		{
			cout << "That was an incorrect input Please select the correct choice of a year greater than or equal to 1980!!" << endl;
			cin >> year;
		}
		searchObj.createSSY(year);

	}


	void dispP()  //function to display the price selection
	{
		double price;
		int price2;


		cout << " * NOTE* : The result shown will be the games with the price tag that you choose or lower " << endl;
		cout << " Enter a number you want to search from: $ ";

		cin >> price;
		price2 = static_cast<int>(price);  //validation to convert any user input to an int
		cout << "\n";

		while (price2 <= 0)
		{
			cout << "That was an incorrect input Please input a price of $1 or more " << endl;
			cin >> price;
			price2 = static_cast<int>(price);
		}
		searchObj.createSSP(price2);

	}

	void dispR() //function to display the rating selection
	{
		int rating;

		cout << " * NOTE* : The result shown will be the games with the rating that you choose or higher " << endl;
		cout << " Enter an rating between 1 - 5: ";

		cin >> rating;
		cout << "\n";

		while (rating < 1 || rating > 5)
		{
			cout << "That was an incorrect input Please input a rating between 1 AND 5!!" << endl;
			cin >> rating;
		}
		searchObj.createSSR(rating);

	}





	void dispMulti() //function to display all the search criteria at once.
	{
		cout << "For any of the search options listed above please enter Y or N for the game criteria that you would like to search by. " << endl;
		cout << "If no criteria are selected to search by, the entire list of games will print out. \n" << endl;

		string gen = "n", year = "n", ratings = "n", price = "n", hardware = "n", attribute = "n";


		cout << "Would you like to search by search by genre? select Y or N: ";
		cin >> gen;
		while (gen != "Y" && gen != "y" && gen != "n" && gen != "N")
		{
			cout << "You did not select Y or N please select the correct choice: ";
			cin >> gen;
			cout << "\n";
		}

		if (gen == "Y" || gen == "y")
		{
			dispGe();
			
		}
		cout << "\n";

		
		cout << "Would you like to search by search by game attribute? select Y or N: ";
		cin >> attribute;
		while (attribute != "Y" && attribute != "y" && attribute != "n" && attribute != "N")
		{
			cout << "You did not select Y or N please select the correct choice: ";
			cin >> attribute;
			cout << "\n";
		}

		if (attribute == "Y" || attribute == "y")
		{
			dispGA();
			
		}
		cout << "\n";


		cout << "Would you like to search by search by year? select Y or N: ";
		cin >> year;
		while (year != "Y" && year != "y" && year != "n" && year != "N")
		{
			cout << "You did not select Y or N please select the correct choice: ";
			cin >> year;
			cout << "\n";
		}

		if (year == "Y" || year == "y")
		{
			dispY();
			
		}
		cout << "\n";

		cout << "Would you like to search by search by rating? select Y or N: ";
		cin >> ratings;
		while (ratings != "Y" && ratings != "y" && ratings != "n" && ratings != "N")
		{
			cout << "You did not select Y or N please select the correct choice: ";
			cin >> ratings;
			cout << "\n";
		}

		if (ratings == "Y" || ratings == "y")
		{
			dispR();
			
		}
		cout << "\n";


		cout << "Would you like to search by search by price? select Y or N: ";
		cin >> price;
		while (price != "Y" && price != "y" && price != "n" && price != "N")
		{
			cout << "You did not select Y or N please select the correct choice: ";
			cin >> price;
			cout << "\n";
		}

		if (price == "Y" || price == "y")
		{
			dispP();
			
		}
		cout << "\n";


		cout << "Would you like to search by search by Hardware? select Y or N: ";
		cin >> hardware;
		while (hardware != "Y" && hardware != "y" && hardware != "n" && hardware != "N")
		{
			cout << "You did not select Y or N please select the correct choice: ";
			cin >> hardware;
			cout << "\n";
		}

		if (hardware == "Y" || hardware == "y")
		{
			dispH();
			
		}
		cout << "\n";

	}

	void dispAD() // Admin login
	{	
		int userPassword = 0;
		cout << " Please enter the admin password: ";
		cin >> userPassword;
		
		while (userPassword != password)
		{
			cout << "Sorry that password was not correct try again or enter 1 to quit: ";
			cin >> userPassword;

			if (userPassword == 1)
			break;
			
		}
		if(userPassword == password)
		dispADM();


		
	}



	void dispADM() // this function is the admins menu
	{
		int  userInput;
		cout << "Admin privileges allow to either update a game or add a game. Which do you prefer? " << endl;
		cout << "1 - Update a game" << endl;
		cout << "2 - Add a new game" << endl;
		cin >> userInput;

		while (userInput != 1 && userInput != 2)
		{
			cout << " That selection was not 1 or 2 please enter one of the two correct choices: ";
			cin >> userInput;
		}

		if (userInput == 1)
		{
			dispADU();
		}
		if (userInput == 2)
		{
			dispADAdd();
		}
	}

	void dispADU() // this function is the admin update menu
	{
		string gName;
		string vectorGameName;
		int counter = driverObj.getVectorSize();
		int x;
		int adminAtt;
		
		cout << "What is the name of the game you would like to search for: ";
		cin.ignore();
		getline(cin, gName);

		
		for (x = 0; x < counter; x++)
		{
			vectorGameName = driverObj.getGameName(x);  // usin the function in the loop to search for the specific name of a game
			if (gName == vectorGameName)
			break;
		}

		string again = "N";  //variable to repeat do while to update a specific game for the admin
		do
		{
			string tempString = "";
			double tempInt = 0;
			int tempInt2;     // tempInt2 is a variable to hold a static cast to turn the price into an int becuase the game class only holds an int for the price

			cout << " Which attribute would you like to change " << endl;
			cout << " 1. Genre " << endl;
			cout << " 2. Attribute " << endl;
			cout << " 3. Year " << endl;
			cout << " 4. Rating" << endl;
			cout << " 5. Price " << endl;
			cout << " 6. Hardware " << endl;

			cin >> adminAtt; //input for admin to select for which attribute they would like to change 

			while (adminAtt < 1 || adminAtt > 6)  //main menu user input validation
			{
				cout << "That was an invalid input from the menu. Please enter a correct menu selection value 1 - 6: ";
				cin >> adminAtt;
			}

			cout << "\n";

			switch (adminAtt)
			{
			case 1:
				cout << "Enter the new genre of the choices RPG, Classic, FPS, Action, and Strategy " << endl;
				cin >> tempString;

				while (tempString != "Classic" && tempString != "RPG" && tempString != "Strategy" && tempString != "FPS" && tempString != "Action") //input validation for the genre
				{
					cout << "That was an incorrect input Please input either RPG, Classic, FPS, Action, and Strategy!!" << endl;
					cin >> tempString;

				}
				cout << "\n";
				driverObj.setVectorGenre(tempString, x);
				break;

			case 2:
				cout << "Enter the new attribute of the choices guns, hand to hand, real time, 2D, turn based, and fantasy " << endl;
				cin.ignore();
				getline(cin,tempString);

				while (tempString != "guns" && tempString != "hand to hand" && tempString != "real time" && tempString != "2D" && tempString != "turn based" && tempString != "fantasy")  //input validation for the attribute
				{
					cout << "That was an incorrect input Please input any of the correct attributes guns, hand to hand, real time, 2D, turn based, and fantasy!!" << endl;
					cin.ignore();
					getline(cin, tempString);

				}
				cout << "\n";
				driverObj.setVectorAttribute(tempString, x);
				break;

			case 3:
				cout << "Enter the new year which is any year greater or equal to 1980 " << endl;
				cin >> tempInt2;

				while (tempInt2 < 1980) //input validation for the year
				{
					cout << "That was an incorrect input Please select the correct choice of a year greater than or equal to 1980!!" << endl;
					cin >> tempInt2;

				}
				cout << "\n";
				driverObj.setVectorYear(tempInt2, x);
				break;

			case 4:
				cout << "Enter the new rating which is between 1 and 5" << endl;
				cin >> tempInt;

				while (tempInt < 1 || tempInt > 5) //input validation for the rating
				{
					cout << "That was an incorrect input Please input 1 - 5 ONLY!!" << endl;
					cin >> tempInt;

				}
				cout << "\n";
				driverObj.setVectorRating(tempInt, x);
				break;

			case 5:
				cout << "Enter the new price not, has to be greater than $0 " << endl;
				cin >> tempInt;
				tempInt2 = static_cast<int>(tempInt);

				while (tempInt <= 0)  //input validation for the attribute
				{
					cout << "That was an incorrect input Please input a price of $1 or more " << endl;
					cin >> tempInt;
					tempInt2 = static_cast<int>(tempInt);
				}
				cout << "\n";
				driverObj.setVectorPrice(tempInt2, x);
				break;

			case 6:
				cout << "Enter the new hardware of the choices XB, PC, PS, and NI" << endl;
				cin >> tempString;

				while (tempString != "XB" && tempString != "PC" && tempString != "PS" && tempString != "NI")   //input validation for the hardware
				{
					cout << "That was an incorrect input Please input either XB, PC, PS, and NI !!" << endl;
					cin >> tempString;

				}
				cout << "\n";
				driverObj.setVectorHardWare(tempString, x);
				break;
			}

			
			cout << "Would admin like to update another attribute please enter Y or N " << endl;
			cin >> again;
			cout << "\n";

		} while (again == "Y" || again == "y"); // asking to repeat another update to the same game 
	}

	// this function adds a new game using the admins input and adds it to the game //vector
	void dispADAdd()
	{
		string name, hardware, genre, attribute;
		int year, rating, price2; //price2 is to be able to have a variable to convert any floats or doubles to an int becuase the game class only holds an int for the price
		double price;

		cout << "When entering new data be sure to input the data listed below correctly " << endl;   
		cout << "Please enter the name of the game: ";
		cin.ignore();
		getline(cin, name);
		cout << "\n";

		cout << "Please enter the new hardware for the game of the choices XB, PC, PS, and NI: ";
		cin >> hardware;
		

		while (hardware != "XB" && hardware != "PC" && hardware != "PS" && hardware != "NI")  //input validation for the hardware
		{
			cout << "That was an incorrect input Please input either XB, PC, PS, and NI !!" << endl;
			cin >> hardware;
			
		}
		cout << "\n";

		cout << "Please enter the year the game was released is 1980 or greater: ";
		cin >> year;
		

		while (year < 1980)   //input validation for the year
		{
			cout << "That was an incorrect input Please select the correct choice of a year greater than or equal to 1980!!" << endl;
			cin >> year;
			
		}
		cout << "\n";

		cout << "Please enter the price of the game with values greater than 0: $";
		cin >> price;
		price2 = static_cast<int>(price);

		
		while (price <= 0)   //input validation for the price
		{
			cout << "That was an incorrect input Please input a price of $1 or more " << endl;
			cin >> price;
			price2 = static_cast<int>(price);
		}
		cout << "\n";

		cout << "Please enter the genre of the game from the choices of RPG, Classic, FPS, Action, and Strategy: ";
		cin >> genre;
		

		while (genre != "Classic" && genre != "RPG" && genre != "Strategy" && genre != "FPS" && genre != "Action")   //input validation for the genre
		{
			cout << "That was an incorrect input Please input either RPG, Classic, FPS, Action, and Strategy!!" << endl;
			cin >> genre;
			
		}
		cout << "\n";

		cout << "Please enter the rating for the new game with values between 1 and 5 " << endl;
		cin >> rating;
		cin.ignore();
		

		while (rating < 1 || rating > 5)   //input validation for the rating
		{
			cout << "That was an incorrect input Please input 1 - 5 ONLY!!" << endl;
			cin >> rating;
			cin.ignore();
			
		}
		cout << "\n";

		cout << "Please enter the attribute of the game of the choices guns, hand to hand, real time, 2D, turn based, and fantasy: ";
		getline(cin, attribute);
	
		
		while (attribute != "guns" && attribute != "hand to hand" && attribute != "real time" && attribute != "2D" && attribute != "turn based" && attribute != "fantasy")  //input validation for the attribute
		{
			cout << "That was an incorrect input Please input any of the correct attributes guns, hand to hand, real time, 2D, turn based, and fantasy!!" << endl;
			cin.ignore();
			getline(cin, attribute);
			
		}
		cout << "\n";

		//fucntion that will store the new game that the admin entered
		driverObj.createNewGame(name, hardware, year, price2, genre, rating, attribute);
		
		
	}
};
#endif




