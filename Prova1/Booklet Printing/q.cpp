#include <bits/stdc++.h>

using namespace std;

int main(){
	int REF[8] = {1,2,4,8,16,32,64,128};
	int book[130];

	int n;
	while (cin >> n && n!= 0){
		for (int i = 0; i < 129; ++i){
			if (i <= n)
				book[i] = i;
			else
				book[i] = 0;
		}

		int aux = 0;
		int k = 0;
		while (aux < n){
			aux = REF[k++];
		}

		//cout << aux << endl;

		int sheet = 1;
		for (int i = 1; i <= aux/2; i+=2){
			
		}



	}


	return 0;
}