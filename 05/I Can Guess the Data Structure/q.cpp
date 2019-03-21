#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;

	while (cin >> n){

		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;


		bool qu = true, 
			 st = true, 
			 pr = true;

		int op, v;

		for (int i = 0; i < n; ++i) {
			cin >> op >> v;

			if (op == 1){
				if (qu) q.push(v);
				if (st) s.push(v);
				if (pr) pq.push(v);

			} else {
				if (qu) {
					if (q.empty() || q.front() != v)
						qu = false;
					else
						q.pop();
				}

				if (st) {
					if (s.empty() || s.top() != v)
						st = false;
					else
						s.pop();
				}
				
				if (pr) {
					if (pq.empty() || pq.top() != v)
						pr = false;
					else
						pq.pop();
				}
			}
		}


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
		
	}

	return 0;
}