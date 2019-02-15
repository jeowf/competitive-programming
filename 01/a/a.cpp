#include <iostream>

int main(){
	int t;

	std::cin >> t;

	long a,b;

	for (int i = 0; i < t; i++){
		std::cin >> a;
		std::cin >> b;

		if (a < b){
			std::cout << "<" << std::endl;
		} else if (a > b){
			std::cout << ">" << std::endl;
		} else {
			std::cout << "=" << std::endl;

		}
	}

	return 0;
}