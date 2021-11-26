#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Employee.h"

Employee::Employee(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

void Employee::showInfo() {
	cout << "编号：" << m_Id << "\t";
	cout << "姓名：" << m_Name << "\t";
	cout << "岗位：" << getDeptName() << "\t";
	cout << "职责：" << "完成经理分配的任务" << endl;;
}

string Employee::getDeptName() {
	return string("员工");
}

