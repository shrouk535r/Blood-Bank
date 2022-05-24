#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<regex>
#include<fstream>
#include<sstream>
#include<string>
#include<queue>
#include<chrono>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include"Date.h"
#include"userdata.h"
using namespace std;
class person
{
protected:
	virtual void Login() = 0;
	virtual void Run() = 0;
	virtual void readdata(fstream& f, userdata& d)=0;
	virtual void writedata(fstream& f, userdata& d)=0;
	bool isValidmail(const string& email);
};

