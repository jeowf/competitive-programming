#include <iostream>
#include <string>

using namespace std;

int t[3][3] = {0};

int victories(int v){
	int x = 0;

	int sum;
	for (int i = 0; i < 3; ++i){
		sum = 0;
		for (int j = 0; j < 3; ++j)	{
			if (t[i][j] == v)
				sum++;
		}
		if (sum == 3)
			x++;
	}

	for (int i = 0; i < 3; ++i){
		sum = 0;
		for (int j = 0; j < 3; ++j)	{
			if (t[j][i] == v)
				sum++;
		}
		if (sum == 3)
			x++;
	}

	if (t[0][0] == v && t[1][1] == v && t[2][2] == v)
		x++;

	if (t[0][2] == v && t[1][1] == v && t[2][0] == v)
		x++;

	return x;

}

int main(){

	int n;
	cin >> n;


	for (int i = 0; i < n; i++){
		string s;
		int x = 0, o = 0;

		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				t[j][k] = 0;
			}
		}

		for (int j = 0; j < 3; ++j) {
			cin >> s;
			for (int k = 0; k < 3; ++k) {
				if (s[k] == 'X'){
					t[j][k] = 1;
					x++;
				} else if (s[k] == 'O'){
					t[j][k] = -1;
					o++;
				}
			}
		}

		bool p;

		if (x==o){
			if (victories(1) > 0)
				p = false;
			else 
				p = true;

		} else if (x == o+1){
			if (victories(-1) > 0)
				p = false;
			else 
				p = true;
		} else {
			p = false;
		}

		if (p){
			cout << "yes" << endl;
		} else{
			cout << "no" << endl;
		}


	}

	return 0;
}