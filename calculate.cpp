#include "calculate.h"
#define Down(i, r, l) for(int i = r; i >=l; i--)
calculate::calculate()
{
	fhClass["+"] = 1;
	fhClass["*"] = 2;
	//fhClass["("] = 9;
	fhClass[")"] = -2;
	fhClass["("] = -3;
	fhClass["@"] = -1;
	fhClass["$"] = 4;
	fhClass["["] = 5;
	fhClass[","] = 6;
	fhClass["]"] = 7;
	fhClass["!"] = 8;
}
int calculate::addP(p tmp)
{
	if (findP(tmp.name).n == 0){
		list.push_back(tmp);
		return 0;
	}
	else return -1;
}

p calculate::findP(string name)
{
	For(i, 0, int(list.size()) - 1){
#ifdef debug1
		cout << list[i].name << endl;
#endif // 
		if (list[i].name == name)
			return list[i];
	}

	return p(0);
}

p calculate::calc(string st)//-1 无此多项式
{
	st += "@";
	vector<string> a = split(st);
	For(i, 0, int(a.size()) - 1){
		if (!isFh(a[i])){
			if (isDoubleNum(a[i])) sz.push(nodeSz(i, p(toDoulbe(a[i]))));
			else{
				if (findP(a[i]).n == 0) return p(-1);
				sz.push(nodeSz(i, findP(a[i])));
			}
		}
		else{
			if (a[i] == "("){
				fh.push(nodeFh(i, a[i]));
				continue;
			}
			int opt = popUp(a[i], i);
			if (opt == -2) return p(-2);
			//
			if (a[i] == ")"){
				if (fh.empty() || fh.top().opt != "("){
					return p(-2);
				}
				else fh.pop();
			}
			//
			if (a[i] != "@" && a[i] != ")") fh.push(nodeFh(i, a[i]));
		}
	}
	if (sz.empty() || !fh.empty()) return p(-2);
	p ans = sz.top().num;
	sz.pop();
	if (!sz.empty()) return p(-2);
	else return ans;

}

bool calculate::isDoubleNum(string st)
{
	For(i, 0, int(st.size()) - 1){
		if (!('0' <= st[i] && st[i] <= '9' || st[i] == '.')) return 0;
	}
	return 1;
}

vector<string> calculate::split(string st)
{
	string subSt;
	vector<string> optList;
	For(i, 0, int(st.size()) - 1){
		if (isFh(toStr(st[i]))){
			if (subSt != "") optList.push_back(subSt);
			optList.push_back(toStr(st[i]));
			subSt = "";
		}
		else{
			subSt += st[i];
		}
	}
	return optList;
}

bool calculate::isFh(string st)
{
	return fhClass.count(st);
}

int calculate::popUp(string curFh, int index)
{
	while (!fh.empty() && fhClass[curFh] <= fhClass[fh.top().opt]){
		string oldFh = fh.top().opt;
		int oldFhIndex = fh.top().index;
		if (oldFh == "+"){
			if (sz.empty()) return -2;
			p b = sz.top().num;
			int bIndex = sz.top().index;
			sz.pop();
			if (sz.empty()) return -2;
			p a = sz.top().num;
			int aIndex = sz.top().index;
			sz.pop();
			if (!(aIndex < oldFhIndex && oldFhIndex < bIndex)) return -2;
			fh.pop();
			sz.push(nodeSz(bIndex, a + b));
		}
		else
			if (oldFh == "*"){
				if (sz.empty()) return -2;
				p b = sz.top().num;
				int bIndex = sz.top().index;
				sz.pop();
				if (sz.empty()) return -2;
				p a = sz.top().num;
				int aIndex = sz.top().index;
				sz.pop();
				if (!(aIndex < oldFhIndex && oldFhIndex < bIndex)) return -2;
				fh.pop();
				sz.push(nodeSz(bIndex, a * b));
			}
			else
				if (oldFh == "!"){
					if (sz.empty()) return -2;
					p a = sz.top().num;
					int aIndex = sz.top().index;
					if (!(aIndex < oldFhIndex)) return -2;
					fh.pop();
					sz.pop();
					sz.push(nodeSz(oldFhIndex, a.qiuDao(a)));
				}
				else
					if (oldFh == "]"){
						fh.pop();
						if (fh.empty()) return -2;
						if (fh.top().opt != ",") return -2;
						fh.pop();
						if (fh.empty()) return -2;
						if (fh.top().opt != "[") return -2;
						fh.pop();
						if (fh.empty()) return -2;
						if (fh.top().opt != "$") return -2;
						fh.pop();
						//不严格的匹配检查
						double l, r;
						if (sz.empty()) return -2;
						p a = sz.top().num;
						int aIndex = sz.top().index;
						sz.pop();
						if (sz.empty()) return -2;
						r = sz.top().num.f[0];
						sz.pop();
						if (sz.empty()) return -2;
						l = sz.top().num.f[0];
						sz.pop();
						if (!(oldFhIndex < aIndex)) return -2;
						sz.push(nodeSz(aIndex, p(a.jiFen(a, l, r))));
					}
					else
						if (oldFh != "(") return -2;
						/*
						if (oldFh == "("){
							if (curFh == ")") fh.pop();
							else return 0;
						}
						else return -2;
						*/
	}
	return 0;
}

string calculate::toStr(char ch)
{
	string st;
	st.push_back(ch);
	return st;
}

double calculate::toDoulbe(string st)
{
	int position = st.find(".");
	string zSt, fSt;
	if (position == -1){
		zSt = st;
		fSt = "";
	}
	else{
		zSt = st.substr(0, position);
		fSt = st.substr(position + 1);
	}
	double sumz = 0, sumf = 0;
	For(i, 0, int(zSt.size()) - 1){
		sumz = sumz * 10 + zSt[i] - '0';
	}
	Down(i, int(fSt.size()) - 1, 0){
		sumf = sumf * 1.0 / 10.0 + fSt[i] - '0';
	}
	sumf /= 10.0;
	return sumz + sumf;
}
