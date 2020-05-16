#include <bits/stdc++.h>
#define NMAX 100010

using namespace std;

struct neto{
	int id, valor;

	neto(){
		id = valor = 0;
	}
	neto(int _id, int _valor){
		id = _id, valor = _valor;
	}

	void set(int val){
		valor = val;
	}

	void add(int val){
		valor += val;
	}
};

neto max(neto a, neto b){
	if(a.valor != b.valor) return (a.valor > b.valor) ? a : b;
	return (a.id < b.id) ? a : b;
}

neto tr[4*NMAX], v[NMAX];
int lz[4*NMAX];

void limpar(){
	for(int i=0;i<4*NMAX;i++) tr[i] = neto(0, 0), lz[i] = 0;
	for(int i=0;i<NMAX;i++) v[i] = neto(0, 0);
}

void build(int no, int l, int r){
	lz[no] = 0;

	if(l == r){
		tr[no] = v[l];
		return;
	}

	int nxt = no << 1, mid = (l+r) >> 1;

	build(nxt, l, mid);
	build(nxt+1, mid+1, r);

	tr[no] = max(tr[nxt], tr[nxt+1]);
}

void propagate(int no, int l, int r){
	if(!lz[no]) return;

	tr[no].add(lz[no]);

	if(l != r){
		lz[no*2] += lz[no];
		lz[no*2 + 1] += lz[no];
	}

	lz[no] = 0;
}

void update(int no, int l, int r, int i, int j, int v){
	propagate(no, l, r);
	if(r < i || l > j) return;

	if(i <= l && j >= r){
		lz[no] = v;
		propagate(no, l, r);
		return;
	}

	int nxt = no << 1, mid = (l+r) >> 1;
	update(nxt, l, mid, i, j, v);
	update(nxt+1, mid+1, r, i, j, v);

	tr[no] = max(tr[nxt], tr[nxt+1]);
}

neto query(int no, int l, int r, int i, int j){
	propagate(no, l, r);
	if(r < i || l > j) return neto();

	if(i <= l && j >= r) return tr[no];

	int nxt = no << 1, mid = (l+r) >> 1;

	return max(query(nxt, l, mid, i, j), query(nxt+1, mid+1, r, i, j));
}

int main(){	
	int n, q; 

	while(scanf("%d %d", &n, &q) != EOF){
		limpar();

		for(int i=0;i<n;i++){
			int a; scanf("%d", &a);
			v[i].id = i+1;
			v[i].valor = a;
		}

		build(1, 0, n-1);

		while(q--){
			char c; scanf(" %c", &c);

			if(c == 'C'){
				int i, j; scanf("%d %d", &i, &j);
				neto a = query(1, 0, n-1, i-1, j-1);
				printf("%d\n", a.id);
			}
			else{
				int i, j, v; scanf("%d %d %d", &i, &j, &v);
				update(1, 0, n-1, i-1, j-1, v);
			}
		}
	}

	return 0;
}