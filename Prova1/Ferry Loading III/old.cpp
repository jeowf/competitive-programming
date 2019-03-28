#include <bits/stdc++.h>

using namespace std;

const bool left_to_right = true;
const bool right_to_left = false;

int main(){

	int c;
	cin >> c;

	for (int i = 0; i < c; ++i) {
		int n, t, m;
		cin >> n >> t >> m;

		priority_queue<int, vector<int>, greater<int> > left;
		priority_queue<int, vector<int>, greater<int> > right;

		for (int j = 0; j < m; ++j) {
			int x;
			string bank;

			cin >> x >> bank;
			if (bank[0] == 'l')
				left.push(x);
			else
				right.push(x);
		}

		bool direction = left_to_right;
		//if (!right.empty() && right.top() < left.top())
		//	direction = right_to_left;

		int a1 = (left.empty()) ? 0 : left.top();
		int a2 = (right.empty()) ? 0 : right.top();



		int actual = (a1 < a2) ? a1 : a2;
		//int actual = 0;

		map<int, queue<int>>

		while (!left.empty() || !right.empty()){
			int cap = n;
			while (cap > 0){
				if (direction == left_to_right){
					if (!left.empty() && left.top() <= actual){
						//int t = left.top();
						cout << actual + t << endl;
						left.pop();
					} else {
						break;
					}
				} else {
					if (!right.empty() && right.top() <= actual){
						//int t = right.top();
						cout << actual + t << endl;
						right.pop();
					} else {
						break;
					}
				}

				cap--;
			}

			direction = !direction;
			actual += t;
		}

		cout << endl;



	}

	return 0;
}