#include "UI.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;
void UI::read()
{
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
	a.pop_back();
	p c(a, 0, "b");
	cout << b << endl;
	cout << c << endl;
	cout << p(b + c, "c") << endl;
//	p b(a, 0, "a");
	//p c(a, 0, "b");

}
