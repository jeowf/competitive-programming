#include <bits/stdc++.h>

using namespace std;

int main(){


	int n;

	while (cin >> n){

		map<int, int> m;
		stack < pair<int, int> > v;
		int order = 1;

		bool error = false;

		bool qu = true, 
			 st = true, 
			 pr = true;

		int op, x;

		for (int i = 0; i < n; ++i) {
			cin >> op >> x;
			if (op == 1){
				m[x] = order++;

				pair<int, int> p;
				p.first = x; // value
				p.second = m[x]; // ordem de entrada

				v.push(p);

			} else {
				if (m[x] == 0)
					error = true;
				//order--;
				m[x] = 0;
				
				pair<int, int> aux, next;
				if (!v.empty()){
					aux = v.top();
					v.pop()
					if (!v.empty()){
						next = v.top();

						if (v[i-1].second < v[i].second)
							st = false;
						if (v[i-1].second > v[i].second)
							qu = false;
						if (v[i-1].first < v[i].first)
							pr = false;
					}


				}

					
				

				v.pop_back();

			}
		}

		/*for (int i = 0; i < v.size(); ++i)
			{
				cout << v[i].first << " ";
			}
			cout << endl;*/

		if (!error){

			/*if (v.size() != order-1){
				qu = st = false;
			}*/

			if (qu && !st && !pr){
				cout << "queue" << endl;
			} else if (st && !qu && !pr){
				cout << "stack" << endl;

			} else if (pr && !qu && !st){
				cout << "priority queue" << endl;

			} else if (!pr && !st && !qu){
				cout << "impossible" << endl;
				//impossivel
			} else {
				cout << "not sure" << endl;

			}
		} else {
			cout << "impossible" << endl;
			
		}

		

	}

	return 0;
}