#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> graph;
bool mask[200];
int visited = 0;

void dfs(int st){
	// visited++;
	// mask[st] = true;
	for(auto & e : graph[st]){
		if (!mask[e]){
			mask[e] = true;
			visited++;
			dfs(e);
		}
	}
}

int main(){

	int n;

	while(cin >> n and n != 0){


		int start_v;
		//int v_count = 0;
		while (cin >> start_v and start_v != 0){

			int end_v;

			while(cin >> end_v and end_v != 0){
				graph[start_v].push_back(end_v);
			}
		}

		int n_queries;
		cin >> n_queries;

		for (int i = 0; i < n_queries; ++i) {
			//cout << "opa";

			for (int j = 1; j <= n; ++j)
				mask[j] = false;
			visited = 0;

			int x;
			cin >> x;

			dfs(x);

			cout << (n-visited);

			for (int j = 1; j <= n; j++){
				if (!mask[j])
					cout << " " << j; 
			}
			cout << endl;

		}

		graph.clear();

	}

	return 0;
}