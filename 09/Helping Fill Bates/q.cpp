#include <bits/stdc++.h>

using namespace std;


int main(){


	string s;
	cin >> s;

	int queries;
	cin >> queries;

	for (int c = 0; c < queries; c++){

		
		int answer_ini = -1, answer_end = -1;

		string q;
		cin >> q;

		int q_it = 0; // query iterator
		int s_it = 0; // original word iterator

		while (q_it < q.size() and s_it < s.size()){

			if (s[s_it] == q[q_it]){

				if (answer_ini == -1){
					answer_ini = s_it;


				} if (q_it == q.size() - 1){
					answer_end = s_it;
				}

				s_it++;
				q_it++;	
			} else  {
				s_it++;
			}

		}

		if (answer_ini == -1 or answer_end == -1){
			cout << "Not matched\n";
		} else {
			cout << "Matched " << answer_ini << " " << answer_end << "\n";
		}


	}

	return 0;
}