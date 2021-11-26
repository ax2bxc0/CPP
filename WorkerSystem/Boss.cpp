#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Boss.h"

Boss::Boss(int id, string name, int did) {
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}

void Boss::showInfo() {
	cout << "编号：" << m_Id << "\t";
	cout << "姓名：" << m_Name << "\t";
	cout << "岗位：" << getDeptName() << "\t";
	cout << "职责：" << "管理整个公司" << endl;;
}

string Boss::getDeptName() {
	return string("老板");
}