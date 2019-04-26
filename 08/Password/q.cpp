#include <bits/stdc++.h>

using namespace std;

int K;
int k;


map<char, int> grid1[5];
map<char, int> grid2[5];
int max_c[5];

int res[5];


bool pass_tree(int n, string password){
	if (n == 5){
		k++;
		if (k == K){
			cout << password << endl;
			return true;
		}
		return false;
	}


	for (auto & e: grid1[n]){
		if (e.second > 0 && grid2[n][e.first] > 0){
			char c = e.first;
			if (pass_tree(n+1,password + c))
				return true;
		}
	}


	return false;

}

int main(){

	int T;

	cin >> T;

	for (int cases = 0; cases < T; cases++){
		for (int i = 0; i < 5; ++i) {
			max_c[i] = 0;
		}

		cin >> K;

		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 5; ++j) {
				char c;
				cin >> c;
				grid1[j][c]++;
			}
		}

		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 5; ++j) {
				char c;
				cin >> c;
				grid2[j][c]++;
			}
		}



		k=0;
		bool res = pass_tree(0,"");
		if (!res)
			cout << "NO" << endl;

		for (int i = 0; i < 5; ++i) {
			grid1[i].clear();
			grid2[i].clear();
		}

	}

	return 0;
}