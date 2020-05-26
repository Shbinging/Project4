#include "UI.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;

UI::UI()
{
	wrongList[0] = "�����ɹ�";
	wrongList[1] = "����Ч����";
	wrongList[2] = "����Ч����";
	wrongList[3] = "����Ч����";
	wrongList[4] = "�����ظ�";
	wrongList[5] = "���ʽ�Ƿ�";
	wrongList[6] = "�޴˱��ʽ";
	wrongList[7] = "����Чѡ��";

}

int UI::read()
{
	int n;
	while (1){
		n = queBoxInt("��Ҫ��ӵĶ���ʽ����Ϊ:");
		if (n < 0){
			wrongBox(1);
		}
		else if (n == 0){
			wrongBox(2);
		}
		else break;
	}
	cout << "�밴����ʽϵ���Ӹߵ�������ÿһ��,�ո����:";
	vector<double> a;
	//��Ч����Ϊ�ж�
	For(i, 1, n){
		double tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	reverse(a.begin(), a.end());
	string name;
	while (1){
		name = queBoxStr("���������:");
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
		st = queBoxStr("��������ʽ:");
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
		st = queBoxStr("���������ʽ����:");
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
		printf("==============����ʽ������V1.0����ȫ��==============\n1.����  2.������� 6.�鿴\n====================================================\n");
		int opt = queBoxInt("���������:");
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
