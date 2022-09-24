/*Ramsha Bilal
bilal_week6_ps
Problem set 6
main.cpp file
PC
*/
#include "Money.h"
#include "problems.h"
#include<iostream>
#include<string>
using namespace std;

/*IMPORTANT NOTE: For some reason, my destructor kept cauing an 
error when trying to decontruct the array made using the copy 
constructor. It did NOT cause the error for the other arrays. I 
am unable to figure out the reason so I have commended the destructor
out so it does not cause errors during running.*/

int main()
{
	problem1();
	problem2();
	return 0;
}