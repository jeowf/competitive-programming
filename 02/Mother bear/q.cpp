#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool is_char( char x ){
    return x != '.' && 
           x != ',' && 
           x != '!' &&
           x != ' ' &&
           x != '?';
}

int main(int argc, char *argv[]){
    string s = "";

    while (1){
        getline(cin, s);
        if (s == "DONE") break;

        int i = 0, f = s.size() - 1;   

        bool p = true;

        while (i != f && s.size()>0){
            if (is_char(s[i])){
                if (is_char(s[f])){

                    if (tolower(s[i]) != tolower(s[f])){
                        p = false;
                        break;
                    }

                    i++; f--;
                } else {
                    f--;
                }
            } else {
                i++;
            }
        }
        

        if (p)
            cout << "You won't be eaten!" << endl;
        else
            cout << "Uh oh.." << endl;

    }

    return 0;
}