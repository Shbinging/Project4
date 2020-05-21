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
	p(vector<double> a, int id1, string name1) :n(a.size()), f(a), id (id1), name(name1){}//Ĭ�Ϲ���
	p(vector<double> a):n(a.size()), f(a){}
	p(const double a){
		n = 1;
		f.push_back(a);
	}//doubleת������
	p(const p & tmp){
		n = tmp.n;
		f.assign(tmp.f.begin(), tmp.f.end());
	}//��������
	p(const p& tmp, string name1){
		n = tmp.n;
		f.assign(tmp.f.begin(), tmp.f.end());
		name = name1;
	}
	~p(){
		f.clear();
	}//����
	p operator * (const p& tmp);

	p operator + (const p& tmp);

	//p operator - (const p& tmp);
	//p& operator = (const p& tmp);
	//vector& getf();//��ȡϵ������
	//int getsum();//��ȡ��*/
	friend vector<cp> fft(vector<double>& f, bool flag, int n);//fft�㷨
	friend vector<cp> fft(const vector<double>& g, bool flag, int n);
	friend ostream& operator << (ostream& os, const p& tmp);
private:
	string name;//����ʽ����
	int id;//����ʽ���
	int n;
	vector<double> f;//ϵ����ʾ
};


ostream& operator << (ostream& os, const p& tmp);