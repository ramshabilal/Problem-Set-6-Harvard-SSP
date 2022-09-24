/*Ramsha Bilal
bilal_week6_ps
Problem set 6
Problem 1
Money.cpp file
PC
*/
#include "Money.h"
#include<iostream>
#include<string>
using namespace std;

const int MAX_CENTS = 100;

//default constructor
Money::Money()
{
	cout << "Inside default constructor" << endl;
}

/*constructor that takes amount of dollars and
cents as input with cents defaulted to 0. 	*/
Money::Money(int d, int c)
{
	cout << "Inside second constructor (that takes amount of dollars and cents as input with cents defaulted to 0.)" 
		<< endl;
	m_dollars = d;
	m_cents = c;
	if (m_cents >= MAX_CENTS)
	{
		int numOfDollars = m_cents / MAX_CENTS;
		m_dollars += numOfDollars;
		m_cents -= numOfDollars * MAX_CENTS;
	}
	cout << "Dollars are set to " << m_dollars << endl << "Cents are set to " << m_cents << endl; 
}

/*constructor that takes double as parameter and converts appropriately to dollars and cents*/
Money::Money(double inputValue)
{
	cout << "Inside third constructor (that takes double as " 
		<< "parameter and converts appropriately to dollars and cents)" 
		<< endl;
	int inputInto100;
	inputInto100 = inputValue * MAX_CENTS;
	m_dollars = inputInto100 / MAX_CENTS;
	m_cents = (inputValue - m_dollars)*MAX_CENTS;

	cout << "Dollars are set to " << m_dollars
		<< endl
		<< "Cents are set to " << m_cents 
		<< endl; 
}

//copy constructor 
Money::Money(Money& other)
{
	m_dollars = other.getDollars();
	m_cents = other.getCents();
}

//destructor
Money::~Money()
{
	cout << "My wallet is now empty" << endl;
}

//mutators
void Money::setDollarsAndCents(int d, int c)
{
	cout << "Inside first setDollarsAndCents() "
		<< "(that sets the amount of dollars and cents using individual integer values)"
		<< endl;
	m_dollars = d;
	m_cents = c; 
	if (c >= MAX_CENTS)
	{
		int numDollars = m_cents / MAX_CENTS;
		m_dollars += numDollars;
		m_cents -= numDollars * MAX_CENTS;
	}
	cout << "Dollars set to " << m_dollars << endl
		<< "Cents set to " << m_cents << endl;
}

void Money::setDollarsAndCents(double input)
{
	cout << "Inside second setDollarsAndCents() "
		<< "(that takes a double as input and appropriately assigns dollars and cents)" 
		<< endl;
	int inputTo100;
	inputTo100 = input * MAX_CENTS;
	m_dollars = inputTo100 / MAX_CENTS;
	m_cents = (input - m_dollars)*MAX_CENTS;

	cout << "Dollars are set to " << m_dollars
		<< endl
		<< "Cents are set to " << m_cents
		<< endl;
}

void Money::increaseDollarsAndCents(int d, int c)
{
	cout << "Inside first increaseDollarsAndCents()"
		<< " (that takes individual cents and dollars and adds them to existing cents and dollars)" 
		<< endl;
	m_dollars += d;
	m_cents += c; 
	if (m_cents >= MAX_CENTS)
	{
		int numDollarsToAdd = m_cents / MAX_CENTS;
		m_dollars += numDollarsToAdd;
		m_cents -= numDollarsToAdd * MAX_CENTS;
	}
	cout << "Dollars are set to " << m_dollars << endl << "Cents are set to " << m_cents << endl;
}

void Money::increaseDollarsAndCents(double input)
{
	cout << "Inside second increaseDollarsAndCents()"
		<< " (that takes double as input and adds appropriate values to existing cents and dollars)"
		<< endl;
	int dollarsToAdd, centsToAdd;
	int inputx100 = input * 100;
	dollarsToAdd = (inputx100 / MAX_CENTS);
	m_dollars += dollarsToAdd;
	m_cents += (input - dollarsToAdd)*MAX_CENTS;
}

//to display monetary value
void Money::show()
{
	cout << "Inside show()" << endl;
	double total = m_dollars + (static_cast<double>(m_cents) / static_cast<double>(MAX_CENTS));
	cout << "Dollars: " << m_dollars
		<< endl 
		<< "Cents: " << m_cents 
		<< endl
		<< "Total money: " << total 
		<< endl;

}

//accessors
int Money::getDollars()
{
	cout << "Inside getDollars()" << endl;
	return m_dollars;
}

int Money::getCents()
{
	cout << "Inside getCents()" << endl;
	return m_cents;
}
