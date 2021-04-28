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
	void printgame(gameClass Obj)
	{
		cout << "-------- - Your game(s) are-------- " << endl;
		cout << "Name: " << Obj.getname() << endl;
		cout << "Hardware: " << Obj.gethardware() << endl;
		cout << "Rating: " << Obj.getrating() << endl;
		cout << "Year: " << Obj.getyear() << endl;
		cout << "Price: $" << Obj.getprice() << endl;
		cout << "Genre: " << Obj.getgenre() << endl;
		cout << "Attribute: " << Obj.getattribute() << endl;

	}

};











#endif // 
