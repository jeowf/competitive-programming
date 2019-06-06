#include <bits/stdc++.h>

using namespace std;

const int G_SIZE = 101;

int main(){

	int c = 0;
	int a,b;

	while( cin >> a >> b and (a != 0 and b != 0)){

		int graph[G_SIZE][G_SIZE];
		for (int i = 0; i < G_SIZE; ++i){
			for (int j = 0; j < G_SIZE; ++j){
				graph[i][j] = 999999;
			}
		}

		graph[a][b] = 1;

		while(cin >> a >> b and (a != 0 and b != 0)){
			graph[a][b] = 1;
		}

		for (int k = 1; k < G_SIZE; ++k){
			for (int i = 1; i < G_SIZE; ++i){
				for (int j = 1; j < G_SIZE; ++j){
					graph[i][j] = min(graph[i][j], 
						              graph[i][k] +
						              graph[k][j]);
				}
			}
		}

		int total = 0;
		int qtd = 0;

		for (int i = 1; i < G_SIZE; ++i){
			for (int j = 1; j < G_SIZE; ++j){
				if (graph[i][j] != 999999 and i != j){
					//cout << graph[i][j] << endl; 
					qtd++;
					total += graph[i][j];
				}
			}
		}

		float res = (float) total / qtd;
		//cout << total << " " << qtd << endl;
		printf("Case %d: average length between pages = %.3f clicks\n", ++c, res);

	}


	return 0;
}