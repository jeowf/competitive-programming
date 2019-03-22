#include <bits/stdc++.h>

using namespace std;

struct entry{
	int id;
	int time;
	int d_time; // tempo default

	bool operator<(entry const &b) const {
	    if (this->time == b.time) 
	    	return this->id > b.id;

	    return this->time > b.time;
	}
};

int main(){

	priority_queue<entry> pq;

	string s;

	while (cin >> s && s != "#"){
		int id, time;
		cin >> id >> time;
		entry e;
		e.id = id;
		e.time = time;
		e.d_time = time;
		pq.push(e);
	}


	int K;
	cin >> K;
	
	for (int i = 0; i < K; ++i){

		auto t = pq.top();
		cout << t.id << endl;
		pq.pop();

		entry e;
		e.id = t.id;
		e.time = t.time + t.d_time;
		e.d_time = t.d_time;

		pq.push(e);

	}
	

	return 0;
}