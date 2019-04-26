#include <bits/stdc++.h>

using namespace std;

const int N = 111;
//bool graph[N][N];

int graph[N][N];
int res[N];

int n; // nos
int e; // arestas

int mask[N];

int max_b;

void backtracking(int node){

	if (node > n){

		int blacks = 0;
		for (int i = 1; i <= n; ++i){
			if (mask[i] == 1)
				blacks++;
		
		}

		if (blacks > max_b){
			max_b = blacks;

			int aux = 0;

			for (int i = 1; i <=n; ++i)	{
				if (mask[i] == 1){
					res[aux++] = i;
				}
			}
		}

		return;

	} else {
		mask[node] = 0;
		backtracking(node + 1);
		mask[node] = 1;

		bool cant = false;

		for (int i = 1; i <= n; i++){
			if (graph[i][node] == 1 && mask[i] == 1){
				cant = true;
				break;
			}
		}

		if (!cant)
			backtracking(node+1);

		mask[node] = 0;

	}


	return;
}

int main(){
	int m;

	cin >> m;

	for ( int t_case = 0; t_case < m; t_case++ ){

		for (int i = 0; i < N; ++i) {
			mask[i] = res[i] = 0;
			for (int j = 0; j < N; ++j) {
				graph[i][j] = 0;
			}
		}

		max_b = 0;

		cin >> n >> e;

		for (int i = 0; i < e; ++i) {
			int n1;
			int n2;
			cin >> n1 >> n2;
			graph[n1][n2] = graph[n2][n1] = 1;
		}


		backtracking(1);

		cout << max_b << endl;

		for (int i = 0; i < max_b; ++i) {
			cout << res[i];
			if (i < max_b - 1)
				cout << " ";
		}

		cout << endl;

	}

	return 0;
}
