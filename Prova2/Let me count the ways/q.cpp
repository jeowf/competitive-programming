#include <iostream>

int coins[5] = {5, 10, 25, 50};
long long numbers[30002];

int main()
{
	for(long long i = 0; i < 30002; i++) {
		numbers[i] = 1;
	}

	for(long long i = 0; i < 4; i++) {
		for(long long j = coins[i]; j < 30002; j++) {
			numbers[j] += numbers[j - coins[i]];
		}
	}

	long long n;

	while(std::cin >> n){
		if(numbers[n] == 1)
			std::cout << "There is only 1 way to produce " << n << " cents change." << std::endl;
		else
			std::cout << "There are " << numbers[n] << " ways to produce " << n << " cents change." << std::endl;
	}
	
	return 0;
}
