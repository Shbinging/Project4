#include"algori.h"

int tr[MAXN];
double pi = 3.1415926575;

vector<cp> fft(vector<cp>& f, bool flag, int n){//0 fft 1 ifft
	memset(tr, 0, sizeof(tr));

	For(i, 0, n - 1){
		tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
	}
	For(i, 0, n - 1){
		if (i < tr[i]) swap(f[i], f[tr[i]]);
	}
	for (int p = 2; p <= n; p *= 2){
		int len = p / 2;
		cp tg(cos(2 * pi / p), sin(2 * pi / p));
		if (!flag) tg.y = -tg.y;
		for (int i = 0; i < n; i += p){
			cp buf(1, 0);
			for (int l = i; l < i + len; l++){
				cp tt = buf * f[len + l];
				f[len + l] = f[l] - tt;
				f[l] = f[l] + tt;
				buf = buf * tg;
			}
		}
	}
	return f;
}

vector<cp> fft(const vector<double>& g, bool flag, int n){//1 fft 0 ifft
	vector<cp> f;
	for (int i = 0; i < g.size(); i++){
		f.push_back(cp(g[i], 0));
	}
	For(i, 1, n - g.size()) f.push_back(cp(0, 0));
	return fft(f, flag, n);
}

bool equal(double a, double b){
	if (fabs(a - b) < 1e-7) return 1;
	else return 0;
}