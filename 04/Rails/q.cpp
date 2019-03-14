#include <bits/stdc++.h>
using namespace std;

int main(){

	int ts;

	while(cin >> ts && ts != 0){

		int train[1001];

		int x;

		while ( cin >> x && x != 0){

			bool anwser = true;


			train[0] = x;
			for (int i = 1; i < ts; ++i)
				cin >> train[i];	
			

			stack<int> aux;
			int t = 0, a = 0;

			while (t < ts){
				aux.push(t+1);
				while (!aux.empty() && 
						aux.top() == train[a] && 
						a < ts){
					aux.pop();
					a++;
				}

				t++;
			}

			if (!aux.empty())
				anwser = false;

			

			if (anwser == true){
				cout << "Yes" << endl;

			} else {
				cout << "No" << endl;
			}
		}

		cout << endl;
		
	}


	return 0;
}