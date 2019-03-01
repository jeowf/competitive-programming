#include <iostream>

using namespace std;

int main(){

	int w, n;
	while (cin >> w >> n){

		int area = 0;

		for (int i = 0; i < n; ++i) {
			int x,y;
			cin >> x >> y;
			area += x * y;
		}

		cout << area/w << endl;

		
	}
	return 0;
	
}