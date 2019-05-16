#include <bits/stdc++.h>

using namespace std;

int main(){

	int cases;
	cin >> cases;

	for (int i = 0; i < cases; ++i) {
		int aux;
		int min = 0;
		int max = 0;

		int l, n;

		cin >> l >> n;

		for (int j = 0; j < n; ++j) {
			cin >> aux;
			if (aux >= l-aux)
				aux = l-aux;

			if (aux > min) min = aux;
			if (l-aux > max) max = l-aux;
		}

		cout << min << " " << max << endl;
	}


	return 0;
}

/*
#include <stdio.h>

int main() {
    int t, x;
    scanf("%d", &t);
    while(t--) {
        int l, n, min = 0, max = 0;
        scanf("%d %d", &l, &n);
        while(n--) {
            scanf("%d", &x);
            x = x < l-x ? x : l-x;
            if(x > min)
                min = x;
            if(l-x > max)
                max = l-x;
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}*/