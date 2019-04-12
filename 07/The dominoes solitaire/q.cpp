#include <bits/stdc++.h>

using namespace std;

int N, M;
pair<int, int> first_d, last_d, dominoes[30];
bool mask[30];

bool find_sequence(int n, int next){

	if (n == N){
		if (next == last_d.first) 
			return true;
		else 
			return false;
	}

	for (int i = 0; i < M; ++i) {
		if (!mask[i] && (dominoes[i].first == next || dominoes[i].second == next ) ) {

			mask[i] = true;

			bool answer;

			if (dominoes[i].first == next)
				answer = find_sequence(n + 1, dominoes[i].second);
			else
				answer = find_sequence(n + 1, dominoes[i].first);

			if ( answer) return true;

			mask[i] = false;
		
		}

	}

	return false;

}


int main(){

	while (cin >> N && N != 0){
		cin >> M;

		cin >> first_d.first >> first_d.second 
		    >> last_d.first >> last_d.second;

		for (int i = 0; i < M; ++i) {
			cin >> dominoes[i].first >> dominoes[i].second;
			mask[i] = false;
		}

		if (find_sequence(0, first_d.second))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


	}

	return 0;
}