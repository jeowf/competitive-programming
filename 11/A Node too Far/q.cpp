#include <bits/stdc++.h>

using namespace std;

int main(){

	int NC;

	int c = 1;

	while(cin >> NC and NC != 0){

		//cout << NC << endl;
		map<int, vector<int>> graph;
		map<int, bool> gamb;
		//int n_nodes = 0;

		for (int i = 0; i < NC; ++i) {
			int a, b;
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);

			gamb[a] = gamb[b] = true;
		}

		int node, ttl;
		int reachable;

		while (cin >> node >> ttl){

			reachable = 1;
			map<int, int> visited;
			queue<int> ctrl;

			if (node == 0 and ttl == 0)
				break;
			
			ctrl.push(node);
			visited[node] = 1;



			if (ttl > 0){

				while(!ctrl.empty()){

					for (auto & e : graph[ctrl.front()]) {
						if (visited[e] == 0 and visited[ctrl.front()] < ttl){

							ctrl.push(e);
							visited[e] = visited[ctrl.front()] + 1;

						} 
					}

					ctrl.pop();

				}


			}

			reachable = visited.size();

			if (ttl == 0 and !gamb[node])
				reachable = 0;

			// if (c == 142){
			// 	cout << " - 142 --- \n";

			// 	for (auto & e : graph){
			// 		for ( auto & f : e.second ) {
			// 			cout << e.first << "-" << f << ", ";
						
			// 		}
			// 		cout << endl;
			// 	}

			// 	cout << " ---- \n\n";

			// }

			int n_nodes = gamb.size();

			//cout << n_nodes << " " << reachable << endl;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", c++, (n_nodes - reachable), node, ttl);
			//printf("  TOTAL: %d, REACH: %d\n", gamb.size(), reachable);


		}


	}

	return 0;
}