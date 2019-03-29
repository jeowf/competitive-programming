#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	while (cin >> n && n != 0){

		map < map<int,int>, int > all_courses;
		int max = 0;

		for (int i = 0; i < n; ++i) {

			map<int, int> courses;

			for (int j = 0; j < 5; ++j) {
				int x;
				cin >> x;
				courses[x]++;
			}

			int aux = ++all_courses[courses];
			if (aux > max) {
				max = aux;
			}
		}

		int aux = 0;

		for (auto & e : all_courses)	{
			if (e.second == max)
				aux += max;
		}

		cout << aux << endl;

	}


	return 0;
}