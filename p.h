#pragma once
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include "algori.h"
using namespace std;
class p
{
public:
	p(vector<double> a, int id1, string name1) :n(a.size()), f(a), id (id1), name(name1){}//默认构造
	p(vector<double> a):n(a.size()), f(a){}
	p(int N):n(N){}
	p(const double a){
		n = 1;
		f.push_back(a);
	}//double转换构造
	p(const p& tmp){
		n = tmp.n;
		f.assign(tmp.f.begin(), tmp.f.end());
		name = tmp.name;
		id = tmp.id;
	}//拷贝构造

	
	p(const p& tmp, string name1){
		n = tmp.n;
		f.assign(tmp.f.begin(), tmp.f.end());
		name = name1;
	}

	~p(){
		f.clear();
	}//析构
	p operator * (const p& tmp);

	p operator + (const p& tmp);


	double jiFen(const p&tmp, double l, double r);
	p qiuDao(const p& tmp);

	double xSquare(double a, int n, double x);//系数 次数 取值
	//p operator - (const p& tmp);
	p& operator = (const p& tmp);
	//vector& getf();//获取系数序列
	//int getsum();//获取串*/
	friend vector<cp> fft(vector<double>& f, bool flag, int n);//fft算法
	friend vector<cp> fft(const vector<double>& g, bool flag, int n);
	friend ostream& operator << (ostream& os, const p& tmp);

	string name;//多项式名称
	int id;//多项式编号
	int n;
	vector<double> f;//系数表示
};


ostream& operator << (ostream& os, const p& tmp);