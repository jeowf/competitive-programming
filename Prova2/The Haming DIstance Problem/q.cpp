

#include <bits/stdc++.h>

using namespace std;

bool mask[20];
int N, H;

void solve(int i, int qtd){
	//cout << qtd<< " " <<  i << endl;
	if (qtd > H)
		return;
	

	if (qtd == H){
		for (int i = 0; i < N; ++i)
		{
			if (mask[i])
				cout << "1";
			else
				cout << "0";
		}

		cout << endl;
		return;
	}

	if (i>= N){
		
		return;
	}

	//mask[i] = false;
	solve(i+1, qtd);

	mask[i] = true;

	solve(i+1, qtd+1);
	mask[i] = false;

	

	return;

}

int main(){

	int t;

	cin >> t;

	while(t--){

		cin >> N >> H;
		for (int i = 0; i < 20; ++i)
		{
			mask[i] = false;
		}

		solve(0, 0);

		if (t > 0)
			cout << endl;

	}

}