/*Ramsha Bilal
bilal_week6_ps
Problem set 6
problems.cpp file
PC
*/
#include "problems.h"
#include "Money.h"
#include "SafeArray.h"
#include<iostream>
#include<string>
using namespace std;

//program function to test the Money class
void problem1()
{
	cout << "Testing Money Class" << endl << endl;

	Money wallet1;
	wallet1.setDollarsAndCents(6, 17);
	wallet1.increaseDollarsAndCents(5, 250);
	wallet1.show();
	cout << endl;

	Money wallet2(4, 12);
	wallet2.increaseDollarsAndCents(1.25);
	wallet2.show();
	cout << endl;

	Money wallet3(wallet1);
	wallet3.increaseDollarsAndCents(3.45);
	wallet3.show();
	wallet3.setDollarsAndCents(11, 53);
	wallet3.show();
	cout << endl;

	Money wallet4(5); 
	cout << endl;



}
void problem2()
{
	cout << endl << endl;
	cout << "Testing SafeArray Class: " << endl;
	cout << endl;

	//testing default constructor 
	SafeArray newArray1;     
	cout << endl;

	//testing constructor that takes initializer list
	SafeArray newArray2({ 1, 2, 3, 66 }); 
	cout << endl;

	//testing copy constructor
	SafeArray newArray3(newArray2);
	cout << endl;

	//testing addItems()
	newArray3.addItems(5, 4);
	cout << endl;

	//testing exception for at()
	int returnNum;
	newArray2.at(8); // should throw an exception
	cout << endl;

	//testing addItems(), put() and its exceptions
	newArray1.addItems(5, 9);
	cout << endl;
	newArray1.put(2, 15);    //should put 15 at index 2
	newArray1.put(10, 15); // should throw an exception
	cout << endl;

	//testing at()
	SafeArray newArray4({ 5,10,15,25 });
	cout << endl;
	returnNum = newArray4.at(1); // should be 10
	cout << "Returned number is " << returnNum << endl;

	//testing put()
	int* data;
	data = new int[4];
	data[0] = 5;
	newArray4.put(1, data, 1);
	cout << endl;
	newArray4.put(1, data, 10);
	cout << endl;

	//testing copyTo()
	vector<int>v; 
	SafeArray newArray5({ 1, 2, 3, 4, 5, 6, 7, 8 });
	newArray5.copyTo(v);
	cout << endl;
	cout << "Updated vector: ";
	for (int i : v)
		cout << i << "  ";
	cout << endl;

	//testing size()
	cout << "Size is : " << newArray5.size() << endl;
	cout << endl;

	//testing clear()
	newArray5.clear();
	cout << endl;

}