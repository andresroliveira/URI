#include <bits/stdc++.h> 

using namespace std;

map < string, int > D;
map < string, int > CD;

int main(void){
	int t;

	while(~scanf("%d", &t)){
		if(!t) return 0;

		D.clear();
		CD.clear();

		char d[159], cd[159];
		bool f = true, i = true;

		while(t--){getchar();
			scanf("%s -> %s", d, cd);

			if(D.count(d)) f = false;
			else D[d] = 1;

			if(CD.count(cd)) i = false;
			else CD[cd] = 1;
		}

		if(!f) printf("Not a function.\n");
		else printf("%s\n", (i) ? "Invertible." : "Not invertible.");
	}

	return 0;
}