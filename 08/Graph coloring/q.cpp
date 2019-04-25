#include <bits/stdc++.h>

using namespace std;

const int N = 101;
//bool graph[N][N];


//0 - branco
//1 - preto
int n_white;
int n_black;
int colors[101];
map<int, vector<int> > adj; 


int m; // casos de teste
int n; // nos
int e; // arestas


int mask[101];

void backtracking(){


	return;
}

int main(){


	while (cin >> m){
		/*
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				graph[i][j] = false;
			}
		}*/



		cin >> n >> e;

		for (int i = 0; i < 101; ++i) {
			mask[i] = -1;
			colors[i] = 0;
			n_white = n;
			n_black = 0;
		}

		for (int i = 0; i < e; ++i) {
			int n1;
			int n2;
			cin >> n1 >> n2;
			//graph[n1][n2] = true;
			//graph[n2][n1] = true;

			adj[n1].push_back(n2);
			adj[n2].push_back(n1);

			//nodes[n1] = nodes[n2] = true;

		}




		adj.clear();

	}

	return 0;
}
