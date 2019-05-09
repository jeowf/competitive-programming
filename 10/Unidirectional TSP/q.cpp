#include <bits/stdc++.h>

using namespace std;

int main(){

	
	int height, width;

	while (cin >> height >> width){

		int matrix[11][101];
		int refs[11][101];
		int weights[11][101];

		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				cin >> matrix[i][j];
				weights[i][j] = INT_MAX;
			}
		}




		for (int i = 0; i < height; ++i) {
			weights[i][0] = matrix[i][0];
			refs[i][0] = 0;
		}

		for (int j = 1; j < width; ++j) {
			for (int i = 0; i < height; ++i){
			

				for (int k = -1; k <= 1; ++k) {
					int wei = weights[(i - k + height)%height][j-1] + matrix[i][j];
					if (wei < weights[i][j]){
						weights[i][j] = wei;
						refs[i][j] = k;
					} /*else if (wei == weights[i][j]){
						if ( (i - k + height)%height < (i - refs[i][j] + height) % height)
							refs[i][j] = k;
					}*/
				}
			}
		}


		int min_wei = weights[0][width-1];
		for (int i = 1; i < width; ++i)
		{
			if (min_wei > weights[i][width-1])
				min_wei = weights[i][width-1];
		}

		for (int i = 0; i < height; ++i) {
			if (weights[i][width-1] == min_wei){
				long long num = weights[i][width-1];
				long long dec = 1;

				int lin = i + refs[i][];

				for (int i = width-2; i >=0; --i)
				{
					dec*=10;


				}
			}
		}

		cout << min_wei << endl;

		/*

		for (int i = 0; i < height; ++i)
		{
			cout << weights[i][width-1] << endl;
		}

		
*/
		//cout << endl;

	}


	return 0;
}