#include "p.h"
#include<algorithm>
p p::operator*(const p& tmp)
{
	int newN = 1;//扩展次数
	int highN = n + tmp.n - 2;//最高次
	for (; newN < highN + 1; newN *= 2);//次数扩展成2的倍数,最高次为n + tmp.n -2;
	vector<cp> a = fft(f, 1, newN);//计算f的点值表达式
	vector<cp> b = fft(tmp.f, 1, newN);//计算f1的点值表达式
	vector<cp> c;
	For(i, 0, newN - 1){
		c.push_back(a[i] * b[i]);
	}
	vector<cp> ans = fft(c, 0, newN);//将乘积转换为系数表达式
	vector<double> ans1;
	For(i, 0, highN) ans1.push_back(ans[i].x/newN);
	return format(p(ans1));
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
	return format(p(a));
}

p p::operator - (const p& tmp)
{
	vector<double> a;
	int n1 = n;
	int n2 = tmp.f.size();
	For(i, 1, max(n1, n2)) a.push_back(0);
	For(i, 0, n1 - 1) a[i] += f[i];
	For(i, 0, n2 - 1) a[i] -= tmp.f[i];
	return format(p(a));
}

p p::operator/(const p& b)
{
	p a(f);
	int n = a.n - 1;
	int m = b.n - 1;
	if (n - m < 0) return p(0.0);
	p revA = reverse(a);
	p revB = reverse(b);
	p revD = mod(niYuan(revB, n - m + 1) * revA, n - m + 1);
	p D = reverse(revD);
	return format(D);
}

p p::operator%(const p& b)
{
	if (n == 1 && b.n == 1) return (p(double(int(f[0]) % int(b.f[0]))));
	p a(f);
	p d = a / b;
	p r = a - d * b;
	return format(r);
}

p p::format(const p& b)
{
	p tmp(b);
	while (tmp.n > 1 && equal(fabs(tmp.f.back()), 0)){
		tmp.n--;
		tmp.f.pop_back();
	}
	return tmp;
}

p p::qiuDao(const p& tmp)
{
	vector<double> g;
	For(i, 0, int(tmp.f.size()) - 2){
		g.push_back(tmp.f[i + 1] * (i + 1));
	}
	if (g.size() == 0) g.push_back(0);
#ifdef debug1
	cout << "1"<< g.size() << endl;
#endif
	return format(p(g));
}

double p::jiFen(const p& tmp, double l, double r)
{
	double ans = 0;
	For(i, 0, int(tmp.f.size()) - 1){
		ans += xSquare(tmp.f[i] / (i + 1), i + 1, r) - xSquare(tmp.f[i] / (i + 1), i + 1, l);
#ifdef  debug2
		cout << xSquare(f[i] / (i + 1), i + 1, r) <<" "<< xSquare(f[i] / (i + 1), i + 1, l) << endl;
#endif //  debug2

	}
	return ans;
}

double p::xSquare(double a, int n, double x)
{
	double ans = 1;
	For(i, 1, n) ans *= x;
	return ans * a;
}

p& p::operator=(const p& tmp)
{
	f.assign(tmp.f.begin(), tmp.f.end());
	n = tmp.n;
	name = tmp.name;
	id = tmp.id;
	return *this;
}

ostream& operator << (ostream& os, const p& tmp){
	os << tmp.name << " = ";
	int N = int(tmp.f.size()) - 1;
#ifdef debug2
	cout << "b:" << N << endl;
#endif
	for (int i = N; i >= 0; i--){
		if (equal(tmp.f[i], 0)&& !equal(N, 0)) continue;
		if (i != N){
			if (tmp.f[i] >= 0) os << " + ";
			else os << " - ";
		}
		else{
			if (tmp.f[i] < 0) os << "-";
		}
		if (!equal(fabs(tmp.f[i]), 1) || i == 0) cout << fabs(tmp.f[i]);
		if (i != 0){ 
			if (i == 1) os << "x";
			else os << "x^" << i; 
		}
	}
	return os;
}

p mod(p tmp, int n)//n是最高次数
{
	int n1 = min(n, tmp.n);
	vector<double> b;
	b.assign(tmp.f.begin(), tmp.f.begin() + n1);
	return p(b);
}

p niYuan(p f, int n)
{
	if (n == 1) return p(1 / f.f[0]);
	else{
		p g = niYuan(f, (n % 2 == 0) ? n / 2 : n / 2 + 1);
		p l = g * (p(2.0) + p(-1.0) * f * g);
		return (mod(p(l),n));
	}
}

p reverse(p tmp)
{
	vector<double> a = tmp.f;
	reverse(a.begin(), a.end());
	return p(a);
}
