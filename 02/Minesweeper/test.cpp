#include <iostream>
using std::cin;
using std::cout;

int main(int argc, char *argv[])
{
    char ch;
    unsigned m = 10;

    int i = 0;
    while (cin && m--) {
        cin.read(&ch, sizeof(ch));
        i++;
        if (ch == '\n')
        	cout << "OPA" << std::endl;
        cout << i << ": " << ch << std::endl;
    }
    return 0;
}