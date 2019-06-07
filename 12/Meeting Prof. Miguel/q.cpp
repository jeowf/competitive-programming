#include <bits/stdc++.h>

using namespace std;
const int INF = 9999999;
const int G_SIZE = 30;

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
			int from = (char) a - 65;
			int to = (char) b - 65;
			if (a == 'Y'){
				Y[from][to] = f;
				if (b == 'B')
					Y[to][from] = f;

			} else {
				M[from][to] = f;
				if (b == 'B')
					M[to][from] = f;

			}
		}

		char a,b;
		cin >> a >> b;

		int startY = (int) a - 65;
		int startM = (int) b - 65;

		cout << startY << " " << startM << endl; 

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
		for (int i = 0; i < G_SIZE; ++i){
			if ((Y[startY][i] > 0 and Y[startY][i] < INF) and
				(M[startM][i] > 0 and M[startM][i] < INF)){
				int aux = Y[startY][i] + M[startM][i];
				if (aux < dis){
					city = i;
					dis = aux;
				}
			}
		}

		cout << dis << " " << city << endl;

	}

	return 0;
}