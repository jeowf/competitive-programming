#include <bits/stdc++.h>

using namespace std;
const int INF = 9999999;
const int G_SIZE = 26;

int main(){

	int N;

	char a;
	//cin >> a;
	//cout << (int) a - 65 << endl;

	while(cin >> N && N != 0){

		int Y[G_SIZE][G_SIZE];
		int M[G_SIZE][G_SIZE];

		for (int i = 0; i < G_SIZE; ++i){
			for (int j = 0; j < G_SIZE; ++j){
				if (i != j)
					Y[i][j] = M[i][j] = INF;
				else
					Y[i][j] = M[i][j] = 0;

			}
		}

		for (int i = 0; i < N; ++i) {
			char a, b, c, d;
			int f;
			cin >> a >> b >> c >> d >> f;
			int x = (int) c - 65;
			int y = (int) d - 65;

			//cout << x << " " << y << endl;

			if (a == 'Y'){
				Y[x][y] = f;
				if (b == 'B')
					Y[y][x] = f;

			} else {
				M[x][y] = f;
				if (b == 'B')
					M[y][x] = f;

			}
		}

		char a,b;
		cin >> a >> b;

		int startY = (int) a - 65;
		int startM = (int) b - 65;

		for (int k = 0; k < G_SIZE; ++k){
			for (int i = 0; i < G_SIZE; ++i){
				for (int j = 0; j < G_SIZE; ++j){
					Y[i][j] = min(Y[i][j], Y[i][k] + Y[k][j]);
					M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
				}
			}
		}


		int city = -1;
		int dis = INF;

		for (int i = 0; i < G_SIZE; ++i)
		{
			Y[i][i] = M[i][i] = 0;
		}

		for (int i = 0; i < G_SIZE; ++i){

			if (Y[startY][i] + M[startM][i] < dis){
				dis = Y[startY][i] + M[startM][i];
				city = i;

			}
		}
		
		
		if (city == -1){
			cout << "You will never meet.\n";
		} else {
			cout << dis;
			for (int i = 0; i < G_SIZE; ++i) {
				if (Y[startY][i]+M[startM][i] == dis)
					cout << " " << (char) (i + 65);

			}
			cout << endl;
		}

	}

	return 0;
}