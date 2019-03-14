#include <bits/stdc++.h>
using namespace std;

struct rect{
	int height;
	int width;
};

int main(){

	rect histogram[100001];
 

	int n;

	while (cin >> n && n != 0){

		for (int i = 0; i < n; ++i) {

			int h;
			cin >> h;

			if (i == 0){
				histogram[i].height = h;
				histogram[i].width = 1;
			} else {

			}

			cin >> histogram[i].height;
			histogram[i].width = 1;

			if (i > 0 && )

		
		}

	}

	return 0;

}