#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int book[105];

	//int count = 0;

	int n;
	while (cin >> n && n!= 0){
		for (int i = 1; i < 105; ++i){
			if (i <= n){
				book[i] = i;
			} else {
				book[i] = 0;
			}
		}

		int aux = n;
		if (n%4 != 0) n += 4- n%4;

		int p1,p2,p3,p4;

		cout << "Printing order for " << aux << " pages:" << endl;
		int sheet = 1;
		for (int i = 1; i <= n/2; i+=2) {
			p1 = book[i];
			p2 = book[i+1];
			p3 = book[n - i];
			p4 = book[n-i+1];

			if (p1 != 0 || p4 != 0){
				cout << "Sheet " << sheet << ", front: ";
				if (p4!=0)
					cout << p4 << ", ";
				else
					cout << "Blank, ";

				if (p1!=0)
					cout << p1 << endl;
				else
					cout << "Blank" << endl; 
			}

			if (p3 != 0 || p2 != 0){
				cout << "Sheet " << sheet << ", back : ";
				if (p2!=0)
					cout << p2 << ", ";
				else
					cout << "Blank, ";

				if (p3!=0)
					cout << p3 << endl;
				else
					cout << "Blank" << endl; 
			}

			sheet++;

		}
	

	}


	return 0;
}

