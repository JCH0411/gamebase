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
	/*gameClass();
	gameClass(string gN, string hH, int yG, int pG, string gG, int rG, string aG); // construtor
	string getname();// this function returns the private variable name
	string gethardware();// this function returns the private variable hardware
	int getyear();// this function returns the private variable year
	int getprice(); //this variable returns the private variable price
	string getgenre(); // this function returns the private variable genre
	int getrating(); //this function returns the private variable rating
	string getattribute(); // this function returns the private variable attribute*/

	//constructor to create new game

//variable to store sku of each attribute
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



};

#endif // !
