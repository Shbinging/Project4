#pragma once
#include"p.h"
#include<stack>
#include<map>
class calculate
{
public:
	calculate();
	struct nodeFh{
		int index;
		string opt;
		nodeFh(int a, string b){
			index = a;
			opt = b;
		}
	};
	struct nodeSz{
		int index;
		p num;
		nodeSz(int a, p b):index(a), num(b){}
	};
	int addP(p tmp);//0 成功 1 重名
	p findP(string name);
	p calc(string st);
	bool isDoubleNum(string st);
	vector<string> split(string st);
	bool isFh(string st);
	stack<nodeFh> fh;
	stack<nodeSz> sz;
	map<string, int> fhClass;
	vector<p> list;
	int popUp(string fh,int index);
	string toStr(char ch);
	double toDoulbe(string st);
};

