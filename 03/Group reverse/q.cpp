#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int g;

	while (cin >> g && g!=0){

		string s = "";
		cin >> s;

		g = s.size()/g;

		for (int i = 0; i < s.size()/g; i++)
			reverse(s.begin()+i*g, s.begin() + (i+1)*g);
		
		cout << s << endl;

	}

	return 0;
}