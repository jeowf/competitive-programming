#include <iostream>

using namespace std;

int main() {

	int lv[100000];
	int rv[100000];

    int N, B;
    while (cin >> N >> B && N != 0 && B != 0) {
        for (int i = 0; i < N; ++i) {
            lv[i] = i - 1;
            rv[i] = i + 1;
        }

        lv[0] = rv[N - 1] = -1;
        
        for (int i = 0; i < B; i++) {
            int l, r;

            cin >> l >> r;

            l -= 1; 
            r -= 1;
            
            int l_most = lv[l];
		    int r_most = rv[r];
		    
		    if (l_most != -1) 
		    	rv[l_most] = r_most;
		    
		    if (r_most != -1) 
		    	lv[r_most] = l_most;
		    

            if (l_most == -1) 
            	cout << "* ";
            else 
            	cout << (l_most + 1) << " ";
            
            if (r_most == -1) 
            	cout << "*" << endl;
            else 
            	cout << (r_most + 1) << endl;
        }
        cout << "-" << endl;
    }
}