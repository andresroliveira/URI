#include <bits/stdc++.h>
using namespace std;

string notas[] = {"si","do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#"};

int escala[12][7] = {
    {0,2,4,5,7,9,11},
    {0,1,3,5,6,8,10},
    {1,2,4,6,7,9,11},
    {0,2,3,5,7,8,10},
    {1,3,4,6,8,9,11},
    {0,2,4,5,7,9,10},
    {1,3,5,6,8,10,11},
    {0,2,4,6,7,9,11},
    {0,1,3,5,7,8,10},
    {1,2,4,6,8,9,11},
    {0,2,3,5,7,9,10},
    {1,3,4,6,8,10,11}
};

int main() {

	int vet[12],n,a;
	for(int k=0;k<12;k++){
		vet[k] = 0;
		for(int j=0;j<7;j++){
			vet[k] |= 1 << escala[k][j];
		}
	}

	scanf("%d",&n);

	int s = 0;
	while(n--){
		scanf("%d",&a);
		a %= 12;
		s |= 1 << a;
	}

	int r = -1;
	for(int k=0;k<12 && r == -1;k++){
		int aux = s | vet[k];
		if(aux == vet[k]) r = k;
	}

	puts(r == -1 ? "desafinado" : notas[r].c_str());
	return 0;
}