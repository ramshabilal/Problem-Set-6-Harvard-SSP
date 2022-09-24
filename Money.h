/*Ramsha Bilal
bilal_week6_ps
Problem set 6
Problem 1
Money.h file
PC
*/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private: 
	int m_dollars;
	int m_cents;

public:
	//default constructor
	Money();

	/*constructor that takes amount of dollars and
	cents as input with cents defaulted to 0. 	*/
	Money(int d, int c=0);

	/*constructor that takes double as parameter and converts appropriately to dollars and cents*/
	Money(double inputValue);
 
	//copy constructor 
	Money(Money& other);

	//destructor
	~Money();

	//mutators
	void setDollarsAndCents(int d, int c);
	void setDollarsAndCents(double input);
	void increaseDollarsAndCents(int d, int c);
	void increaseDollarsAndCents(double input);

	//to display monetary value
	void show();

	//accessors
	int getDollars();
	int getCents();
};

#endif

