#include <bits/stdc++.h>
using namespace std;

pair<int, int> v[100000];

void wind(int i, char dir){
	if (dir == 'U')
		v[i].second++;
	else if (dir == 'D')
		v[i].second--;
	else if (dir == 'L')
		v[i].first--;
	else
		v[i].first++;
}

int main(){

	pair<int, int> s;
	pair<int, int> d;


	cin >> s.first >> s.second;
	cin >> d.first >> d.second;

	int str_n;
	string str;

	cin >> str_n;
	cin >> str;

	v[0].first = v[0].second = 0;

	wind(0, str[0]);

	for (int i = 1; i < str_n; i++){
		v[i] = v[i-1];
		wind(i, str[i]);
	}

	for (int i = 0; i < str_n; ++i) {
		printf("(%d,%d)\n", v[i].first, v[i].second );
	}

	for (int i = 0; i < count; ++i)
	{
		/* code */
	}



	return 0;
}