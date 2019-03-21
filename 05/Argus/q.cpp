#include <bits/stdc++.h>

using namespace std;
/*
struct entry{
	int id,
	int time;
	int d_time; // default time
};

bool operator< (entry lhs, entry rhs){
	if (lhs.time < rhs.time)
		return true;
	else if (lhs.time == rhs.time && lhs.id < rhs.id)
		return true;
	return false;
}

*/

struct entry{
	int id;
	int d_time; // tempo default
};

int main(){

	string s;
	int id, time;
	map<int, entry> m;

	while (cin >> s && s != "#"){
		cin >> id >> time;
		entry e;
		e.id = id;
		e.d_time = time;
		m[time] = e;
	}


	int K;
	cin >> K;
	auto iter = m.begin();	
	
	for (int i = 0; i < K; ++i){
		cout << "ID: " << iter->first << endl;
		cout << iter->second.id << endl;

		int index = iter->first + iter->second.d_time;

		if (iter->second.id > m[index].id)
			m[index] = iter->second;

		//if (iter == m.rbegin())
		//	iter = m.begin();
		iter++;

	}
	

	return 0;
}