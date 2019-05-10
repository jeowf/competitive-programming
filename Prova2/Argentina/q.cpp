#include <bits/stdc++.h>

using namespace std;

struct player{
	string name;
	int attack;
	int defense;

	player(){}

	player(string n, int a, int d) : name(n), attack(a), defense(d)
	{ }

};

bool comp (player lhs, player rhs){
	if (lhs.attack > rhs.attack){
		return true;
	} else if (lhs.attack == rhs.attack && lhs.name < rhs.name){
		return true;
	}
	return false;
}

bool comp2 (player lhs, player rhs){
	if (lhs.defense < rhs.defense){
		return true;
	}
	return false;
}

bool comp3(player lhs, player rhs){
	if (lhs.name < rhs.name){
		return true;
	}

	return false;
}

int main(){


	int c;

	cin >> c;



	for (int i = 0; i < c; ++i)	{
		vector<player> players;

		for (int j = 0; j < 10; ++j){
			string s;
			int a, d;

			cin >> s >> a >> d;

			player p(s,a,d);

			players.push_back(p);

		}

		sort(players.begin(), players.end(), comp);

		int aux = players[4].attack;

		int inip = 0;
		int endp = 0;
		for (int k = 0; k < 10; ++k)
		{	
			inip = k;
			if (players[k].attack == aux){
				for (int l = k; l < 10; ++l)
				{
					endp = l;
					if (players[l].attack != aux){
						endp -= 1;
						break;
					}
				}
				break;
			}
		}
		cout << "Case " << i+1 << ":\n";
		//int siz = endp - inip + 1;

		sort(players.begin() + inip, players.begin() + endp+1, comp2);
		sort(players.begin(), players.begin() +5, comp3);
		sort(players.begin() + 5, players.begin() +10, comp3);


		cout << "(";
		for (int k = 0; k < 5; ++k)
		{
			cout << players[k].name;
			if (k < 4)
				cout << ", ";
		}
		cout << ")\n";



		cout << "(";
		for (int k = 5; k < 10; ++k)
		{
			cout << players[k].name;
			if (k < 9)
				cout << ", ";
		}
		cout << ")\n";

		/*for (auto & e : players)		{
			cout << e.attack << endl;
		}*/
/*
		int max_attack = 0;
		int max_def = 0;
		vector<player> atk_config(5);
		vector<player> def_config(5);

		for (int j = 0; j < 5; ++j)
		{
			max_attack += players[j].attack;
			max_def += players[j + 5].defense;
			atk_config[j] = players[j];
			def_config[j] = players[j + 5];
		}

		for (int j = 1; j <= 4; ++j) {
			int local_attack = 0;
			int local_def = 0;

			vector<player> local_atk_config(5);
			int aux = 0;

			for (int k = j; k < j+5; ++k){
				local_attack += players[k].attack;
				local_atk_config[aux++] = players[k];
			}

			vector<player> local_def_config(5);
			int count = 0;

			if (local_attack == max_attack){
				for (int l = 0; l < 10; ++l) {
					if ( l < j && l >= (j+5) ){
						local_def += players[l].defense;
						local_def_config[count++] = players[l];
					}
				}

				if (local_def > max_def){
					for (int l = 0; l < 5; ++l) {
						def_config[l] = local_def_config[l];
						atk_config[l] = local_atk_config[l];
						max_def = local_def;
					}
				}
			} else {
				break;
			}
		}

		for (int k = 0; k < 5; ++k)
		{
			cout << atk_config[k].name << " ";
		}

		cout << endl;

		for (int k = 0; k < 5; ++k)
		{
			cout << def_config[k].name << " ";
		}
*/

	}

	return 0;

}