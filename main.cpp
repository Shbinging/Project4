#include<iostream>
#include<stdio.h>
#include<vector>
#include"UI.h"
#include"p.h"
using namespace std;

int s;
p dfs(p f, int n){
	s++;
	if (n == 1) return p(1 / f.f[0]);
	else{
		p g = dfs(f, (n%2 == 0) ? n / 2: n /2+1);
		p l = g * (p(2.0) + p(-1.0)*f * g);
		vector<double> c;
		c.assign(l.f.begin(), l.f.begin() + n);
		return (p(c));
	}
}

int main(){
	UI a;
	a.mainUi();
	/*
	vector<double> a;
	a.push_back(9);
	a.push_back(7);
	a.push_back(1);
	a.push_back(1);
	//a.push_back(2.4);
	cout << a << endl;
	p b(a);
	vector<double> c;
	c.push_back(6);
	c.push_back(5);
	c.push_back(1);
	p d(c);
	cout << d/b << endl;
	cout << d % b << endl;
	/*
	int NN = 1;
	while (NN < b.n) NN *= 2;
	cout << dfs(b, b.n)<<endl;
	cout << s << endl;
	*/
	return 0;
}