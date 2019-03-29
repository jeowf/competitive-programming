#include <bits/stdc++.h>

using namespace std;

long facs[100001] = {0};


long first_m_fac(long x){
	if (x == 0 or x == 1)
		return 1;
	int i = 0;
	while (x >= facs[i]){ i++;}

	return facs[i-1]; 
}

int main(){
int last_fac = 1;

	
	facs[0] = 1;
	facs[1] = 1;
	

	long n;

	while(cin >> n){
		//cout << "a" ;
		while (n > facs[last_fac]){
			last_fac++;
			facs[last_fac] = facs[last_fac - 1] * last_fac;
		}

		//cout << "opa";
		long r = n;
		int aux = 0;
		while (r > 0){
			//cout << r << endl;
			long x = first_m_fac(r);
			//cout << " > " << x << endl;
			r -= x;
			aux++;
		}

		cout << aux << endl;

	}
	return 0;
}