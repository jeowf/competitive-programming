#include <bits/stdc++.h>

using namespace std;

int main(){

	int v[1001];

	int n;
	cin >> n;
	while(n--){

		int q;
		cin >> q;

		for (int i = 1; i <= q; ++i)	{
			cin >> v[i]; 
		}

		int acc = 1; // valor acumulado
		int n_coins = 2;
		if (q == 1)
			n_coins = 1;

		//int max

		for (int i = 2; i < q; ++i) {
			if (acc + v[i] < v[i + 1]){

				n_coins++;
				acc += v[i];
			}
		}

		cout << n_coins << endl;
	}

	return 0;
}