#pragma once
#include"p.h"
#include"calculate.h"
class UI
{
public:
	UI();
	int read();
	int calc();
	int print();
	int mainUi();
	calculate data;
	int queBoxInt(string st);
	string queBoxStr(string st);
	void wrongBox(int code);
	map<int, string> wrongList;
};

