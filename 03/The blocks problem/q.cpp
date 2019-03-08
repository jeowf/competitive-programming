#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> world[25];
int refs[25];

string cmd1 = " ";
string cmd2;
int a,b;

int n;

void return_x( int x ){
	refs[x] = x;
	world[refs[x]].push(x);
}

void move_onto(int a, int b){
	int p = -1;

	while (world[refs[a]].top() != a){
		p = world[refs[a]].top();
		return_x(p);
		world[refs[a]].pop();
	}

	world[refs[a]].pop();
	refs[a] = refs[b];

	while (world[refs[b]].top() != b){
		p = world[refs[b]].top();
		return_x(p);
		world[refs[b]].pop();
	}

	world[refs[b]].push(a);

}	

void move_over(int a, int b){

	int p = -1;

	while (world[refs[a]].top() != a){
		p = world[refs[a]].top();
		return_x(p);
		world[refs[a]].pop();
	}

	world[refs[a]].pop();
	refs[a] = refs[b];

	world[refs[b]].push(a);

}

void pile_onto(int a, int b){
	int p = -1;

	stack<int> aux;

	while (world[refs[b]].top() != b){
		p = world[refs[b]].top();
		return_x(p);
		world[refs[b]].pop();
	}


	while (world[refs[a]].top() != a){
		p = world[refs[a]].top();
		aux.push(p);
		refs[p] = refs[b];
		world[refs[a]].pop();
	}

	world[refs[a]].pop();
	refs[a] = refs[b];

	world[refs[b]].push(a);

	while(!aux.empty()){
		p = aux.top();
		world[refs[b]].push(p);
		aux.pop();
	}
}

void pile_over(int a, int b){
	int p = -1;

	stack<int> aux;

	while (world[refs[a]].top() != a){
		p = world[refs[a]].top();
		aux.push(p);
		refs[p] = refs[b];
		world[refs[a]].pop();
	}

	world[refs[a]].pop();
	refs[a] = refs[b];

	world[refs[b]].push(a);

	while(!aux.empty()){
		p = aux.top();
		world[refs[b]].push(p);
		aux.pop();
	}
}

void print_world(){
	stack<int> aux;

	for (int i = 0; i < n; ++i) {
		cout << i << ":";

		while (!world[i].empty()){
			aux.push(world[i].top());
			world[i].pop();
		}

		if (!aux.empty()){
			while(!aux.empty()){
				cout << " " << aux.top();
				aux.pop();
			}
		}
		cout << endl;
	}
}

int main(){

	

	cin >> n;

	for (int i = 0; i < n; ++i)	{
		refs[i] = i;
		world[i].push(i);
	}

	while (cin >> cmd1 && cmd1 != "quit"){
		cin >> a >> cmd2 >> b;

		if (a == b)
			continue;

		if (refs[a] == refs[b])
			continue;

		if (cmd1 == "move" && cmd2 == "onto"){
			move_onto(a,b);
		} else if (cmd1 == "move" && cmd2 == "over") {
			move_over(a,b);
		} else if (cmd1 == "pile" && cmd2 == "onto"){
			pile_onto(a,b);
		} else {
			pile_over(a,b);
		}

	}
	

	print_world();

	return 0;
}