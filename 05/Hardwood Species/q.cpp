#include <bits/stdc++.h>

using namespace std;

int main(){

	int cases;

	cin >> cases;
	string g; // ignores first line
	getline(cin, g);
	getline(cin, g);

	//int i = 0;

	for (int i = 0; i < cases; i++){

		map<string, int> florest;
		int n = 0;

		string tree;

		while (getline(cin,tree)){
			if (tree.size()>0){
				florest[tree]++;
				n++;	
			} else {
				break;
			}
					
		}

		for (auto & e : florest){
			if(e.first.size() > 0){
				cout << e.first << " ";
				printf("%.4f\n", (float) 100*e.second/n );
			}
			
		}
		if (i < cases - 1)
			cout << endl;
		//i++;
		
		
	
	}



	



	return  0;
}