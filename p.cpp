#include "p.h"
#include<algorithm>
p p::operator*(const p& tmp)
{
	int newN = 1;//��չ����
	int highN = n + tmp.n - 2;//��ߴ�
	for (; newN < highN + 1; newN *= 2);//������չ��2�ı���,��ߴ�Ϊn + tmp.n -2;
	vector<cp> a = fft(f, 1, newN);//����f�ĵ�ֵ���ʽ
	vector<cp> b = fft(tmp.f, 1, newN);//����f1�ĵ�ֵ���ʽ
	vector<cp> c;
	For(i, 0, newN - 1){
		c.push_back(a[i] * b[i]);
	}
	vector<cp> ans = fft(c, 0, newN);//���˻�ת��Ϊϵ�����ʽ
	vector<double> ans1;
	For(i, 0, highN) ans1.push_back(ans[i].x/newN);
	return p(ans1);
}

p p::operator+(const p& tmp)
{
	vector<double> a;
	int n1 = n;
	int n2 = tmp.f.size();
	for (int i = 0; i < min(tmp.f.size(), f.size()); i++){
		a.push_back(f[i] + tmp.f[i]);
	}
	if (n2 > n1){
		for (int i = n1; i < n2; i++){
			a.push_back(tmp.f[i]);
		}
	}
	else{
		for (int i = n2; i < n1; i++){
			a.push_back(f[i]);
		}
	}
	return p(a);
}

ostream& operator << (ostream& os, const p& tmp){
	os << tmp.name << " = ";
	int N = int(tmp.f.size()) - 1;
	for (int i = N; i >= 0; i--){
		if (equal(tmp.f[i], 0)) continue;
		if (i != N){
			if (tmp.f[i] >= 0) os << " + ";
			else os << " - ";
		}
		if (!equal(tmp.f[i], 1) || i == 0) cout << fabs(tmp.f[i]);
		if (i != 0) os << "x^" << i;
	}
	return os;
}