#include <bits/stdc++.h>

using namespace std;

int m, n;

typedef pair<int, int> pii;

map<pii, bool> visited;

//tamnho do componente e quantidade
//map<int, int> res;
int aux = 0;
int max_aux = 0;

// void dfs(pii node, map<pii, vector<pii>> & G){
// 	aux++;

// 	visited[node] = true;
// 	for(int i = 0; i < G[node].size(); i++){
// 		if (visited[G[node][i]] == false)
// 			dfs(G[node][i], G);
// 	}
// }

void dfs(pii p, vector<vector<char>> & g, vector<vector<bool>>  & mask, char c){
	aux++;
	int i = p.first;
	int j = p.second;
	mask[i][j] = true;

	if (g[(i+1)][j] == c and !mask[(i+1)][j]){
		pii aux((i+1), j);
		dfs(aux, g, mask, c);
	}

	if (g[(i-1)][j] == c and !mask[(i-1)][j]){
		pii aux((i-1), j);
		dfs(aux, g, mask, c);
	}

	if (g[i][(j+1)] == c and !mask[i][(j+1)]){
		pii aux(i, (j+1));
		dfs(aux, g, mask, c);
	} 

	if (g[i][(j-1)] == c and !mask[i][(j-1)]){
		pii aux(i, (j-1));
		dfs(aux, g, mask, c);
	}


}


int main(){
	while(cin >> m >> n){
		vector<vector<char>> region(m+2, vector<char>(n+2,'.'));
		vector<vector<bool>> mask(m+2, vector<bool>(n+2,false));
		max_aux = 0;
		aux = 0;

		for (int i = 1; i <=m; ++i)	{
			string str;
			cin >> str;

			for (int j = 1; j <= n; ++j){
				region[i][j] = str[j-1];
			}
		}

		int a,b;
		cin >> a >> b;


		pii pk(a+1,b+1);
		char c = region[a+1][b+1];
		//cout << c << endl;
		dfs(pk, region, mask, c);
		aux = 0;
		
		for (int i = 1; i <=m; ++i)	{
			for (int j = 1; j <= n; ++j){
				if (region[i][j] == c and !mask[i][j]){
					pii px(i,j);
					dfs(px, region, mask, c);
					if (aux > max_aux)
						max_aux = aux;
					aux = 0;
				}
			}
		}

		cout << max_aux << endl;

	}


	return 0;
}