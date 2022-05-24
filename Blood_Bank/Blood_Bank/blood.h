#pragma once
#include"Donor.h"
#include"Date.h"
#include <iostream>
#include<regex>
#include<fstream>
#include<string>
#include<queue>
#include<stdio.h>
#include<map>
class blood
{
public:
	string type, Rday, quantity, Rmonth, Ryear, Eday, Emonth, Eyear;
	void InsertBlood();
	void updateblood(string btype);
	void deleteblood(string btype);
	blood();
};