#include <bits/stdc++.h>

using namespace std;

int t, n;
int numbers[12];

bool mask[12];
bool has_solution = false;

//map <bool[12], bool> last_results;

void calc_sum(int prev, int index){
	//used[index] = prev;

	if (prev > t || index >= n)
		return;

	// lembrar de ajeitar: printar em funcao do tamanho da mask
	if (prev == t){
		has_solution = true;
			cout << "index : " << index << "\n";
			for (int i = 0; i <= index; ++i)	{
				if (mask[i]){
					cout << numbers[i];
					if (i < index-1) 
						cout << "+";
				}
			}
			cout << endl;

		//return;
	}

	mask[index] = true;
	calc_sum(prev + numbers[index], index + 1);
	mask[index] = false;
	calc_sum(prev, index + 1);

	return;

}

int main(){

	while (cin >> t >> n && n != 0){
		for (int i = 0; i < n; i++){
			mask[i] = false;
			cin >> numbers[i];
		}

		has_solution = false;

		cout << "Sums of " << t << ":\n";
		
		calc_sum(0,0);

		if (!has_solution)
			cout << "NONE\n";

	}

	

	return 0;
}