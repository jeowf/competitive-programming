#include <iostream>
#include <string>

using namespace std;

int main(){

	int n;

	int v[(18-10)*60];

	int count = 1;

	while (cin >> n){

		for (int i = 0; i < (18-10)*60; ++i)
			v[i] = -1;

		string aux;
		int max = -1;

		for (int i = 0; i < n; ++i)
		{
			cin >> aux;
			int h1 = stoi(aux.substr(0,2));
			int m1 = stoi(aux.substr(3,2));

			//cout << "[" <<h1 << ":" << m1 << "]" <<endl;

			cin >> aux;
			int h2 = stoi(aux.substr(0,2));
			int m2 = stoi(aux.substr(3,2));

			//cout << "[" <<h2 << ":" << m2 << "]" <<endl;


			//cin >> aux;
        	getline(cin, aux);


			//cout << aux;

			int ini = (h1-10)*60 + m1;
			v[ini] = (h2-10)*60 + m2;

			if (max == -1){
				max = ini;
			} else if (v[ini] - ini > v[max] - max){
				max = ini;
			}


		}

		int prev = -1;

		for (int i = 0; i < (18-10)*60; ++i) {
			if (v[i] == -1 && prev == -1)
				prev = i;

			if (v[i] != -1){
				v[prev] = i;
				prev = -1;

				if (max == -1){
					max = prev;
				} else if (v[prev] - prev > v[max] - max){
					max = prev;
				}

				i = v[i] - 1;
			}
		}

		if (prev != -1){
			v[prev] = (18-10)*60;

			if (max == -1){
				max = prev;
			} else if (v[prev] - prev > v[max] - max){
				max = prev;
			}
		}

		cout << max/60 + 10 << ":" << max%60 <<endl;

		count++;

	}

	return 0;
}