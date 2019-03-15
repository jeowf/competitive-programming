#include <bits/stdc++.h>
using namespace std;


int main(){

	long long int histogram[100005];

	int n;

	while (cin >> n && n != 0){
		int area, t;
		int max = 0;
		stack<int> aux;
		//histogram[n] = 0;

		for (int i = 0; i < n; ++i)	{
			cin >> histogram[i];
		}


		for (int i = 0; i < n; ) {
			//cin >> histogram[i];
			
			if (aux.empty() || histogram[aux.top()] <= histogram[i]){
				aux.push(i++);

			} else {

				//while( !(aux.empty() || histogram[aux.top()] <= histogram[i]) ){
				t = aux.top();
				aux.pop();

				if (aux.empty())
					area = histogram[t] * i;
				else
					area = histogram[t] * (i - aux.top() - 1);

				if (area > max) max = area;
					
				//}
			}
		}

		while(!aux.empty()){
			t = aux.top();
			aux.pop();
			if (aux.empty())
				area = histogram[t] * n;
			else
				area = histogram[t] * (n - aux.top() - 1);

			if (area > max) max = area;
		}
	
		cout << max << endl;

	}

	return 0;

}