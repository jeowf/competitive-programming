#include <bits/stdc++.h>

using namespace std;


int main(){

	int cases;

	cin >> cases;

	for (int c = 0; c < cases; ++c) {
		int street[102][102] = {0};
		street[0][1] = 1;

		int rows, columns;
		cin >> rows >> columns;

		string s;
		getline(cin, s);

		for (int i = 0; i < rows; ++i) {
			int row,col;

			getline(cin, s);
			stringstream ss(s);
			
			ss >> row;

			while (ss >> col)
				street[row][col] = -1;
			
		}




		for (int i = 1; i <= rows; ++i){
			for (int j = 1; j <= columns; ++j){
				
				if (street[i][j] != -1){

					if (street[i][j-1] != -1)
						street[i][j] += street[i][j-1];
					if (street[i-1][j] != -1)
						street[i][j] += street[i-1][j];

				}
			}
		}

		cout << street[rows][columns] << endl;

		if (c < cases-1)
			cout << endl;


	}


	return 0;
}