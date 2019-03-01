#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct entry{
	string name;
	int g; //ouro
	int s; //prata
	int b; //bronze
	
};

bool comp(entry *lhs, entry *rhs){

	if (lhs->g > rhs->g){
		return true;
	} else if (lhs->g==rhs->g && lhs->s > rhs->s){
		return true;
	} else if (lhs->g==rhs->g && lhs->s == rhs->s && lhs->b > rhs->b){
		return true;
	} else if (lhs->g==rhs->g && lhs->s == rhs->s && lhs->b == rhs->b){

		int min = lhs->name.size() < rhs->name.size() ? lhs->name.size() : rhs->name.size();

		for (int i = 0; i < min; ++i) {
			if (tolower(lhs->name[i]) < tolower(rhs->name[i]))
				return true;
			else 
				return false;
		}

		return true;

	}



	return false;
}

int alf_comp( entry *lhs, entry  ){

}

int main(){

	int g;
	cin >> g;

	vector<entry*> v(g);

	for (int i = 0; i < g; ++i){
		entry *e = new entry();
		cin >> e->name >> e->g >> e->s >> e->b; 
		v[i] = e;
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < g; ++i)
	{
		cout << v[i]->name << " " 
		     << v[i]->g << " "
		     << v[i]->s << " "
		     << v[i]->b << endl;
	}

	return 0;
}