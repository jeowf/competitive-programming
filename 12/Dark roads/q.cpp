#include <bits/stdc++.h>

using namespace std;

//const int G_SIZE = 200001;


int main(){

	int m, n;


	while(cin >> m >> n and (m!=0 and n!=0)){

		map< int, vector<pair<int, int>> > graph;

		int totalCost = 0;

		for (int i = 0; i < n; i++){
			int x, y, z;
			cin >> x >> y >> z;
			graph[x].push_back(make_pair(y, z));
			graph[y].push_back(make_pair(x, z));

			totalCost += z;
		}





		//prim (pq union find é chato)
		priority_queue< pair<int, int> > pq;
		map<int, bool> mask;
		int minCost = 0;

		mask[0] = 1;
		for (auto & e : graph[0]) 
			if (!mask[e.first])
				pq.push(e);
		
		while(!pq.empty()){

			auto aux = pq.top();
			pq.pop();

			if (!mask[-aux.second]){
				minCost -=  aux.first;

				mask[-aux.second] = 1;
				for (auto & e : graph[-aux.second]) 
					if (!mask[e.first])
						pq.push(e);
			}

		}

		cout << (totalCost - minCost) << endl;


	}

	return 0;

}