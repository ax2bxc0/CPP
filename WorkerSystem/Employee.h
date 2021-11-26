#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Worker.h"

class Employee: public Worker 
{
public:
	Employee(int id, string name, int did);
	virtual void showInfo();
	virtual string getDeptName();
};
