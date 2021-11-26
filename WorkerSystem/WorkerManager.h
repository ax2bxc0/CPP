#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#define FILENAME "employ.txt"
#include"Worker.h"
class WorkerManager {
public:
	WorkerManager();
	~WorkerManager();
	void showMenu();
	void exitSystem();
	void addWorker();
	void saveFile();
	int getWorkerNum();
	void initWorkerArry();
	void showInfo();
	int findWorker(int id);
	void deleteWorker();
	void changeWorker();
	void getWorkerInfo();
	int findWorker(string name);

	int m_WorkerNum;
	Worker** m_WorkerArry;
	bool m_FileIsEmpty;

};