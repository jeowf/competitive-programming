#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;

	while( getline(cin, s) ){
		//cout << "CASE: " << s;
		istringstream line(s);

		stack<int> m;
		stack<int> sum;

		int aux = 0;


		int x;
		while (line >> x) {
		

			if (x < 0){
				if (!m.empty() && x <= m.top())
					break;	
				m.push(x);
				sum.push(-1*x);
				aux += -1*x;
			}

			else if ( x > 0 ){
				
				if (m.empty()){
					m.push(0);
					break;
				}

				if ( !m.empty() && m.top()*-1 != x){
					break;
				} else if (!m.empty() && m.top()*-1 == x){
					int ax = 0;

					while(!sum.empty() ) {

						if (sum.top() == x )
							break;

						ax += sum.top();
						sum.pop();
					}

					if (ax >= x)
						break;
					//cout << " > Removing " << x << " sum " << ax << endl;  

					m.pop();
					
					
				} 
			}
		}

		if (m.empty())
			cout << ":-) Matrioshka!" << endl;
		else
			cout << ":-( Try again." << endl;

	}

	return 0;

}