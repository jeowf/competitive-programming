#include <bits/stdc++.h>

using namespace std;

int main(){

	int cases;

	cin >> cases;
	string g; // ignores first line
	getline(cin, g);

	int i = 0;
	///for (int i = 0; i <= cases; ++i) {
		
		while(i < cases){
			map<string, int> florest;
			int n = 0;

			string tree;

			while (getline(cin,tree) && tree != "\n"){
				florest[tree]++;
				n++;
			}

			for (auto & e : florest){
				cout << e.first << " ";
				printf("%.4f\n", (float) 100*e.second/n );
			}
			i++;
		}
		
	
	//}

	



	return  0;
}