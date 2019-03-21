#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, m;

	while(cin >> n >> m && n != 0 && m != 0) {

		map<int, int> cds;

		int total = 0;
		int aux;

		for (int i = 0; i < n; ++i) {
			cin >> aux;
			cds[aux]++;

		}

		for (int i = 0; i < m; ++i) {
			cin >> aux;
			if (cds[aux] == 1)
				total++;
		}

		cout << total << endl;
	}



	return  0;
}