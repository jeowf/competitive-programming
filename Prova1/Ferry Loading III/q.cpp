#include <bits/stdc++.h>

using namespace std;

const bool left_to_right = true;
const bool right_to_left = false;

struct car{
	int id;
	int t;

	car(int _id, int _t) : id(_id), t(_t){ }
};

int main(){

	int c;
	cin >> c;

	for (int i = 0; i < c; ++i) {
		int n, t, m;
		cin >> n >> t >> m;

		queue< car > left;
		queue< car > right;

		//map<int, queue<int>> cars;
		int count = 0;

		for (int j = 0; j < m; ++j) {
			int x;
			string bank;

			cin >> x >> bank;

			car ca(count++, x);

			if (bank[0] == 'l')
				left.push(ca);
			else
				right.push(ca);
		}

		bool direction = left_to_right;
		//if (!right.empty() && right.front().t < left.front().t)
		//	direction = right_to_left;

		//int a1 = (left.empty()) ? 0 : left.front().t;
		//int a2 = (right.empty()) ? 0 : right.front().t;



		//int actual = (a1 < a2) ? a1 : a2;
		int actual = 0;

		map<int, int> cars;

		while (!left.empty() || !right.empty()){

			int cap = 0;
			if (direction == left_to_right){
				while (cap < n && !left.empty() && left.front().t <= actual){
					cap++;
					cars[left.front().id] = actual + t;
					left.pop();
				}

				if (cap){
					actual += t;
					direction = !direction;
					continue;
				}

				if (right.empty() || (!left.empty() && left.front().t <= right.front().t)){
					actual = left.front().t;
					while(cap < n && !left.empty() && left.front().t <= actual) {
						cap++;
						cars[left.front().id] = actual + t;
						left.pop();
					}
					actual += t;;
				} else {
					if (!right.empty() || left.empty() && left.front().t > right.front().t)
						actual = max(right.front().t, actual) + t;
					else
						actual += t;
				}
			} else {
				while (cap < n && !right.empty() && right.front().t <= actual){
					cap++;
					cars[right.front().id] = actual + t;
					right.pop();
				}

				if (n-cap){
					actual += t;
					direction = !direction;
					continue;
				}

				if (left.empty() || (!right.empty() && right.front().t <= left.front().t)){
					actual = right.front().t;
					while(cap < n && !right.empty() && right.front().t <= actual) {
						cap++;
						cars[right.front().id] = actual + t;
						right.pop();
					}
					actual += t;;
				} else {
					if (!left.empty() || right.empty() && right.front().t > left.front().t)
						actual = max(left.front().t, actual) + t;
					else
						actual += t;
				}
			}

			/*
			int cap = n;
			while (cap > 0){
				if (direction == left_to_right){
					if (!left.empty() && left.front().t <= actual){
						//int t = left.front().t;
						//cout << actual + t << endl;
						cars[left.front().id] = actual + t;
						left.pop();
					} else {
						break;
					}
				} else {
					if (!right.empty() && right.front().t <= actual){
						//int t = right.front().t;
						//cout << actual + t << endl;
						cars[right.front().id] = actual + t;
						right.pop();
					} else {
						break;
					}
				}

				cap--;
			}

			if (left.empty() && right.empty())
				break;

			direction = !direction;

			if (direction == left_to_right){
				if (left.empty()){
					direction = !direction;
				} else if (!right.empty() && right.front().t <= left.front().t){
					actual = right.front().t;
					direction = !direction;

				}
			} else {
				if (right.empty()){
					direction = !direction;
				} else if (!left.empty() && left.front().t <= right.front().t){
					actual = left.front().t;
					direction = !direction;

				}
			}

			actual += t;*/
		}

		for (auto & e : cars){
			cout << e.second << endl;
		}

		cout << endl;



	}

	return 0;
}