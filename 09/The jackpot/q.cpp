#include <bits/stdc++.h>

using namespace std;


int main() {

	int bets[10005] = {0};
	int streaks[10005] = {0};

	int N;
	while(cin >> N && N != 0){

		int max_streak = -999999;

		for (int i = 0; i <N; ++i){

			int bet;
			cin >> bet;

			bets[i] = bet;

			if (i == 0){
				streaks[0] = bets[0];
				max_streak = bets[0];
			} else {
				int a = bets[i];
				int b = streaks[i-1] + a;

				if (a > b)
					streaks[i] = a;
				else 
					streaks[i] = b;

				if (streaks[i] > max_streak)
					max_streak = streaks[i];
			}
		}

		if (max_streak > 0)
			cout << "The maximum winning streak is " << max_streak << ".\n";
		else 
			cout << "Losing streak.\n";
		//cout << max_streak << endl;
	}


	
	return 0;
}