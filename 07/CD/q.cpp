#include <bits/stdc++.h>

using namespace std;

int last_sum = 0;
bool final_part[20];
bool part[20];
int cds[20];
int N; // max  minutos
int n_tracks;

void search_sum(int i, int sum){

	if (sum > N)
		return;

	if (sum > last_sum){
		last_sum = sum;
		for (int j = 0; j < 20; ++j){
			final_part[j] = part[j];
		}
	}

	if (i >= n_tracks)
		return; 

	part[i] = true;
	search_sum(i+1, sum + cds[i]);
	part[i] = false;
	search_sum(i+1, sum);


}

int main(){


	while(cin >> N){
		cin >> n_tracks;
		for (int i = 0; i < n_tracks; ++i){
			cin >> cds[i];
		}

		last_sum = 0;
		for (int i = 0; i < 20; ++i){
			final_part[i] = part[i] = false;
		}

		search_sum(0, 0);
		for (int i = 0; i < n_tracks; ++i){
			if (final_part[i])
				cout << cds[i] << " ";
		}
		cout << "sum:" << last_sum << endl;


	}

	return 0;

}