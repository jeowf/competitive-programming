#include <bits/stdc++.h>

using namespace std;

const int M_SIZE = 52;

int main(){



	int l;
	while (cin >> l && l != 0){
		int n;
		int cuts[M_SIZE];
		int sol[M_SIZE][M_SIZE];

		cin >> n;

		cuts[0] = 0;
		cuts[n+1] = l;

		for (int i = 0; i < n; ++i)
			cin >> cuts[i+1];

		for (int end = 1; end <= n+1; end++) {

			for (int beg = end - 1; beg >= 0; beg--) {


				if (beg + 1 == end){
					sol[beg][end] = 0;


				} else {

					sol[beg][end] = INT_MAX;

					for(int i = beg + 1; i < end; i++){


						if (sol[beg][end] >= sol[beg][i] + sol[i][end] )
							sol[beg][end] = sol[beg][i] + sol[i][end];

					}

					sol[beg][end] += cuts[end] - cuts[beg];
				}
				
			}
		}
		

		cout << "The minimum cutting is " << sol[0][n+1] << ".\n";

	}


	return 0;
}