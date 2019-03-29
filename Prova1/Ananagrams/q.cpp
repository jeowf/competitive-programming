#include <bits/stdc++.h>

using namespace std;



int main(){

	string s = " ";

	bool valid = true;
	map<map<char, int>, vector<string>> words;
	while (getline(cin,s) && valid){

		istringstream ss(s);

		//int count = 0;
		string x;

		while (ss >> x){
			if (x == "#"){
				valid = false;
				break;
			}

			map<char, int> word;
			locale loc;
			for (int i = 0; i < x.size(); ++i) {
				char c = tolower(x[i], loc);
				word[c]++;
			}

			words[word].push_back(x);
			
		}

		if (!valid) continue;
	}

	vector<string> res;

	for(auto e : words){
		if (e.second.size()==1){
			res.push_back(e.second.front());
		}
	}

	sort(res.begin(), res.end());

	for(auto & e : res){
		cout << e << endl;
	}

	return 0;

}