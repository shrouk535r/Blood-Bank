#ifndef UNTITLED63_recipient_H
#define UNTITLED63_recipient_H
#pragma warning(disable : 4996)
#include<iostream>
#include<vector>
#include<map>
#include"person.h"
#include"user.h"
#include"userdata.h"
using namespace std;
class recipient : public user,public person
{

public:

    map<string, int> mp;
    bool a = true;
    int i = 0;
public:

    vector<userdata>v;

public:
    recipient();
    void Login()override;
    void display();
    void request(string bloodf);
    void Run()override;
    void update_bloood(string bloodtype, int rest);
    void readdata(fstream& f, userdata& d)override;
    void writedata(fstream& f, userdata& d)override;
    void Register()override;
    void update(string id)override;
    void Delete(string id)override;
};
#endif