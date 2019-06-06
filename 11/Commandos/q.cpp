#include <bits/stdc++.h>

using namespace std;

const int G_SIZE = 101;
const int INF = 99999999;
int main(){

	int T;
	int c = 0;

	cin >> T;
	for (int t_cases = 0; t_cases < T; ++t_cases) {
		
		int graph[G_SIZE][G_SIZE];
		for (int i = 0; i < G_SIZE; ++i){
			for (int j = 0; j < G_SIZE; ++j) {
				if (i != j){
					graph[i][j] = INF;
				}
			}
		}

		int n, r;
		int s, d;
		int answer = 0;

		cin >> n >> r;

		for (int i = 0; i < r; ++i) {
			int u, v;
			cin >> u >> v;
			graph[u][v] = graph[v][u] = 1;
		}

		cin >> s >> d;

		for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
		}


		for (int i = 0; i < n; ++i) {
			if (answer < graph[s][i] + graph[i][d])
				answer = graph[s][i] + graph[i][d];
		}

		cout << "Case " << ++c << ": " << answer << endl;
	}

	return 0;
}