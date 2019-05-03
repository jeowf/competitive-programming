#include <bits/stdc++.h>

using namespace std;

const int MAX = 10001;

int main(){

	int squares[MAX];

	for (int i = 0; i < MAX; ++i)
		squares[i] = i;

	for (int i = 1; i*i < MAX; ++i) 
		squares[i*i] = 1;
	

	//cout << squares[2] << endl;

	for (int i = 2; i < MAX; ++i) {
		

		if (squares[i] != 1){
			int aux = 100000;

			for (int j = 1; j*j < i; ++j){
				if (aux > 1 + squares[i - j*j])
					aux = 1 + squares[i - j*j];
			}

			squares[i] = aux;
			
		}
	}

	int cases;
	cin >> cases;

	for (int i = 0; i < cases; ++i)	{ 		
		int N;
		cin >> N;
		cout << squares[N] << endl;
	}

	return 0;
}