/*Ramsha Bilal
bilal_week6_ps
Problem set 6
Problem 2
SafeArray.cpp file
PC
*/
#include "SafeArray.h"
#include <initializer_list>
#include<iostream>
#include<string>
using namespace std;

//default constructor
SafeArray::SafeArray() 
{ 
	cout << "Inside default constructor." << endl; 
}

//copy constructor
SafeArray::SafeArray(SafeArray &other)
{
	cout << "Inside copy constructor" << endl;
	m_dynArray = other.getDynArray();
	m_size = other.getSize();
}

//constructor with initializer list
SafeArray::SafeArray(initializer_list<int> integers)
{
	cout << "Inside constructor with initializer list" << endl;
	vector<int> integersv = integers;

	//DEBUG
	cout << endl;
	cout << "Vector contents: ";
	for (int i : integersv)
		cout << i << " ";

	int* startArray;

	int size = integersv.size();
	m_dynArray = new int[size];
	startArray = m_dynArray;
	
	for (int i = 0; i < size; i++)
	{
		*m_dynArray = integersv[i];
		m_dynArray++;
	}
	m_dynArray = startArray;


	//DEBUG
	cout << endl;
	cout << "m_dynArray contents: " << endl;
	for (int i=0;i<size;i++)
		cout << m_dynArray[i] << endl;
	m_dynArray = startArray;

	m_size =size;

	//DEBUG
	cout << endl; 
	cout << "Size is set to " << m_size << endl;
	cout << "Data saved:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *m_dynArray;
		m_dynArray++;
	}
	cout << endl;

	m_dynArray = startArray;
}

//destructor
/*SafeArray::~SafeArray()
{
	cout << "Inside destructor" << endl;
	delete[] m_dynArray;
}
*/
int* SafeArray::getDynArray()
{
	return m_dynArray;
}

/*getSize - used during early development of this
program before I created size()*/
int SafeArray::getSize()
{
	return m_size;
}

//code for size() method - returns m_size
int SafeArray::size()
{
	return m_size;
}

//at() method
int SafeArray::at(int index)
{
	cout << "Inside at()" << endl;

	try {
		if (index >= m_size || index < 0)
		throw (index);

		return m_dynArray[index];
	}

	catch(int num)
	{
		cout << "Index is out of bounds.It must be greater than 0 and less than " << m_size << endl;
		return 0; 
	}
	
	
}

//put() method that takes index and data to insert at that index
void SafeArray::put(int index, int data)
{
	cout << "Inside put()" << endl;
	try {
		if (index >= m_size || index < 0)
			throw (index);
		m_dynArray[index] = data;
		cout << m_dynArray[index] << " is added at index " << index << endl;
	}
	catch (int num)
	{
		cout << "Index is out of bounds. It must be greater than 0 and less than " << m_size << endl;
	}
}

//addItems() method
void SafeArray::addItems(int howMany, int value = 0)
{
	cout << "Inside addItems()" << endl;
	
	int* temp; 
	temp = new int[m_size + howMany];

	for (int c = 0; c < m_size; c++)
	{
		temp[c] = m_dynArray[c];
	}

	for (int i = m_size; i < (m_size + howMany); i++)
		temp[i] = value;

	delete[] m_dynArray;

	m_dynArray = temp;

	m_size += howMany;
	cout << "New size is: " << m_size << endl;

	if (m_dynArray == nullptr)
		cout << "Dynamic memory has not been allocated to m_dynArray yet." << endl;
	else
	{
		for (int c = 0; c < m_size; c++)
		{
			cout << "Value added: " << m_dynArray[c] << endl;
		}

		for (int i = 0; i < m_size; i++)
			cout << m_dynArray[i] << endl;

		cout << endl;
		cout << "Size is " << m_size << endl;
	}
}

//second put() method
void SafeArray::put(int index, int* data, int howMany)
{
	cout << endl << "Inside put(int index, int* data, int howMany)" << endl;
	try 
	{

		for (int i = index; i < index + howMany; i++)
		{
			if (i < 0 || i >= m_size)
				throw(index);

			data[i] = howMany;
		}
	}
	catch (int num) 
	{
		cout << "Error. Access violation. Some index locations are out of bound.";
	}
}

//copyTo() method
void SafeArray::copyTo(vector<int>& v)
{
	cout << "Inside copyTo()" << endl;
	for (int i = 0; i < m_size; i++)
		v.push_back(m_dynArray[i]);
}

//clear() method
void SafeArray::clear()
{
	cout << "Inside clear()" << endl;
	delete[] m_dynArray;
}
