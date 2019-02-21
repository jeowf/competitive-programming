#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	
	string s;

	int count = 1;

	while (cin >> s){
		cout << "Case " << count << ":" << endl;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int min, max;
			cin >> min;
			cin >> max;

			char first_digit = s[min];

			bool equal = true;

			for (int j = min + 1; j <= max; ++j){
				if (s[j] != first_digit){
					equal = false;
					break;
				}
			}

			if (equal)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;

		}

		count++;
	}

	return 0;
}