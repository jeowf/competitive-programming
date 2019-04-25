#include <bits/stdc++.h>

using namespace std;

int t, n;
int numbers[13];

bool mask[13];
bool has_solution = false;

map<string, int> exps;

//map <bool[12], bool> last_results;

void calc_sum(int prev, int index, int s){
	//used[index] = prev;

	if (prev > t || index >= n)
		return;

	stringstream expr;
	// lembrar de ajeitar: printar em funcao do tamanho da mask
	if (prev == t){
		has_solution = true;

		int j = 0;
		for (int i = 0; i <= index; ++i){
			if (mask[i]){
				expr << numbers[i];
				if (j++ < s-1) 
					expr << "+";

			}
		}
		exps[expr.str()] = 1;
	}


	mask[index] = true;
	calc_sum(prev + numbers[index], index + 1,s+1);
	mask[index] = false;
	calc_sum(prev, index + 1,s);

	return;

}

int main(){

	while (cin >> t >> n && n != 0){
		for (int i = 0; i < n; i++){
			mask[i] = false;
			cin >> numbers[i];
		}
		numbers[n] = 0;
		n++;

		has_solution = false;

		cout << "Sums of " << t << ":\n";
		
		calc_sum(0,0,0);

		if (!has_solution)
			cout << "NONE\n";

		/*for(auto & e : exps){
			if (e.second == 1){
				cout << e.first << endl;
			}
		}*/
		for (auto it = exps.rbegin(); it != exps.rend(); ++it){
			if (it->second == 1)
				cout << it->first << endl;
		}

		exps.clear();

	}

	

	return 0;
}