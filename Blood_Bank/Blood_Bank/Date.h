#pragma once
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
class Date
{
public:
	int d;
	int m;
	int y;
	Date() {}
	Date(string day, string month, string year);
	int countleabyears();
	long long diffbetwenndates(Date dt);
	bool validate();
	Date countexpirydate(Date d, int n);
};
