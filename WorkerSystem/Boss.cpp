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
	cout << "��ţ�" << m_Id << "\t";
	cout << "������" << m_Name << "\t";
	cout << "��λ��" << getDeptName() << "\t";
	cout << "ְ��" << "����������˾" << endl;;
}

string Boss::getDeptName() {
	return string("�ϰ�");
}