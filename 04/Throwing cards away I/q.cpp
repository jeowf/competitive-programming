#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;

	while (cin >> n && n != 0){
		deque<int> deck;

		for (int i = 1; i <= n; ++i){
			deck.push_back(i);
		}

		cout << "Discarded cards:";

		while (deck.size() > 1){

			int t = deck.front();
			cout << " " << t;

			if (deck.size() != 2)
				cout << ",";


			deck.pop_front();
			deck.push_back(deck.front());
			deck.pop_front();
		}

		cout << endl;

		cout << "Remaining card: " << deck.front() << endl;

	}

	return 0;
}