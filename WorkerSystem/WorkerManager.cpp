#pragma once
#include"WorkerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		m_WorkerNum = 0;
		m_WorkerArry = NULL;
		m_FileIsEmpty = true;
	}
	else {
		char ch;
		ifs >> ch;
		if (ifs.eof()) {
			m_WorkerNum = 0;
			m_WorkerArry = NULL;
			m_FileIsEmpty = true;
		}
		else {
			m_WorkerNum = getWorkerNum();
			m_WorkerArry = new Worker * [m_WorkerNum];
			initWorkerArry();

		}
	}
	ifs.close();
}

WorkerManager::~WorkerManager() {
	if (m_WorkerArry != NULL) {
		delete[] m_WorkerArry;
		m_WorkerArry = NULL;
	}
}

void WorkerManager::showMenu() {
	cout << "****************************" << endl;
	cout << "** 欢迎使用职工管理系统！ **" << endl;
	cout << "****** 0.退出管理系统 ******" << endl;
	cout << "****** 1.添加职工信息 ******" << endl;
	cout << "****** 2.显示职工信息 ******" << endl;
	cout << "****** 3.删除离职职工 ******" << endl;
	cout << "****** 4.修改职工信息 ******" << endl;
	cout << "****** 5.查找职工信息 ******" << endl;
	cout << "****** 6.按照编号排序 ******" << endl;
	cout << "****** 7.清空所有信息 ******" << endl;
	cout << "****************************" << endl;
}

void WorkerManager::exitSystem() {
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addWorker() {
	int add_Num = 0;
	cout << "请输入添加职工数量：" << endl;
	cin >> add_Num;
	if (add_Num > 0) {
		int new_Size = add_Num + m_WorkerNum;
		Worker** new_WorkerArry = new Worker*[new_Size];
		if (m_WorkerNum != 0) {
			for (int i = 0; i < m_WorkerNum; i++) {
				new_WorkerArry[i] = m_WorkerArry[i];
			}
		}
		for (int i = 0; i < add_Num; i++) {
			cout << "请输入第" << i+1 << "个用户的编号" << endl;
			int temp_Id;
			cin >> temp_Id;
			cout << "请输入第" << i+1 << "个用户的姓名" << endl;
			string temp_Name;
			cin >> temp_Name;
			cout << "请输入第" << i+1 << "个用户的岗位" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			int temp_Did;
			cin >> temp_Did;

			Worker* temp_wk= NULL;
			switch (temp_Did)
			{
			case 1:
				temp_wk = new Employee(temp_Id, temp_Name, temp_Did);
				break;
			case 2:
				temp_wk = new Manager(temp_Id, temp_Name, temp_Did);
				break;
			case 3:
				temp_wk = new Boss(temp_Id, temp_Name, temp_Did);
				break;
			default:
				cout << "输入有误！" << endl;
				break;
			}
			new_WorkerArry[m_WorkerNum + i] = temp_wk;
			cout << "第" << i + 1 << "个用户添加成功！" << endl;
 		}
		m_WorkerNum = new_Size;
		delete[] m_WorkerArry;
		m_WorkerArry = new_WorkerArry;
		WorkerManager::saveFile();
		m_FileIsEmpty = false;
	}
	else {
		cout << "输入有误！" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::saveFile() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//ofs << "编号\t姓名\t\t部门\t" << endl;
	for (int i = 0; i < m_WorkerNum; i++) {
		ofs << m_WorkerArry[i]->m_Id << "\t";
		ofs << m_WorkerArry[i]->m_Name << "\t\t";
		ofs << m_WorkerArry[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::getWorkerNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::initWorkerArry() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int idx = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* wk = NULL;
		if (dId == 1) {
			wk = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			wk = new Manager(id, name, dId);
		}
		else {
			wk = new Boss(id, name, dId);
		}
		m_WorkerArry[idx] = wk;
		idx++;
	}
	ifs.close();
}

void WorkerManager::showInfo() {
	if (m_FileIsEmpty) {
		cout << "记录为空！" << endl;
	}
	else {
		cout << "总共有" << m_WorkerNum << "名职工" << endl;
		for (int i = 0; i < m_WorkerNum; i++) {
			m_WorkerArry[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::findWorker(int id) {
	cout << "请输入职工编号" << endl;
	int idx = -1;
	for (int i = 0; i < m_WorkerNum; i++) {
		if (m_WorkerArry[i]->m_Id == id) {
			idx = i;
			break;
		}
	}
	return idx;
}

int WorkerManager::findWorker(string name) {
	cout << "请输入职工编号" << endl;
	int idx = -1;
	for (int i = 0; i < m_WorkerNum; i++) {
		if (m_WorkerArry[i]->m_Name == name) {
			idx = i;
			break;
		}
	}
	return idx;
}

void WorkerManager::deleteWorker() {
	if (m_FileIsEmpty) {
		cout << "记录为空！" << endl;
	}
	else {
		cout << "请输入要删除的职工编号" << endl;
		int id;
		cin >> id;
		int idx = findWorker(id);
		if (idx != -1) {
			for (int i = idx; i < m_WorkerNum; i++) {
				//delete m_WorkerArry[i];
				m_WorkerArry[i] = m_WorkerArry[i + 1];
			}
			m_WorkerNum--;
			cout << "职工删除成功" << endl;
			saveFile();
		}
		else {
			cout << "职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::changeWorker() {
	if (m_FileIsEmpty) {
		cout << "记录为空！" << endl;
	}
	else {
		cout << "请输入要修改的职工编号" << endl;
		int id;
		cin >> id;
		int idx = findWorker(id);
		if (idx != -1) {
			cout << "修改前职工信息为：" << endl;
			m_WorkerArry[idx]->showInfo();

			int id;
			string name;
			int dId;
			cout << "请输入职工编号" << endl;
			cin >> id;
			cout << "请输入职工姓名" << endl;
			cin >> name;
			cout << "请输入职工岗位" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> dId;

			Worker* worker = NULL;
			switch (dId)
			{
			case 1:
				worker = new Employee(id, name, dId);
				break;
			case 2:
				worker = new Manager(id, name, dId);
				break;
			case 3:
				worker = new Boss(id, name, dId);
				break;
			default:
				break;
			}
			delete m_WorkerArry[idx];
			m_WorkerArry[idx] = worker;
			cout << "职工修改成功" << endl;
			saveFile();
		}
		else {
			cout << "职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::getWorkerInfo(){
	if (m_FileIsEmpty) {
		cout << "记录为空！" << endl;
	}
	else {
		cout << "请输入查找方式：" << endl;
		cout << "1. 按照职工编号查找" << endl;
		cout << "2. 按照职工姓名查找" << endl;
		int choice;
		cin >> choice;
		int idx;
		if (choice == 1)
		{
			cout << "请输入职工编号" << endl;
			int id;
			cin >> id;
			idx = findWorker(id);
			if (idx != -1) {
				m_WorkerArry[idx]->showInfo();
			}
			else {
				cout << "查无此人！" << endl;
			}
		}
		else if (choice == 2) {
			cout << "请输入职工姓名" << endl;
			string name;
			cin >> name;
			idx = findWorker(name);
			if (idx != -1) {
				m_WorkerArry[idx]->showInfo();
			}
			else {
				cout << "查无此人！" << endl;
			}
		}
		else {
			cout << "输入有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}