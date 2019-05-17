#include <bits/stdc++.h>

using namespace std;

map<string, vector<string> > graph;

string start;
string goal;

string iter_s(string s, int k, int t){
	//soma
	if (t == 1){
		if (s[k] == '9')
			s[k] = '0';
		else
			s[k]++;

	}

	//sub
	if (t == -1){
		if (s[k] == '0')
			s[k] = '9';
		else
			s[k]--;
	}

	return s;
}

void start_graph(string s){
	if (graph[s].empty()){
		for (int i = 0; i < 4; ++i){
			string x = iter_s(s, i, 1);
			graph[s].push_back(x);
		}

		for (int i = 0; i < 4; ++i){
			string x = iter_s(s, i, -1);
			graph[s].push_back(x);

		}

		for(auto & e : graph[s]){
			start_graph(e);
		}
	}

}

int main(){

	int cases;
	cin >> cases;

	start_graph("0000");


	while(cases--){
		map<string, int> cant;
		int n_cant;

		string st = "xxxx";
		string go = "xxxx";

		for (int i = 0; i < 4; ++i)
			cin >> st[i];

		for (int i = 0; i < 4; ++i)
			cin >> go[i];

		cin >> n_cant;

		for (int i = 0; i < n_cant; ++i){
			string aux = "xxxx";

			for (int j = 0; j < 4; ++j)
				cin >> aux[j];

			cant[aux] = 1;
		}
		

	}

	return 0;
}