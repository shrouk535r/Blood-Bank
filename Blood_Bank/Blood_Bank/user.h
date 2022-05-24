#pragma once
#pragma warning(disable : 4996)
#ifndef USER_H
#define USER_H
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
class user
{
protected:
	user();
	 virtual void Register()=0;
	 virtual void update(string id)=0;
	 virtual void Delete(string id)=0;
};
#endif