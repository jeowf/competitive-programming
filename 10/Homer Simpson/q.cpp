#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m,t;

    int memo[10000];
    
    while(cin >> n >> m >> t){
        memo[0] = 0;
        for (int i = 1; i < t+1; ++i) 
            memo[i] = -1;

        
        for(int i=1; i<=t; i++){
            if( i>=n and memo[i-n]!=-1 ) {
                memo[i]=memo[i-n] + 1;
            }

            if( i>=m and memo[i-m]!=-1 ) {
                memo[i] = max(memo[i], memo[i-m] + 1);
            }
        }
        
        if(memo[t] != -1) 
            cout << memo[t] << endl;
        else{
            int i = t;
            while(1){
                if(memo[i]!=-1){
                    cout << memo[i] << " " << t-i << endl;
                    //printf("%d %d\n",memo[i],t-i);
                    break;
                }
                i--;
            }
        }
    }
    
    return 0;
}