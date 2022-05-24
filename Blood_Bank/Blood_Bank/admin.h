#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include"person.h"
#include <iostream>
#include<regex>
#include<fstream>
#include<string>
#include<queue>
#include"blood.h"
#include"Date.h"
#include"recipient.h"
#include<stdio.h>
#include"userdata.h"
class admin : public person
{
private :
	string email;
	string password;
public:
	queue<userdata>accepted;
	queue<userdata>waiting;
	bool flag = true;
	int ch;
	int ch2;
	Donor D;
	recipient R;
	void deltefile(const char* s);
	void show(queue<userdata>& q);
	void insertfile(queue<userdata>& d, string s);
	void validatedrequest(queue<userdata>& accepted, queue<userdata>& waiting);
	void Login()override;
	bool validatadmin();
	void Run()override;
	void DisplayDonor();
	void DisplayRecipient();
	void readdata(fstream& f, userdata& d)override;
	void writedata(fstream& f, userdata& d)override;
	void insertblood();
	admin();
	~admin();
};
#endif