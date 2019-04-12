#include <bits/stdc++.h>

using namespace std;

const bool prime[32] = { false, true, true, true, false,
                   		 true, false, true, false,
                  		 false, false, true, false,
                  		 true, false, false, false,
                 		 true, false, true, false,
                 		 false, false, true, false,
                 		 false, false, false, false,
                		 true, false, true };

int n;

bool mask[17];
int used[17];

void prime_ring(int prev, int index){
	used[index] = prev;
	if (index == n && prime[prev + 1]){
		for (int i = 1; i <= n; ++i)
		{
			cout <<  used[i];
			if (i < n)
				cout << " ";
		}
		cout << endl;
		return;
	}

	

	for (int i = 1; i <= n; ++i) {
		if (!mask[i]){
			if( prime[ prev +  i] ){
				mask[i] = true;

				prime_ring(i, index + 1);

				mask[i] = false;
			}
		}
	
	}

	return;

}

int main(){

	int c = 1;

	while (cin >> n){
		for (int i = 0; i <= 16; ++i) {
			mask[i] = false;
		}

		mask[1] = true;
		if (c > 1)
			cout << endl;
		
		cout << "Case " << c++ << ":" << endl;
		if (n == 1){
			cout << "1\n";
		} else {
			prime_ring(1, 1);
		}

		//cout << endl;
	}

	return 0;
}