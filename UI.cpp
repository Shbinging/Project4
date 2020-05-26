#include "UI.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;

UI::UI()
{
	wrongList[0] = "操作成功";
	wrongList[1] = "非有效长度";
	wrongList[2] = "非有效数字";
	wrongList[3] = "非有效命名";
	wrongList[4] = "命名重复";
	wrongList[5] = "表达式非法";
	wrongList[6] = "无此表达式";
	wrongList[7] = "非有效选择";

}

int UI::read()
{
	int n;
	while (1){
		n = queBoxInt("您要添加的多项式长度为:");
		if (n < 0){
			wrongBox(1);
		}
		else if (n == 0){
			wrongBox(2);
		}
		else break;
	}
	cout << "请按多项式系数从高到低输入每一项,空格隔开:";
	vector<double> a;
	//无效数字为判断
	For(i, 1, n){
		double tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	reverse(a.begin(), a.end());
	string name;
	while (1){
		name = queBoxStr("请给它命名:");
		if (name == ""){
			wrongBox(3);
		}
		else{
			if (data.findP(name).n != 0){
				wrongBox(4);
			}
			else{
				data.addP(p(a, 0, name));
				break;
			}
		}
	}
	wrongBox(0);
	return 0;
}

int UI::calc()
{
	string st;
	while (1){
		st = queBoxStr("请输入表达式:");
		if (data.calc(st).n <= 0){
			wrongBox(5);
		}
		else{
			cout << p(data.calc(st), "ans") << endl;
			break;
		}
	}
	return 0;
}

int UI::print()
{
	string st;
	while (1){
		st = queBoxStr("请输入多项式名字:");
		if (!data.findP(st).n){
			wrongBox(6);
		}
		else{
			cout << data.findP(st) << endl;
			break;
		}
	}
	return 0;
}

int UI::mainUi()
{
	while (1){
		printf("==============多项式计算器V1.0不完全版==============\n1.输入  2.混合运算 6.查看\n====================================================\n");
		int opt = queBoxInt("请输入操作:");
		if (opt <= 0){
			wrongBox(7);
		}
		else{
			switch (opt){
				case 1:
					read();
					break;
				case 2:
					calc();
					break;
				case 6:
					print();
					break;
				default:
					wrongBox(7);
			}
		}
	}
}

int UI::queBoxInt(string st)
{
	cout << st;
	string stRead;
	cin >> stRead;
	if (!data.isDoubleNum(stRead)) return -1000000000;
	return int(data.toDoulbe(stRead));
}

string UI::queBoxStr(string st)
{
	cout << st;
	string stRead;
	cin >> stRead;
#ifdef debug1
	cout << "cout "<< stRead << endl;
#endif // debug1

	return stRead;
}

void UI::wrongBox(int code)
{
	cout << wrongList[code] << endl;
}
