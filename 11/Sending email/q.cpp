#include <bits/stdc++.h>

using namespace std;

const int G_SIZE = 20005;

int main(){
	
	int N;

	cin >> N;

	for (int t_case = 0; t_case < N; ++t_case){

		//graph[G_SIZE][G_SIZE] = {0};
		map<int, vector<pair<int, int>> > graph;

		int n, m, S, T;
		cin >> n >> m >> S >> T;

		for (int i = 0; i < m; ++i)	{
			int a,b,w;
			cin >> a >> b >> w;

			pair<int, int> pa(b,w);
			pair<int, int> pb(a,w);

			graph[a].push_back(pa);
			graph[b].push_back(pb);
		}

		bool explored[G_SIZE];
		int dist[G_SIZE];
		queue<int> ctrl;

		for (int i = 0; i < n; ++i)	{
			explored[i] = false;
			dist[i] = INT_MAX;
		}

		ctrl.push(S);
		dist[S] = 0;

		int aux;
		while(!ctrl.empty()){
			aux = ctrl.front();
			ctrl.pop();
			explored[aux] = false;

			for (auto & e : graph[aux]) {
				if ( dist[e.first] > dist[aux] + e.second ){
					dist[e.first] = dist[aux] + e.second;
					if (!explored[e.first]){
						explored[e.first] = true;
						ctrl.push(e.first);
					}
				}
			}
		}

		cout << "Case #" << t_case + 1 << ": ";
		if (dist[T] == INT_MAX)
			cout << "unreachable\n";
		else
			cout << dist[T] << endl;

	}	

	return 0;
} 