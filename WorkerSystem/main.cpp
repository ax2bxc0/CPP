#include<iostream>
using namespace std;
#include<string>
#include"WorkerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"


int main() {
	//Worker* wk = NULL;
	//wk = new Employee(1, "����", 1);
	//wk->showInfo();
	//delete wk;
	//wk = NULL;

	//wk = new Manger(2, "����", 2);
	//wk->showInfo();
	//delete wk;
	//wk = NULL;

	//wk = new Boss(3, "����", 3);
	//wk->showInfo();
	//delete wk;
	//wk = NULL;

	WorkerManager wm;
	int choice;
	while (true) {
		wm.showMenu();
		cout << endl;
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();
		case 1:
			wm.addWorker();
			break;
		case 2:
			wm.showInfo();
			break;
		case 3:
			wm.deleteWorker();
			break;
		case 4:
			wm.changeWorker();
			break;
		case 5:
			wm.getWorkerInfo();
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			continue;
		}
	}
	system("pause");
	return 0;
}