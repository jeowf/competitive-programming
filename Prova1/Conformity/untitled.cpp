#include <bits/stdc++.h>

using namespace std;

const int LINE = 10001;
int p[LINE][4];

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
	//getline(cin, s);

	int count = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < LINE; ++j){
			for (int k = 0; k < 4; ++k) {
				p[j][k] = 0;
			}
		}

		int f1 = 0,f2 = 0,f3 = 0;
		int a;
		int b;
		cin >> b;
		for (int j = 0; j < b; ++j)	{
			cin >> a;
			if (p[a][1] == 0){
				p[a][0]++; //Atualiza o total
				p[a][1]++; // atualiza f1;
				f1++;
			}
		}


		cin >> b;
		for (int j = 0; j < b; ++j) {
			cin >> a;
			if (p[a][2] == 0){
				if (p[a][0] == 0){
					f2++;
				} else {
					if (p[a][1] == 1)
						f1--;
					p[a][1] = 2;
					p[a][2] = 2;
				}
				p[a][0]++; //Atualiza o total
				p[a][2]++; // atualiza f2;
			}
		}

		cin >> b;
		for (int j = 0; j < b; ++j) {
			cin >> a;
			if (p[a][3] == 0){
				if (p[a][0] == 0){
					f3++;
				} else {
					if (p[a][1] > 0){
						if (p[a][1] == 1)
							f1--;
						p[a][1] = 2;
						p[a][3] = 2;
					}
					if (p[a][2] > 0){
						if (p[a][2] == 1)
						f2--;
						p[a][3] = 2;
						p[a][2] = 2;
					}
				}
				p[a][0]++; //Atualiza o total
				p[a][3]++; // atualiza f3;
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