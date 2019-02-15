#include <iostream>

int main(){
	int t;

	std::cin >> t;

	//long a,b,c;
	std::cout << t << ":" << std::endl;

	for (int i = 2; i < t; i++){
		for (int j = 1; j >= 0; j--){
			int a = i;
			int b = a - j;

			int t1 = ( (t/(a+b))*(a+b) );
			int t2 = ((t/(a+b)) + 1)*a + ((t/(a+b)))*b;

			if (t1 == t || t2 == t)
				std::cout << a << ", " << b << std::endl; 
		}
		
	}

	return 0;
}