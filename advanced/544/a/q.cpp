#include <bits/stdc++.h>
using namespace std;

int main(){
	int h1,m1;
	int h2,m2;

	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);

	int x1 = h1*60 + m1;
	int x2 = h2*60 + m2;

	int mid = (x2+x1)/2;

	printf("%.2d:%.2d\n", (mid/60),(mid%60));

	return 0;
}