#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	int l;

	while(cin >> n and n!=0){

		vector<int> graph[500];

		cin >> l;

		for (int i = 0; i < l; ++i) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);

			//cout << a << " " << b << endl;
		}

		bool answer = true;
		int colors[500] = {0};

		colors[0] = 1;

		queue<int> ctrl;

		for(auto & e : graph[0]){
			ctrl.push(e);
			colors[e] = 2;
		}


		while(!ctrl.empty()){
			for(auto & e : graph[ctrl.front()]){
				if (colors[e] == 0){
					ctrl.push(e);
					if (colors[ctrl.front()] == 1)
						colors[e] = 2;
					else
						colors[e] = 1;
				} else if ( colors[e] == colors[ctrl.front()] ){
					answer = false;
					break;
				}
				
			}

			ctrl.pop();

		}

		if (answer)
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.\n";

	}


	return 0;
}