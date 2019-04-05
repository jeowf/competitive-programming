#include <bits/stdc++.h>

using namespace std;

int main(){
	int v[1001];
	int sums[1100000];
	int n;

	int c = 1;

	while (cin >> n && n != 0){
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		int aux = 0;
		for (int i = 0; i < n; ++i)	{
			for (int j = 0; j < n; ++j)	{
				if (i!=j)
					sums[aux++] = v[i] + v[j]; 
			}
		}

		cout << "Case " << c++ << ":" << endl;
		int m;
		cin >> m;
		
		for (int i = 0; i < m; ++i) {
			int min = 210001;
			int q;
			cin >> q;
		
			for (int j = 0; j < aux; ++j)	{
				if (abs(q-sums[j]) < abs(q-min)) 
					min = sums[j];
			}

			cout << "Closest sum to " << q << " is " << min << "." << endl;
		}




	}

	return 0;
}