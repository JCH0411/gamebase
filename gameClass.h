#include <string>
using namespace std;
#ifndef GAMECLASS_H
#define GAMECLASS_H
#pragma once
#pragma warning(disable: 4430)



class gameClass {

private:
	string name;
	string hardware;
	int year;
	int price;
	string genre;
	int ratings;
	string attribute;

public:
	


    //constructor to give dummy variables
	gameClass()
	{
		name = "";
		hardware = "";
		year = 0;
		price = 0;
		genre = "";
		ratings = 0;
		attribute = "";
	}
	//constructor to create new game
	gameClass(string gN, string hH, int yG, int pG, string gG, int rG, string aG)
	{
		name = gN;
		hardware = hH;
		year = yG;
		price = pG;
		genre = gG;
		ratings = rG;
		attribute = aG;
	}

	//getters to return the attributes of a game for searhces and admin
	string  getname()
	{
		return name;
	}
	string gethardware()
	{
		return hardware;
	}
	int getyear()
	{
		return year;
	}
	int getprice()
	{
		return price;                                  
	}
	string getgenre()
	{
		return genre;
	}
	int getrating()
	{
		return ratings;
	}
	string getattribute()
	{
		return attribute;
	}

	//Setters that will change the values of the gamevector that will be used by the admin
	void setName(string vectorName)
	{
		name = vectorName;
	}
	void setHardware(string vectorHardware)
	{
		hardware = vectorHardware;
	}
	void setYear(int vectorYear)
	{
		year = vectorYear;
	}
	void setPrice(int vectorPrice)
	{
		price = vectorPrice;
	}
	void setGenre(string vectorGenre)
	{
		genre = vectorGenre;
	}
	void setRatings(int vectorRatings)
	{
		ratings = vectorRatings;
	}
	void setAttribute(string vectorAttribute)
	{
		attribute = vectorAttribute;
	}


};

#endif // !
