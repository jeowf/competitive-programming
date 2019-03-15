#include <bits/stdc++.h>

using namespace std;

int main(){

	map<string, int> florest;
	int n = 0;

	string tree;

	while (getline(cin,tree)){
		florest[tree]++;
		n++;
	}

	//sort(florest, florest.begin(), florest.end());

	for (auto & e : florest){

		cout << e.first << " ";
		printf("%.4f\n", (float) 100*e.second/n );
	}



	return  0;
}