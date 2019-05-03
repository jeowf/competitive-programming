
#include <bits/stdc++.h>

using namespace std;


const int MAX = 1125;
int main(){

	int primes[MAX] = {0};

	primes[0] = primes[1] = 1;

	for (int i = 2; i < MAX; ++i) {
		for (int j = i+i; j < MAX; j += i) {
			primes[j]++;
		}
	}
	int size = 1;
	cout << "{2";
	for (int i = 3; i < MAX; ++i){
		if (primes[i] == 0){
			cout << ", " << i;
			size++;
		}


	}
	cout << "}\n";
	cout << size << endl;



	

	return 0;
}
