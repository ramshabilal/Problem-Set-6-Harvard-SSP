/*Ramsha Bilal
bilal_week6_ps
Problem set 6
Problem 2
SafeArray.h file
PC
*/
#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H

#include <initializer_list>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class SafeArray
{
private:
	int* m_dynArray;
	int m_size;
public:
	SafeArray();
	SafeArray(SafeArray& other);
	SafeArray(initializer_list<int> integers);

	//destructor
	//SafeArray();

	//accessors
	int* getDynArray();
	int getSize();

	int size();
	

	//mutators 
	int at(int index);
	void put(int index, int data);
	void addItems(int howMany, int value);

	void put(int index, int* data, int howMany);
	void copyTo(vector<int>& v);
	void clear();
};

#endif
