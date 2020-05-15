#include <bits/stdc++.h>

using namespace std;

int fib[1510];

int main(){
	fib[0] = 0;
	fib[1] = 1;

	for(int i=2;i<1510;i++){
		fib[i] = fib[i-2] + fib[i-1];
		fib[i] %= 1000;
	}

	int t; cin >> t;

	while(t--){
		string s; cin >> s;

		int k = 0;

		for(int i=0;s[i];i++){
			k = 10*k + (s[i]-'0');
			k %= 1500;
		}
		
		printf("%.3d\n", fib[k]);
	}

	return 0;
}