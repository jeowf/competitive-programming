#include <bits/stdc++.h>

using namespace std;

const int G_SIZE = 200001;
typedef pair<int, int> node;

class comp {
	public :
    bool operator() (node lhs, node rhs) {
        if (lhs.second > rhs.second)
			return true;

		return false;
    }
};

int main(){

	int m, n;


	while(cin >> m >> n and (m!=0 and n!=0)){

		vector<node> graph[G_SIZE];
		bool mask[G_SIZE];

		int totalCost = 0;

		for (int i = 0; i < m; ++i) {
			mask[i] = false;
		}

		for (int i = 0; i < n; i++){
			int x, y, z;
			cin >> x >> y >> z;
			graph[x].push_back(make_pair(y, z));
			graph[y].push_back(make_pair(x, z));

			totalCost += z;
		}


		//prim (pq union find é chato)
		priority_queue< node, vector<node>, comp> pq;
		
		int minCost = 0;

		mask[0] = 1;
		for (auto & e : graph[0]) {
			if (!mask[e.first]){
				pq.push(e);
				//minCost += e.second;
			}
		}
		
		while(!pq.empty()){

			auto aux = pq.top();
			pq.pop();

			if (!mask[aux.first]){
				minCost +=  aux.second;

				mask[aux.first] = 1;
				for (auto & e : graph[aux.first]) {
					if (!mask[e.first]){
						pq.push(e);
						//minCost += e.second;

					}
				}
			}

		}

		cout << (totalCost -  minCost) << endl;


	}

	return 0;

}