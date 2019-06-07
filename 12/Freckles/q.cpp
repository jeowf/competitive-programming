#include <bits/stdc++.h>

using namespace std;

//const int G_SIZE = 101;

struct edge{
	int to;
	double d;

	edge() {}
	edge(int a, double e) :
	to(a),d(e) {}
};

struct node{
	double x, y;

	node() {}
	node(double a, double b) :
	x(a), y(b) {}
};

class comp {
	public :
    bool operator() (edge lhs, edge rhs) {
        if (lhs.d > rhs.d)
			return true;

		return false;
    }
};

float distance(node a, node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
}

node nodes[101];
vector<edge> graph[101];
bool mask[101];
priority_queue< edge, vector<edge>, comp> pq;
double minCost = 0;

int main(){

	int C;
	cin >> C;

	for (int t = 0; t < C; ++t) {



		int n;
		cin >> n;

		for (int i = 0; i < n; ++i){
			double x,y;
			cin >> x >> y;
			node n(x,y);
			nodes[i] = n;
			mask[i] = false;
			if (!graph[i].empty())
				graph[i].clear();

		}

		for (int i = 0; i < n; ++i)	{
			for (int j = 0; j < n; ++j) {
				if(i != j){
					auto dist = distance(nodes[i], nodes[j]);

					edge e1(j, dist);
					edge e2(i, dist);

					graph[i].push_back(e1);
					graph[j].push_back(e2);
				}
			}
		}


		//prim é vida
		minCost = 0;

		mask[0] = 1;
		for (auto & e : graph[0]) {
			if (!mask[e.to]){
				pq.push(e);
				//cout << e.to << endl;
				//minCost += e.second;
			}
		}
		
		while(!pq.empty()){

			auto aux = pq.top();
			pq.pop();

			if (!mask[aux.to]){
				minCost +=  aux.d;
				mask[aux.to] = 1;
				for (auto & e : graph[aux.to]) {
					if (!mask[e.to]){
						pq.push(e);
						//minCost += e.second;

					}
				}
			}

		}

		printf("%.2lf\n", minCost);
		if (t!=C-1)
			cout << endl;
		
	}


	return 0;
}