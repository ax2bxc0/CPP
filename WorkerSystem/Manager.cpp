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
	cout << "��ţ�" << m_Id << "\t";
	cout << "������" << m_Name << "\t";
	cout << "��λ��" << getDeptName() << "\t";
	cout << "ְ��" << "����ϰ��������񣬲���Ա����������" << endl;;
}

string Manager::getDeptName() {
	return string("����");
}