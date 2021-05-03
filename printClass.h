#include <iostream>
#include"driver.h"
#include"gameClass.h"
#ifndef PRINTCLASS_H
#define PRINTCLASS_H
#pragma once
#pragma warning(disable: 4430)
using namespace std;
class printClass
{
public:
	void printgame(driver Obj, int game)
	{
		
		vector<gameClass> tempVector = Obj.getGameVector();
		
		cout << "---------- Your game(s) are--------- " << endl;
		cout << "Name: " << tempVector[game].getname() << endl;
		cout << "Hardware: " << tempVector[game].gethardware() << endl;
		cout << "Rating: " << tempVector[game].getrating()<< endl;
		cout << "Year: " << tempVector[game].getyear()<< endl;
		cout << "Price: $" << tempVector[game].getprice() << endl;
		cout << "Genre: " << tempVector[game].getgenre() << endl;
		cout << "Attribute: " << tempVector[game].getattribute()<< endl;
		cout << "\n";

	}

};











#endif // 
