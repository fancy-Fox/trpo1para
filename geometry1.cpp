#include <bits/stdc++.h>
using namespace std
struct circle {
	double x,y,r;
};
struct triangle {
	vector <pair<double,double>> aaa(4);
};
bool checkcorectness (string type) {
	return (type=="circle" || type=="triangle"); 
}
void Coutri (triangle& buf) {
	for (int i=0; i<4; i++) {
		cout << buf.aaa[i].first << ' ' << buf.aaa[i].second << endl;
	}
}
double imposible (string s, int a, int b) {
	bool q=0;

	double x;
	int i=a,y,c=0;
	if (s[i]=='-') {
		q=1;
		i++;
	}
	x=s[i]-'0';
	i++;
	while (i<b) {
		if (s[i]>='0' && s[i]<='9') {
			x=x*10+(s[i]-'0');
		}
		if (s[i]=='.') {
			y=i;
			c++;
		}
		i++;	
	}
	if (c!=0)		
		x=x/pow(10,i-y-1);
	if (q) 
		x=x*(-1);
	//cout << x << endl;
	return x;
}

pair<double,double> koordinata (string s, int a, int b) {
	pair<double,double> x;
	int h,i;
	h=a;
	while (i<s.size() && s[i]!=' ') {
		i++;
	} 
	x.first=imposible(s,h,i);
	h=i+1;
	while (i<s.size() && i<b) {
		i++;
	}
	x.second=imposible(s,h,i);
	return x;
}

int main () {
	vector <circle> cir;
	vector <triangle> tri;
	while (1) {
		string s;
		getline (cin, s);
		if (s.empty()) 
			break;
		int i=0;
		string type="";
		while (i<s.size() && s[i]!='(') {
			type+=s[i];
			i++;
		}
		if (!checkcorectness(type)) {
			cout << "wrong format";
			continue;
		} 
		if (type=="circle") {
			circle puf;
			int a,b;
			a=i+1;
			while (i<s.size() && s[i]!=' ') {
				i++;
			}
			puf.x=imposible(s,a,i);
			a=i+1;

			while (i<s.size() && s[i]!=',') {
				i++;
			}
			puf.y=imposible(s,a,i);
			a=i+2;
			while (i<s.size() && s[i]!=')') {
				i++;
			}
			puf.r=imposible(s,a,i);
			cir.push_back(puf);
		}
		if (type=="triangle") {
			int i=0,y=0;
			double x=0;
			bool q=0;
			vector <int> mas;
			while (i<s.size() && s[i]!=')') {
				while (i<s.size() && s[i]!=',') {
					x=0;
					y=0;
					q=0;
					while (i<s.size() && s[i]!=' ') {
						if (s[i]=='-') q=1;
						if (s[i]>='0' && s[i]<='9') {
							x=x*10+s[i]-'0';
						}
						if (s[i]=='.') y=i;
						i++;
					}
					i++;
					if (y!=0) x=x/pow(10,i-y-1);
					if (q) x=x*(-1);
					mas.push_back(x);
				} 
				i++;
			}
			triangle buf;
			for (int i=0; i<4; i++) {
				buf.aaa[i].first=mas[i];
				buf.aaa[i].second=mas[i+1];
			}
							// buf.a.first=mas[0]; 
							// buf.a.second=mas[1]; 
							// buf.b.first=mas[2]; 
							// buf.b.second=mas[3]; 
							// buf.c.first=mas[4]; 
							// buf.c.second=mas[5]; 
							// buf.d.first=mas[6]; 
							// buf.d.second=mas[7]; 
			tri.push_back(buf);
			Coutri(buf);
			// cout << buf.a.first << ' ' << buf.a.second << ' ' << buf.b.first << ' ' << buf.b.second << ' ' << buf.c.first;
			// cout << ' ' << buf.c.second << ' ' << buf.d.first << ' ' << buf.d.second;
		}


	}
}