#include <bits/stdc++.h>
#define NMAX 1010

using namespace std;

int n, m; 
int tr[NMAX][NMAX], mat[NMAX][NMAX];

void swap(int *a, int *b){
	int A = *a, B = *b;
	*a = B, *b = A;
}

void update(int x, int y, int val){
	for(int i = x+1; i <= n; i += (i&-i)){
		for(int j = y+1; j <= m; j += (j&-j)){
			tr[i][j] += val;
		}
	}
}

int query(int x, int y){
	int r = 0;
	
	for(int i = x+1; i > 0; i -= (i&-i)){
		for(int j = y+1; j > 0; j -= (j&-j)){
			r += tr[i][j];
		}
	}
	
	return r;
}

int query(int x1, int y1, int x2, int y2){
	if (x1 > x2) swap(&x1, &x2);
    if (y1 > y2) swap(&y1, &y2);
	
	int r = 0;
	
	r += query(x2, y2);
	r -= query(x2, y1-1);
	r -= query(x1-1, y2);
	r += query(x1-1, y1-1);
	
	return r;
}

void build(){	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			update(i, j, mat[i][j]);
		}
	}
}

void imprime(){
	for(int i=0;i<=n;i++){
		printf("%d", tr[i][0]);
		for(int j=1;j<=m;j++) printf(" %d", tr[i][j]);
		putchar('\n');
	}
}

int main(){	
	while(scanf("%d %d", &n, &m) != EOF){
		memset(tr, 0 , sizeof tr);
		
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", &mat[i][j]);
		
		build();
		int q; scanf("%d", &q);
		
		while(q--){
			int r, a, b, c, d; scanf("%d %d %d %d %d", &r, &a, &b, &c, &d);
			
			if(r) printf("%d\n", query(a-1, b-1, c-1, d-1));
			else update(a-1, b-1, -1), update(c-1, d-1, 1);
		}
	}
	
	return 0;
}