#include <bits/stdc++.h>

using namespace std;

int main(){



	int specimens[10];

	int C, S;

	int set = 1;

	while (cin >> C >> S){

		float AM = 0;
		
		for (int i = 0; i < 10; ++i)
			specimens[i] = 0;
		

		for (int i = 0; i < S; ++i){ 
			cin >> specimens[i];
			AM += specimens[i];
		}

		AM /= C;
		float IMBALANCE = 0;
		sort(specimens, specimens + C*2);

		int s_aux;

		cout << "Set #" << set++ << endl;
		for (int i = 0; i < C; ++i) {
			cout << " " << i << ":";
			if (specimens[i] > 0)
				cout << " " << specimens[i];
			if (specimens[C*2 -i-1])
				cout << " " << specimens[C*2 -i-1];
			IMBALANCE += abs(specimens[i] + specimens[C*2 -i-1] - AM);
			cout << endl;
		}

		printf("IMBALANCE = %.5f\n\n", IMBALANCE );
		
	}

	return 0;
}