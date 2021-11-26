#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Manager.h"

Manager::Manager(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

void Manager::showInfo() {
	cout << "编号：" << m_Id << "\t";
	cout << "姓名：" << m_Name << "\t";
	cout << "岗位：" << getDeptName() << "\t";
	cout << "职责：" << "完成老板分配的任务，并给员工分配任务" << endl;;
}

string Manager::getDeptName() {
	return string("经理");
}