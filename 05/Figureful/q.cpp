#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;

	map< pair<int, int>, string > girls;


	for (int i = 0; i < n; ++i) {
		pair<int, int> code;
		string name;
		cin >> code.first >> code.second;
		cin >> name;

		girls[code] = name;
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		pair<int, int> code;
		cin >> code.first >> code.second;
		string name = girls[code];

		cout << name << endl;
	
	}


	return  0;
}