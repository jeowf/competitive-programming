#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string m, n;
		cin >> m;
		cin >> n;
		
		int maximal = 0;

		int chars[256];
		for (int i = 0; i < 256; ++i)
			chars[i] = 0;
		

		for (int i = 0; i < m.size(); ++i){
			chars[m[i]]++;
		}

		bool chain = true;
		int aux = 0;

		for (int i = 0; i < n.size(); ++i){
			if (chars[n[i]] > 0){
				chars[n[i]]--;
				aux++;
			} else {
				chain = false;
				if (aux > maximal) maximal = aux;
			}
		}

		if (aux > maximal) maximal = aux;

		
		cout << maximal << endl;

	}

	return 0;
}