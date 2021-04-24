// include the /h file to use the vector of games and to access the variables in the game //object

#include <iostream>
#include "driver.h"
#include "gameClass.h"
#include "control.h"
#include "print.h"
#include <string>
#include <vector>
#include <stdlib.h>


class userInterFace // this class is incharge of displaying menu’s and accepting users input
{
	private:

		// value to hold admin input for password

		int password;

		// the driver class object that has a vector of games and functions to inshilse them into that //vector



	public:

		userInterFace()
			{

				void dispM();       // displays the main menu
				void dispGA();      // function to display attribute selection
				void dispH();		// function to display hardware selection 
				void dispGe();		// function to display genre selection 
				void dispY();		// function to display the year selection
				void dispR();		// function to display the ratings selection
				void dispMulti();	// function to display multiple search criteria at once.
				void dispAD();		// Admin login
				void dispADM();		// Admin main menu
				void dispADU();		// Admin update a game menu
				void dispADAdd();	// Admin add a new game me	nu 
			}



		userInterFace()
			{
				int year;
				driver driverObj;
				control searchObj;
				password = 12345678;     // admin password that gets initialized every time program runs this is a temporary value.

				dispM();


			}


	// display main menu
		void dispM()
			{

				// Here we will introduce the first menu for the user to select how they would like to search for games

				cout << "Welcome to GameBase Please select how you would like to search for a game" << endl;
				cout << "For admin please select option 8" << endl;
				int again;
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

					switch (x)
					{ 
						//switch to jump function regarding user input

						case 1: dispGe()	searchObj.compare(driverObj)
							break;
						case 2: dispGA()	searchObj.compare(driverObj)
							break;
						case 3: dispY()		searchObj.compare(driverObj)
							break;
						case 4: dispR()		searchObj.compare(driverObj)
							break;
						case 5: dispP()		searchObj.compare(driverObj)
							break;
						case 6: dispH()		searchObj.compare(driverObj)
							break;
						case 7: dispMulti() searchObj.compare(driverObj)
							break;
						case 8: dispAD();    //This is admin login with password protection 
							break;

							cout << " Would you like to perform another search ? ";
							cin >> again;

					}
				}

				while (again == 'y' || again == 'Y'); //This is the end of the inside of main class

			}





		void dispGA()  //function to display attribute selection
			{
				/*types of attributes: 2D, 3D, guns, fantasy, real time, hand- to-hand */

				int attribute;
				cout << "what attribute would you like to chose : " << endl;
				cout << "1 - Guns" << endl;
				cout << "2 - Hand to Hand" << endl;
				cout << "3 - Real Time" << endl;
				cout << "4 - 2D" << endl;
				cout << "5 - 3D" << endl;
				cout << "6 - Turn Based" << endl;
				cout << "7 - Fantasy" << endl;
				cout << "enter a value 1 - 4" << endl;
				cin >> attribute;

				while (attribute < 1 || attribute > 7 )
					{

					dispGA();

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

				while (hardware < 1 || hardware > 4)
				{
					dispH();
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
				while (genre < 1 || genre > 5)
				{
					dispGe();
				}
				searchObj.createSSGe(genre);

			}


		void dispY()  //function to display the year selection
			{
				int year;

				cout << " * NOTE * : The result shown will be the games released in that particular year or newer " << endl;
				cout << " Enter the year you want to search for: " << endl;

				cin >> year;
				while (year < 1980)
				{
					dispY();
				}
				searchObj.createSSY(year);

			}


		void dispP()  //function to display the price selection
			{
				int price;

				cout << " * NOTE* : The result shown will be the games with the price tag that you choose or lower " << endl;
				cout << " Enter a number you want to search from : " << endl;

				cin >> price;
				while (price < 0)
				{
					dispP();
				}
				searchObj.createSSP(price);

			}

		void dispR() //function to display the rating selection
			{
				int rating;

				cout << " * NOTE* : The result shown will be the games with the rating that you choose or higher " << endl;
				cout << " Enter an answer from 1 - 5 " << endl;

				cin >> rating;
				while (rating < 1 || rating > 5)
				{
					dispR();
				}
				searchObj.createSSR(rating);

			}





		void dispMulti() //function to display all the search criteria at once.
			{
				cout << "Choose all the attributes desired for the game" << endl;
				string gen = "n", year = "n", ratings = "n", price = "n", hardware = "n", attribute = "n";


				cout << "search by genre " << endl;
				cin >> gen;
				while(gen != "Y" && gen != "y" && gen != "n" && gen != "N")
				{
					dispMulti();
				}

				if (gen == "Y" || gen == "y")
				{
					dispGe();
				}


				cout << "search by attribute" << endl;
				cin >> attribute;
				while (attribute != "Y" && attribute != "y" && attribute != "n" && attribute != "N")
				{
					dispMulti();
				}

				if (attribute == "Y" || attribute == "y")
				{
					dispGA();
				}


				cout << " search by year " << endl;
				cin >> year;
				while(year != "Y" && year != "y" && gen != "n" && year != "N")
				{
					dispMulti();
				}

				if (year == "Y" || year == "y")
				{
					dispY();
				}


				cout << "search by ratings" << endl;
				cin >> ratings;
				while(ratings != "Y" && ratings != "y" && ratings != "n" && ratings != "N")
				{
					dispMulti();
				}

				if (ratings == "Y" || ratings == "y")
				{
					dispR();
				}


				cout << "search by price" << endl;
				cin >> price;
				while(price !="Y" && price != "y" && price != "n" && price != "N")
				{
					dispMulti();
				}

				if (price == "Y" || price == "y")
				{
					dispP();
				}


				cout << "search by Hardware" << endl;
				cin >> hardware;
				while(hardware != "Y" && hardware != "y" && hardware != "n" && hardware != "N")
				{
					dispMulti();
				}

				if (hardware == "Y" || hardware == "y")
				{
					dispH();
				}

			}

		void dispAD() // Admin login
			{
				int userPassword = 0;
				do
				{
					cout << "Enter the admin password " << endl;
					cin >> userPassword;

					if (userPassword != password)
					{
						cout << "Sorry that was an incorrect password try again " << endl;
					}
					else
						dispADM();

				}
				while (userPassword != password);	
			}



		void dispADM() // this function is the admins menu
			{
				int  userInput;
				cout << "What would you like to do: " << endl;
				cout << "1 - Updating a game" << endl;
				cout << "2 - adding a game" << endl;
				cin >> userInput;

				while (userInput != 1 && userInput != 2)
				{
					cout << " the input is wrong " << endl;
					cin << userInput;
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
				cout << "For what name of the game to search for " << endl;
				cin >> gName;

				// this tempvector = address of other drivervector unsure of how it will compile

				vector <gameClass>tempVector = getgamevector();
				int x = 0;

				for (x = 0; x > tempVector.size(); x++)
				{

					if (gName == tempVector[x].name)
						break;

				}

				do
				{
					string tempString = "";
					int tempInt = 0;
					cout << " Which attribute would you like to change " << endl;
					cout << " 1. Genre " << endl;
					cout << " 2. Attribute " << endl;
					cout << " 3. Year " << endl;
					cout << " 4. Rating" << endl;
					cout << " 5. Price " << endl;
					cout << " 6. Hardware " << endl;

					//All other attributes are displayed as well.
					cin >> x;

					switch (x)
					{
					case 1:
						cout << "Enter the new genre" << endl;
						cin >> tempString;
						tempVector[x].genre = tempVector.push_back(tempString);
						break;
					case 2:
						cout << "Enter the new attribute" << endl;
						cin >> tempString;
						tempVector[x].attribute = tempVector.push_back(tempString);
						break;
					case 3:
						cout << "Enter the new year" << endl;
						cin >> tempInt;
						tempVector[x].year = tempVector.push_back(tempInt);
						break;
					case 4:
						cout << "Enter the new rating" << endl;
						cin >> tempInt;
						tempVector[x].rating = tempVector.push_back(tempInt);
						break;
					case 5:
						cout << "Enter the new price" << endl;
						cin >> tempInt;
						tempVector[x].price = tempVector.push_back(tempInt);
						break;
					case 6:
						cout << "Enter the new hardware" << endl;
						cin >> tempString;
						tempVector[x].hardware = tempVector.push_back(tempString);
						break;

					}

					string again = "N";
					cout << " Would admin like to update another attribute " << endl;
					cin >> again;



				} while (again == "Y" || again == "y");
			}

			 // this function adds a new game using the admins input and adds it to the game //vector
		void dispADAdd()
			 {
				 string name, hardware, genre, attribute;
				 int year,price,rating;

				 cout << "please enter the new game and its values" << endl;
				 cin << name;
				 cin << hardware;
				 cin << year;
				 cin << price;
				 cin << genre;
				 cin << rating;
				 cin << attribute;




				 driverObj.createnewgame(string name, string hardware, int year, int price, string genre, int rating, string attribute);
			 }






