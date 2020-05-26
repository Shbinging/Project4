#pragma once
#ifndef algori
#define algori
#include<vector>
#include <algorithm>
#include<math.h>
#include"diag.h"
#include<string.h>
using namespace std;
struct cp{
	double x, y;
	cp(double xx = 0, double yy = 0){
		x = xx;
		y = yy;
	}
	cp(const cp& tmp){
		x = tmp.x;
		y = tmp.y;
	}
	cp operator + (cp const& tmp) const{
		return cp(x + tmp.x, y + tmp.y);
	}
	cp operator - (cp const& tmp) const{
		return cp(x - tmp.x, y - tmp.y);
	}
	cp operator * (cp const& tmp) const{
		return cp(x * tmp.x - y * tmp.y, x * tmp.y + y * tmp.x);
	}
};


vector<cp> fft(vector<cp>& f, bool flag, int n);

vector<cp> fft(const vector<double>& g, bool flag, int n);

bool equal(double a, double b);
#endif