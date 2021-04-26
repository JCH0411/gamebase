#include <string>
#ifndef GAMECLASS_H_
#define GAMECLASS_H
using namespace std;
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
	void gameclass(string gN, string hH, int yG, int pG, string gG, int rG, string aG); // construtor 
	string getname();// this function returns the private variable name
	string gethardware();// this function returns the private variable hardware
	int getyear();// this function returns the private variable year
	int getprice(); //this variable returns the private variable price
	string getgenre(); // this function returns the private variable genre
	int getrating(); //this function returns the private variable rating
	string getattribute(); // this function returns the private variable attribute

	//constructor to create new game
};
//variable to store sku of each attribute
void gameClass::gameclass(string gN, string hH, int yG, int pG, string gG, int rG, string aG)
{
	name = gN;
	hardware = hH;
	year = yG;
	price = pG;
	genre = gG;
	ratings = rG;
	attribute = aG;
}
string gameClass:: getname()
{
	return name;
}
string gameClass::gethardware()
{
	return hardware;
}
int gameClass::getyear()
{
	return year;
}
int gameClass::getprice()
{
	return price;
}
string gameClass::getgenre()
{
	return genre;
}
int gameClass::getrating()
{
	return ratings;
}
string gameClass::getattribute()
{
	return attribute;
}








#endif // !
