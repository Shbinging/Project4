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
	calculate a;
	cout << a.calc("1+2*3") <<  endl;
	//a.calc("($[0,2.1](F*G))!");
}
