#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int m, n;
		cin >> m;
		cin >> n;
		m -= 2;
		n -= 2;

		if (m%3==0)
			m = m/3;
		else
			m = m/3 + 1;

		if (n%3==0)
			n = n/3;
		else
			n = n/3 + 1;

		cout << m*n << endl;

	}

	return 0;
}