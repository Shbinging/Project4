#include "UI.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;
void UI::read()
{
	/*
	int n;
	cin >> n;
	vector<double> a;
	For(i, 1, n){
		double tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	reverse(a.begin(), a.end());
	p b(a, 0, "a");
	calculate data;
	cout << b << endl;
	cout << data.addP(b) <<endl;
	cout << data.findP("a") << endl;
	cout << data.addP(b) << endl;
	*/
	vector<double> b;
	b.push_back(3);
	b.push_back(2);
	b.push_back(1);
	p a(b, 0, "F");
	cout << a << endl;
	b.clear();
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	p c(b, 0, "G");
	cout << c << endl;
	calculate d;
	d.addP(a);
	d.addP(c);
	//cout << d.calc("f+g!") <<  endl;
	string st;
	cin >> st;
	cout << d.calc(st) << endl;
	//a.calc("($[0,2.1](F*G))!");
}
