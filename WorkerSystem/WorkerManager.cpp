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
	cout << "** ��ӭʹ��ְ������ϵͳ�� **" << endl;
	cout << "****** 0.�˳�����ϵͳ ******" << endl;
	cout << "****** 1.���ְ����Ϣ ******" << endl;
	cout << "****** 2.��ʾְ����Ϣ ******" << endl;
	cout << "****** 3.ɾ����ְְ�� ******" << endl;
	cout << "****** 4.�޸�ְ����Ϣ ******" << endl;
	cout << "****** 5.����ְ����Ϣ ******" << endl;
	cout << "****** 6.���ձ������ ******" << endl;
	cout << "****** 7.���������Ϣ ******" << endl;
	cout << "****************************" << endl;
}

void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addWorker() {
	int add_Num = 0;
	cout << "���������ְ��������" << endl;
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
			cout << "�������" << i+1 << "���û��ı��" << endl;
			int temp_Id;
			cin >> temp_Id;
			cout << "�������" << i+1 << "���û�������" << endl;
			string temp_Name;
			cin >> temp_Name;
			cout << "�������" << i+1 << "���û��ĸ�λ" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
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
				cout << "��������" << endl;
				break;
			}
			new_WorkerArry[m_WorkerNum + i] = temp_wk;
			cout << "��" << i + 1 << "���û���ӳɹ���" << endl;
 		}
		m_WorkerNum = new_Size;
		delete[] m_WorkerArry;
		m_WorkerArry = new_WorkerArry;
		WorkerManager::saveFile();
		m_FileIsEmpty = false;
	}
	else {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::saveFile() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//ofs << "���\t����\t\t����\t" << endl;
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
		cout << "��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "�ܹ���" << m_WorkerNum << "��ְ��" << endl;
		for (int i = 0; i < m_WorkerNum; i++) {
			m_WorkerArry[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::findWorker(int id) {
	cout << "������ְ�����" << endl;
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
	cout << "������ְ�����" << endl;
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
		cout << "��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "������Ҫɾ����ְ�����" << endl;
		int id;
		cin >> id;
		int idx = findWorker(id);
		if (idx != -1) {
			for (int i = idx; i < m_WorkerNum; i++) {
				//delete m_WorkerArry[i];
				m_WorkerArry[i] = m_WorkerArry[i + 1];
			}
			m_WorkerNum--;
			cout << "ְ��ɾ���ɹ�" << endl;
			saveFile();
		}
		else {
			cout << "ְ��������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::changeWorker() {
	if (m_FileIsEmpty) {
		cout << "��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "������Ҫ�޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;
		int idx = findWorker(id);
		if (idx != -1) {
			cout << "�޸�ǰְ����ϢΪ��" << endl;
			m_WorkerArry[idx]->showInfo();

			int id;
			string name;
			int dId;
			cout << "������ְ�����" << endl;
			cin >> id;
			cout << "������ְ������" << endl;
			cin >> name;
			cout << "������ְ����λ" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
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
			cout << "ְ���޸ĳɹ�" << endl;
			saveFile();
		}
		else {
			cout << "ְ��������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::getWorkerInfo(){
	if (m_FileIsEmpty) {
		cout << "��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1. ����ְ����Ų���" << endl;
		cout << "2. ����ְ����������" << endl;
		int choice;
		cin >> choice;
		int idx;
		if (choice == 1)
		{
			cout << "������ְ�����" << endl;
			int id;
			cin >> id;
			idx = findWorker(id);
			if (idx != -1) {
				m_WorkerArry[idx]->showInfo();
			}
			else {
				cout << "���޴��ˣ�" << endl;
			}
		}
		else if (choice == 2) {
			cout << "������ְ������" << endl;
			string name;
			cin >> name;
			idx = findWorker(name);
			if (idx != -1) {
				m_WorkerArry[idx]->showInfo();
			}
			else {
				cout << "���޴��ˣ�" << endl;
			}
		}
		else {
			cout << "��������" << endl;
		}
	}
	system("pause");
	system("cls");
}