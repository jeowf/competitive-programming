#include <bits/stdc++.h>

using namespace std;

int m, n;

typedef pair<int, int> pii;

map<pii, bool> visited;

//tamnho do componente e quantidade
//map<int, int> res;
int aux = 0;
int max_aux = 0;

void dfs(pii node, map<pii, vector<pii>> & G){
	aux++;

	visited[node] = true;
	for(int i = 0; i < G[node].size(); i++){
		if (visited[G[node][i]] == false)
			dfs(G[node][i], G);
	}
}

int main(){
	while(cin >> m >> n){
		vector<vector<char>> region(m+2, vector<char>(n+2,'w'));

		for (int i = 1; i <=m; ++i)	{
			string str;
			cin >> str;

			for (int j = 1; j <= n; ++j){
				region[i][j] = str[j-1];
			}
		}

		int a,b;
		cin >> a >> b;

		map<pii, vector<pii>> G;

		for (int i = 1; i <=m; ++i)	{
			for (int j = 1; j <= n; ++j){
				
				if (region[i][j] == 'l'){
					pii p(i,j);
					for (int x = i - 1; x <= i; x++){
						if (region[x][j] == 'l'){
							pii p2(x,j);
							G[p].push_back(p2);
							G[p2].push_back(p);
						}
					}

					for (int y = j - 1; y <= j+1; y++)	{
						if (region[i][y] == 'l'){
							pii p2(i,y);
							G[p].push_back(p2);
							G[p2].push_back(p);
						}
					}
				}
			}
		}

		for (auto e : G){
			visited[e.first] = false;
		}

		pii pk(a+1,b+1);
		dfs(pk, G);

		aux = 0;

		for (auto e : visited){

			if (!e.second){
				dfs(e.first, G);
				//cout << aux << endl;
				//res[aux]++;
				if (aux > max_aux)
					max_aux = aux;
				aux = 0;
			}
		}
		//cout << max_aux << endl;
		cout << max_aux << endl;
		//visited.clear();
		max_aux = 0;


	}


	return 0;
}