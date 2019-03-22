#include <bits/stdc++.h>

using namespace std;


int show(int x){
	for (int i = 0; i < LINE; i++){
		if (p[i][x] == 1)
			cout << " " << i;
	}
	cout << endl;
}

int main(){
	

	int n;
	cin >> n;
	string s;

	int count = 1;

	for (int i = 0; i < n; ++i) {
		map<int,int> p, m1,m2,m3;
		int f1 = 0,f2 = 0,f3 = 0;
		int a;
		int b;

		vector<int> v1,v2,v3;

		cin >> b;
		for (int j = 0; j < b; ++j)	{
			cin >> a;
			p[a]++;
			m1[a]++;
		}

		cin >> b;
		for (int j = 0; j < b; ++j)	{
			cin >> a;
			p[a]++;
			m2[a]++;

		}

		cin >> b;
		for (int j = 0; j < b; ++j)	{
			cin >> a;
			p[a]++;
			m3[a]++;
		}


		for (auto & e : p){
			if (m1[e.first] ==1){
				v1.push_back(e.first);
			}

			if (m2[e.first] ==1){
				v2.push_back(e.first);
			}

			if (m2[e.first] ==1){
				v2.push_back(e.first);
			}
		}

		bool v1 = false,v2 = false,v3 = false;
		vector<int> aux;
		aux.push_back(f1);
		aux.push_back(f2);
		aux.push_back(f3);

		sort(aux.begin(), aux.end());
		if (f1 == aux[2]) v1 = true;
		if (f2 == aux[2]) v2 = true;
		if (f3 == aux[2]) v3 = true;

		cout << "Case #" << count++ << ":" << endl ;
		if (v1) {
			cout << "1 " << f1;
			show(1);
		}
		if (v2) {
			cout << "2 " << f2;
			show(2);
		}
		if (v3) {
			cout << "3 " << f3;
			show(3);
		}



	}

	return 0;
}