#include <iostream>
#include <vector>

using namespace std;

int main(){

	int N, n;

	while (cin >> N >> n && N!=0 && n!=0){
		char** big = new char*[N];
		for (int i = 0; i < N; ++i){
			big[i] = new char[N];		
			for (int j = 0; j < N; ++j){
				cin >> big[i][j];
			}
		}

		char** little = new char*[n];
		for (int i = 0; i < n; ++i){
			little[i] = new char[n];		
			for (int j = 0; j < n; ++j){
				cin >> little[i][j];
			}
		}

	}

	return 0;
}