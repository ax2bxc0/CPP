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
	cout << "��ţ�" << m_Id << "\t";
	cout << "������" << m_Name << "\t";
	cout << "��λ��" << getDeptName() << "\t";
	cout << "ְ��" << "��ɾ�����������" << endl;;
}

string Employee::getDeptName() {
	return string("Ա��");
}

