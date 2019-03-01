#include <iostream>
#include <string>

using namespace std;

int main(){

	int T;
	cin >> T;
	int v[1000];

	for (int i = 0; i < T; ++i){

		

		int N, K;
		string s;
		cin >> N >> K;

		for (int j = 0; j < N ; ++j)
			v[j] = -1;

		cin >> s;

		char aux = ' ';
		//int ini = -1, end;
		int prev = -1, end = 0;
		for (int j = 0; j < N; j++){
			if (aux == ' '){
				aux = s[j];
				v[j] = j;
				prev = j;
				end = 0;
			} else {
				if ( s[j] != aux ){
					aux = s[j];
					end++;
				} else {
					aux = s[j];
					v[prev] = j-1;
					prev = j;
					end = 0;
					v[j] = j;
				}

			}

		}

		for (int j = 0; j < N; ++j)
		{
			if (v[j] == -1)
				cout << 0;
			else
				cout << v[j];
		}

		cout << endl;

	}

	return 0;
}