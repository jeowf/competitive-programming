#include <bits/stdc++.h>

using namespace std;
const int INF = 9999999;

struct edge{
	int x, y, w;

	edge(){}
	edge(int a, int b, int c) : 
	x(a), y(b), w(c) {}

};

int main(){

	int cases;
	cin >> cases;

	for (int i = 0; i < cases; ++i){
		edge graph[2001];

		int n, m;
		cin >> n >> m;
		int aux = 0;
		for (int i = 0; i < m; ++i){
			int x, y, t;
			cin >> x >> y >> t;
			//graph[x].push_back(make_pair(y, t));
			edge e (x,y,t);
			graph[aux++] = e;
			//graph[y].push_back(make_pair(x, t));
		}

		int dist[1001];

		for (int i = 0; i < n; ++i)	{
			dist[i] = INF;
		}

		dist[0] = 0;
		//ctrl.push(0);

		for (int i = 1; i < n; ++i){
			

			for (int j = 0; j < m; j++) {
				int u = graph[j].x;
				int v = graph[j].y;
				int w = graph[j].w;
				if ( dist[v] > dist[u] + w ){
					dist[v] = dist[u] + w;
					
				}
			}

		}

		bool answer = true;


		for (int j = 0; j < m; j++) {
			int u = graph[j].x;
			int v = graph[j].y;
			int w = graph[j].w;
			if (dist[v] > dist[u] + w){
				answer = false;
				break;
			}
		}


		if (!answer)
			cout << "possible\n";
		else 
			cout << "not possible\n";


	}


	return 0;
}