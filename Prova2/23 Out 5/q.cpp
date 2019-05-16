#include <bits/stdc++.h>

using namespace std;


const int R = 23;
int tup[5];
bool answer;

void backtracking(int index, int value){

	if (index == 5){
		if (value == R) answer = true;

	} else {
		backtracking(index + 1, value + tup[index]);
		backtracking(index + 1, value * tup[index]);
		backtracking(index + 1, value - tup[index]);
	}

}

bool read_in(){

	for (int i = 0; i < 5; ++i)
		cin >> tup[i];

	bool r = false;
	
	for (int i = 0; i < 5; ++i)
	{
		if (tup[i] != 0){
			r = true;
			break;
		}
	}

	return r;
	
}

int main(){

	while ( read_in() ) {
		answer = false;
		sort(tup, tup + 5);

		backtracking(1, tup[0]);

		while(next_permutation(tup, tup + 5)){
			backtracking(1, tup[0]);
		}


		if (answer)
			cout << "Possible\n";
		else
			cout << "Impossible\n";


	}

	return 0;
}