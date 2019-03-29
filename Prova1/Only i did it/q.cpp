#include <bits/stdc++.h>

using namespace std;

int main(){
	

	int n;
	cin >> n;
	
	int count = 1;

	for (int i = 0; i < n; ++i) {
		map<int,int> f1,f2,f3;
		vector<int> v1,v2,v3;
		bool b1,b2,b3;

		int m, aux;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			cin >> aux;
			f1[aux]++;	
		}

		cin >> m;
		for (int j = 0; j < m; ++j) {
			cin >> aux;
			f2[aux]++;	
		}

		cin >> m;
		for (int j = 0; j < m; ++j) {
			cin >> aux;
			f3[aux]++;	
		}

		int max = 0;

		for (auto & e : f1) {
			int index = e.first;
			if (f2[index] == 0 && f3[index] == 0)
				v1.push_back(index);
		}

		for (auto & e : f2) {
			int index = e.first;
			if (f1[index] == 0 && f3[index] == 0)
				v2.push_back(index);
		}

		for (auto & e : f3) {
			int index = e.first;
			if (f2[index] == 0 && f1[index] == 0)
				v3.push_back(index);
		}

		if (v1.size() > v2.size())
			max = v1.size();
		else 
			max = v2.size();

		if (v3.size() > max) max = v3.size();

		cout << "Case #" << count++ << ":" << endl ;
		if (v1.size() == max) {
			cout << "1 " << v1.size();
			//show(1);
			for (auto & e : v1){
				cout << " " << e;
			}
			cout << endl;
		}
		if (v2.size() == max) {
			cout << "2 " << v2.size();
			for (auto & e : v2){
				cout << " " << e;
			}
			cout << endl;
		}
		if (v3.size() == max) {
			cout << "3 " << v3.size();
			for (auto & e : v3){
				cout << " " << e;
			}
			cout << endl;
		}

	}

	

	return 0;
}