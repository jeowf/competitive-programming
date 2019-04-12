#include <bits/stdc++.h>

using namespace std;

int a_min = 5000;
int start[8];
int refs[8];

bool check_conflict(int r, int c){
	for (int j = 0; j < c; ++j) {
		int i = refs[j];
		if (i == r) return false; //linha
		int v_dist = abs(r - i);
		int h_dist = abs(j - c);
		if (v_dist == h_dist) //diagonal
			return false;
	}

	return true;
}

void backtrack(int c){
	for (int i = 0; i < 8; ++i) {
		if (check_conflict(i, c)){
			refs[c] = i;
			if (c < 7){
				backtrack(c+1);
			} else {
				int aux = 0;
				for (int j = 0; j < 8; ++j) {
					if(refs[j] != start[j])
						aux++;
				}

				if (aux < a_min) 
					a_min = aux;
			}
		}
	}
}

int main(){

	string s;
	int n_case = 1;
	while (getline(cin, s) && s.size() > 0){
		istringstream line(s);

		int c = 0;
		int r;
		while ( line >> r){
			start[c] = r-1;
			refs[c++] = r-1;

		}

		a_min = 5000;
		backtrack(0);

		cout << "Case " << n_case++ << ": " << a_min << endl;
	}


	return 0;
}