#include <bits/stdc++.h>

using namespace std;

int books[10001];

int main(){
	
	int N, M;

	bool f_case = true;
	while (cin >> N){

		for (int i = 0; i < N; ++i) {
			cin >> books[i];
		}

		cin >> M;

		sort(books, books + N);

		int first = 0, last = N;

		int bg, en;

		while (first < last){
			int a = books[first];
			int b = books[last-1];
			if (a + b == M){
				bg = a;
				en = b;
		//cout << bg << " " << en << endl;
				first++;
				last--;

			} else if (a + b > M){
				last--;
			} else{
				first++;
			}
		}
		if (f_case){
			f_case = false;
		}
		else{
			cout << endl << endl;
		}

		cout << "Peter should buy books whose prices are " << bg << " and " << en << ".";

	}

	return 0;
}
