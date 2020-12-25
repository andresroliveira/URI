#include <bits/stdc++.h>

using namespace std;
const double pi = 3.14159265358979323846;

int main(){
	int t; scanf("%d", &t);
	
	int l = 0, p = 0;
	
	vector <int> vec;
	
	while(t--){
		int a, b; scanf("%d^%d", &a, &b);
		int n; scanf("%d!", &n);
		
//		printf("a = %d, b = %d, n = %d\n", a, b, n);
		
		double res_l = (double)b*log((double)a);
		double res_p = (double)n*(log((double)n) - 1.0) + 0.5*log(2*pi*n) + 1/(12.0*n);
		
		if(res_l > res_p){
//			puts("Lucas");
			l++;
			vec.push_back(0);
		}
		else{ 
//			puts("pedro");
			p++;
			vec.push_back(1);
		}
	}
	
	if(l == p) puts("A competicao terminou empatada!");
	else printf("Campeao: %s!\n", l > p ? "Lucas" : "Pedro");
	
	for(int i=0;i<vec.size();i++) printf("Rodada #%d: %s foi o vencedor\n", i+1, !vec[i] ? "Lucas" : "Pedro");
	
	return 0;
}
