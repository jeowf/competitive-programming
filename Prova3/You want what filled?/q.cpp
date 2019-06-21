#include <bits/stdc++.h>

using namespace std;

int m, n;

typedef pair<int, int> pii;

map<pii, bool> visited;

//tamnho do componente e quantidade
//map<int, int> res;
int aux = 0;

void dfs(pii p, vector<vector<char>> & g, vector<vector<bool>>  & mask, char c){
	aux++;
	int i = p.first;
	int j = p.second;
	mask[i][j] = true;


	if (g[i+1][j] == c and !mask[i+1][j]){
		pii aux(i+1, j);
		dfs(aux, g, mask, c);
	}


	if (g[i-1][j] == c and !mask[i-1][j]){
		pii aux(i-1, j);
		dfs(aux, g, mask, c);
	}

	if (g[i][j+1] == c and !mask[i][j+1]){
		pii aux(i, j+1);
		dfs(aux, g, mask, c);
	} 


	if (g[i][j-1] == c and !mask[i][j-1]){
		pii aux(i, j-1);
		dfs(aux, g, mask, c);
	}



}


vector<pair<char, int>> max_v;

bool comp(pair<char, int> lhs, pair<char, int> rhs){
	if (lhs.second > rhs.second)
		return true;
	else if (lhs.second == rhs.second and lhs.first < rhs.first)
		return true;
	return false;
}

int main(){
	int problem = 1;

	while(cin >> m >> n and m != 0 and n != 0){
		vector<vector<char>> region(m+2, vector<char>(n+2,'.'));
		vector<vector<bool>> mask(m+2, vector<bool>(n+2,false));
		//max_aux = 0;
		aux = 0;

		for (int i = 1; i <=m; ++i)	{
			string str;
			cin >> str;

			for (int j = 1; j <= n; ++j){
				region[i][j] = str[j-1];
			}
		}

		for (int i = 1; i <=m; ++i)	{
			for (int j = 1; j <= n; ++j){
				if (!mask[i][j] and region[i][j] != '.'){
					pii px(i,j);
					dfs(px, region, mask, region[i][j]);
					
					pair<char, int> pmax(region[i][j], aux);
					max_v.push_back(pmax);

					aux = 0;
				}
			}

		}

		sort(max_v.begin(), max_v.end(), comp);
		//if (max_v.size() > 0){
			cout << "Problem " << problem++ << ":\n";
			for(auto & e : max_v){
				cout << e.first << " " << e.second << endl;
			}
		//}
		


		max_v.clear();




	}


	return 0;
}