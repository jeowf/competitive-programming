#include <iostream>

int main(){
	int t;

	std::cin >> t;

	long a,b,c;

	for (int i = 0; i < t; i++){
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;

		std::cout << "Case " << (i+1) << ": ";

		if ((a <= b && a >= c) || (a <= c && a >= b)){
			std::cout << a << std::endl;
		} else if ((b <= a && b >= c) || (b <= c && b >= a)){
			std::cout << b<< std::endl;
			
		} else {
			std::cout << c << std::endl;

		}
	}

	return 0;
}