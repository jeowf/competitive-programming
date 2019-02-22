#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	int r = -1, c = -1;
	int m[103][103] = {0};

	char ch;

	int count = 1;

	std::string line;

	bool valid = true;

	while(valid){

		std::cin >> r >> c;

		if (c == 0 && r == 0){
			valid = false;
			continue;
		}

		// leitura da matriz

		for (int i = 1; i <= r; ++i) {

			std::cin >> line;

			for (int j = 1; j <= c; ++j) {

				if (line[j-1] == '*'){
					m[i][j] = -1;
					for (int k = i-1; k <= i+1; ++k) {
						for (int l = j-1; l <= j+1; ++l) {

							if (m[k][l] != -1) m[k][l]++;
							
						}
					}
				}

			}
		}

		// output

		if (count > 1){
			std::cout << std::endl;

		}

		std::cout << "Field #" << count << ":" << std::endl;

		for (int i = 1; i <= r+1; ++i) {
			for (int j = 1; j <= c+1; ++j) {
				if (i < r+1 && j < c+1){

					if (m[i][j] == -1)
						std::cout << '*';
					else
						std::cout << m[i][j];
				}
				

				m[i][j] = 0;
			}
			if (i <= r)
				std::cout << std::endl;
		}


		count++;

	}

	return 0;
}