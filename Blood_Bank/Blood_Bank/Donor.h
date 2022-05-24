#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include<regex>
#include<vector>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include"Date.h"
#include <chrono>
#include<sstream>
#include<queue>
#include"person.h"
#include"user.h"
#include"userdata.h"
using namespace std;
class Donor : public user,public person
{
public:
    queue<userdata>accepted;
    queue<userdata>waiting;
    vector<userdata>v;
    void DonationRequest(fstream& DonorReq, vector<userdata>& vec, int& i);
    void Login() override;
    void Run()override;
    void readdata(fstream& f, userdata& d)override;
    void writedata(fstream& f, userdata& d)override;
    void Register() override;
    void update(string id) override;
    void Delete(string id) override;
    Donor();
};

