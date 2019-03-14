#include <bits/stdc++.h>
using namespace std;

int main(){

    int p[1000000];
    int team_ref[1001];

    int n_teams;

    int scenario = 1;

    while( cin >> n_teams && n_teams != 0 ){
        queue<int> teams[1001];
        
        for (int i = 0; i < 1001; ++i) {
            team_ref[i] = -1;
        }

        int begin = 0;
        int end = 0;

        for (int i = 0; i < n_teams; ++i){
            int team_size;
            cin >> team_size;
            int index;
            for (int j = 0; j < team_size; ++j) {
                cin >> index;
                p[index] = i;
            }
        }

        cout << "Scenario #" << scenario++ << endl;

        string s;

        while (cin >> s && s != "STOP"){
            int e;

            if (s == "ENQUEUE"){
                cin >> e;
                if (team_ref[p[e]] == -1){

                    teams[end].push(e);
                    team_ref[p[e]] = end;
                    end = (end+1)%n_teams;
                } else {
                    teams[ team_ref[p[e]]].push(e);
                }


            } else {

                if (!teams[begin].empty()){
                    e = teams[begin].front();
                    cout << e << endl;
                    teams[begin].pop();

                    if (teams[begin].empty()){
                        begin = (begin+1)%n_teams;
                        team_ref[p[e]] = -1;
                    }
                }

            }


        }

        cout << endl;


    }

    return 0;

}
