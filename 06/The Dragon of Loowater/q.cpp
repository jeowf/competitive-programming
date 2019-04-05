#include <bits/stdc++.h>

using namespace std;

int main(){

	int heads[20001];
	int knights[80001];

	int h, k;
	while(cin >> h >> k && (h != 0 && k != 0)){
		int r = 0;

		for (int i = 0; i < h; ++i) {
			cin >> heads[i];
		}

		for (int i = 0; i < k; ++i)	{
			cin >> knights[i];
		}
		if (k < h){
			cout << "Loowater is doomed!\n";
			break;
		}
		sort(heads, heads+h);
		sort(knights, knights+k);

		int slow = 0, fast = 0;
		
		while (slow < h && fast < k){
			if (heads[slow] <= knights[fast]){
				r+=knights[fast];
				slow++;
				fast++;
			} else {
				fast++;
			}
		}

		if (slow == h)
			cout << r << endl;
		else
			cout << "Loowater is doomed!\n";
			


	}

	return 0;

}