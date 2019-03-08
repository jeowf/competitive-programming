#include <bits/stdc++.h>
using namespace std;

int main(){

	int v[200000];

	int n;
	cin >> n;

	float aux = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		aux += v[i];
	}

	aux /= n;

	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		if (v[i] - aux <= 5.0)
			count++;
	}

	cout << count << endl;

	return 0;
}