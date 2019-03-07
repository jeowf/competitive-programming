#include <iostream>
#include <string>

using namespace std;

int main(){

	char big[100][100] = {0};
	char little[100][100]= {0};

	int N, n;



	while (cin >> N >> n && N!=0 && n!=0){
		
		string s;

		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int j = 0; j < N; ++j){
				big[i][j] = s[j];
			}
		}

		for (int i = 0; i < n; ++i){
			cin >> s;
			for (int j = 0; j < n; ++j){
				little[i][j] = s[j];
			}
		}

		bool r1 = true, 
		     r2 = true, 
		     r3 = true, 
		     r4 = true;

		int a1 = 0,
			a2 = 0,
			a3 = 0, 
			a4 = 0;

/*
		for (int k = 0; k < n; ++k) {
			for (int l = 0; l < n; ++l)	{
				cout << little[k][l];
			}
			cout << endl;
		}

		cout << endl;

		for (int k = 0; k < n; ++k) {
			for (int l = 0; l < n; ++l)	{
				cout << little[l][n-k-1];
			}
			cout << endl;
		}
		cout << endl;


		for (int k = 0; k < n; ++k) {
			for (int l = 0; l < n; ++l)	{
				cout << little[n-k-1][n-l-1];
			}
			cout << endl;
		}

		cout << endl;

*/
		

		for (int i = 0; i < N-n+1; ++i) {
			for (int j = 0; j < N-n+1; ++j) {

				for (int k = 0; k < n; ++k) {
					for (int l = 0; l < n; ++l)	{

						if (big[i+k][j+l] != little[k][l]){
							r1 = false;
							//break;
						}

						if (big[i+k][j+l] != little[l][n-k-1]){
							r2 = false;
							//break;
						}

						if (big[i+k][j+l] != little[n-k-1][n-l-1]){
							r3 = false;
							//break;
						}

						if (big[i+k][j+l] != little[n-l-1][k]){
							r4 = false;
							//break;
						}
					}
					
				}

				if (r1) a1++; r1 = true;
				if (r2) a2++; r2 = true;
				if (r3) a3++; r3 = true;
				if (r4) a4++; r4 = true;
			}
		}

		cout << a1 << " " << a4 << " " << a3 << " " << a2 << endl;



	}

	return 0;
}