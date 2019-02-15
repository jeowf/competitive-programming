#include <iostream>

int main(){
	int t;

	std::cin >> t;

	//long a,b,c;

	for (int i = 2; i < t; i++){
		for (int j = 1; j >= 0; j--){
			int a = i;
			int b = a - j;

			if ( ((float) t/(a+b)) == ((float) t)  || 
				((float) t/(a+b)) == ((float) t) )
			std::cout << a << ", " << b << std::endl; 
		}
		
	}

	return 0;
}