#include <bits/stdc++.h>
#define NMAX 10010
using namespace std;

int n, k;
int doce[NMAX], peso[NMAX];
int memo[1010][NMAX];

int mochila(int pos, int cap){
	if(pos == n || cap <= 0) return 0;
	if(memo[pos][cap] != -1) return memo[pos][cap];

	int r1 = 0, r2 = 0;

	r1 = mochila(pos+1, cap);
	if(peso[pos] <= cap) r2 = doce[pos] + mochila(pos+1, cap-peso[pos]);

	return memo[pos][cap] = max(r1, r2);
}

int main(){
	while(scanf("%d %d", &n, &k) != EOF){
		memset(memo, -1, sizeof memo);

		for(int i=0;i<n;i++) scanf("%d", doce+i);
		for(int i=0;i<n;i++) scanf("%d", peso+i);

		int r = mochila(0, k);

		printf("%d\n", r);
	}

	return 0;
}
