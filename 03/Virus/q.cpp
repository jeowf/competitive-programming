#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int n;

	while (cin >> n){


		vector<int> v(n);
		int sum = 0;

		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < n/2; i++)
		{
			sum += v[n-1-i] - v[i];
		}

		cout << sum << endl;

	}

}