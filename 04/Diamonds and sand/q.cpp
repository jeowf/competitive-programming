#include <iostream>
#include <stack>

using namespace std;

int main(){
	
	int n;
	string s;

	cin >> n;
	getline(cin, s);
	
	stack<char> diamonds;

	for (int i = 0; i < n; ++i) {
		
		getline(cin, s);
		stack<char> diamonds;
		int aux = 0;


		for (char& c : s){
			if (c == '<'){
				diamonds.push('<');
			}
			if (c == '>' && !diamonds.empty() && diamonds.top() == '<'){
				diamonds.pop();
				aux++;
			}
		}

		cout << aux << endl;

	}

	return 0;
}