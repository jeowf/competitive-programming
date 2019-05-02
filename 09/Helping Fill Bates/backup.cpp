#include <bits/stdc++.h>

using namespace std;

struct Cand{
	char state;
	int i_serial;
	int f_serial;
	Cand(char c, int i, int f) : 
	state(c), i_serial(i), f_serial(f) 
	{ }
};

vector<Cand> candidates;



int main(){


	string s;
	getline(cin, s);

	char aux = '@';
	int last_index = -1;
	for(int i =0; i < s.size(); i++){
		char actual = s[i];
		if (actual != aux){
			Cand cand(actual, i,i);
			aux = actual;
			candidates.push_back( cand );
			last_index++;
		} else {
			candidates[last_index].f_serial = i;
		}
	}

	// for (int i = 0; i < last_index+1; ++i)
	// {
	// 	cout << candidates[i].state << " " << (candidates[i].f_serial - candidates[i].i_serial + 1) << endl;
	// }

	int queries;
	cin >> queries;

	getline(cin, s);


	for (int c = 0; c < queries; c++){
		vector<Cand> aux_cand;
		getline(cin, s);

		char aux = '@';
		int aux_last_index = -1;

		for(int i =0; i < s.size(); i++){
			char actual = s[i];
			if (actual != aux){
				Cand cand(actual, i,i);
				aux = actual;
				aux_cand.push_back( cand );
				aux_last_index++;
			} else {
				aux_cand[aux_last_index].f_serial = i;
			}
		}

		// for (int i = 0; i < aux_cand.size(); ++i)
	 // {
	 // 	cout << aux_cand[i].state << " " << (aux_cand[i].f_serial - aux_cand[i].i_serial + 1) << endl;
	 // }
	 // 	cout << endl;

		int i = 0, j = 0;

		Cand answer('a',-1,-1);

		for (; i < aux_cand.size() or j < candidates.size();){
			
			if (candidates[j].state == aux_cand[i].state){
				


				int amount_cand = candidates[j].f_serial - candidates[j].i_serial + 1;
				int amount_aux_cand = aux_cand[i].f_serial - aux_cand[i].i_serial + 1;

//				cout << amount_aux_cand << " <=? " <<amount_cand << endl;


				if (amount_aux_cand <= amount_cand){
					//cout << "SIM \n";
					if (answer.i_serial == -1){
						answer.i_serial = candidates[j].i_serial;
					}

					if (i == aux_cand.size() - 1){



						answer.f_serial = candidates[j].i_serial + amount_aux_cand - 1;
						break;

					}

					j++;

					if (i < aux_cand.size() - 1)
						i++;

				} else {
					aux_cand[i].f_serial -= amount_cand;
					j++;

				}

			} else {
				j++;

			}

			

			if (j == candidates.size()){
				break;
			}
		}

		//cout << "Case " << c+1 << ": \n";

		if (answer.i_serial == -1 or answer.f_serial == -1){
			cout << "Not matched\n";
		} else {
			//deu certo
			cout << "Matched " << answer.i_serial << " " << answer.f_serial << "\n";
		}


	}


	//cout << s << endl << queries << endl;

	return 0;
}