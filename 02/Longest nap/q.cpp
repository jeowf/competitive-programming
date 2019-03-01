#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){

	int n;
	bool v[(18-10)*60];
	int count = 1;

	while (cin >> n){

		for (int i = 0; i < (18-10)*60; ++i)
			v[i] = false;

		string aux;
		
		for (int i = 0; i < n; ++i){
			cin >> aux;
			int h1 = stoi(aux.substr(0,2));
			int m1 = stoi(aux.substr(3,2));

			cin >> aux;
			int h2 = stoi(aux.substr(0,2));
			int m2 = stoi(aux.substr(3,2));

        	getline(cin, aux);

			int ini = (h1-10)*60 + m1;
			int end = (h2-10)*60 + m2;

			for (int k = ini; k < end; ++k)
				v[k] = true;
		}

		int max_i = -1, max_f = -1, prev_i = -1, prev_f = -1;

		for (int i = 0; i < (18-10)*60; ++i) {
			if (!v[i] && prev_i == -1)
				prev_i = i;

			if (v[i] && prev_i != -1){
				prev_f = i;

				if (max_i == -1){
					max_i = prev_i;
					max_f = prev_f;
				} else if (prev_f - prev_i > max_f - max_i){
					max_i = prev_i;
					max_f = prev_f;
				}
				
				prev_i = -1;
			}
		}

		if (prev_i != -1){

			prev_f = (18-10)*60;

			if (max_i == -1){
				max_i = prev_i;
				max_f = prev_f;
			} else if (prev_f - prev_i > max_f - max_i){
				max_i = prev_i;
				max_f = prev_f;
			}
		}

		cout << "Day #" << count << ": the longest nap starts at " <<  
		        setfill('0') << setw(2) << max_i/60 + 10 << ":" << setfill('0') << setw(2) << max_i%60 << 
		        " and will last for ";
		int duration = max_f - max_i;
		if (duration >= 60)
			cout << duration/60 << " hours and " << duration%60 << " minutes." << endl;
		else 
			cout << duration%60 << " minutes." << endl;

		count++;

	}

	return 0;
}