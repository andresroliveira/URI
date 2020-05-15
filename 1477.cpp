#include <bits/stdc++.h>
#define NMAX 100010
using namespace std;

class Jogo{
private:
	int humano, elefante, rato;
public:
	Jogo(){
		humano = elefante = rato = 0;
	}
	Jogo(int _humano, int _elefante, int _rato){
		humano = _humano;
		elefante = _rato;
		rato = _rato;
	}

	void swap(){
		int aux = elefante;
		elefante = humano;
		humano = rato;
		rato = aux;
	}

	Jogo operator+(const Jogo &a){
		Jogo aux = Jogo();
		aux.humano = humano + a.humano;
		aux.elefante = elefante + a.elefante;
		aux.rato = rato + a.rato;
		return aux;
	}

	void print(){
		printf("%d %d %d\n", humano, elefante, rato);
	}
};

Jogo tr[NMAX * 4 + 1];
int lz[NMAX * 4 + 1];

void build(int no, int l, int r){
	lz[no] = 0;
	if(l == r){
		Jogo aux = Jogo(1,0,0);
		tr[no] = aux;
		return;
	}
	
	int nxt = no << 1;
	int mid = (l+r) >> 1;
	
	build(nxt, l, mid);
	build(nxt+1, mid+1, r);
	
	tr[no] = tr[nxt]+ tr[nxt+1];
}

void propagate(int no, int l, int r){
	if(!lz[no]) return;
	
	int aux = (lz[no]) % 3;
	
	while(aux--) tr[no].swap();
	
	if(l != r){
		lz[no*2] += lz[no];
		lz[no*2 + 1] += lz[no];
	}
	
	lz[no] = 0;
}

Jogo query(int no, int l, int r, int i, int j){
	propagate(no, l, r);
	Jogo aux = Jogo()	;
	if(i > r || j < l) return aux;
	if(i <= l && j >= r) return tr[no];
	
	int nxt = no << 1;
	int mid = (l+r) >> 1;
	
	return query(nxt, l, mid, i, j) + query(nxt+1, mid+1, r, i, j);	
}

void update(int no, int l, int r, int i, int j){
	propagate(no, l, r);
	
	if(i > r || j < l) return;
	if(i <= l && j >= r){
		lz[no] = 1;
		propagate(no, l, r);
		return;
	}
	
	int nxt = no << 1;
	int mid = (l+r) >> 1;
	
	update(nxt, l, mid, i, j);
	update(nxt+1, mid+1, r, i, j);
	
	tr[no] = tr[nxt] + tr[nxt+1];
}

int main(){
	int n, m, a, b;
	char c;
	while(scanf("%d%d", &n, &m) != EOF){
		build(1, 1, n);
		while(m--){
			scanf(" %c %d %d", &c, &a, &b);

			if(c == 'C') query(1, 1, n, a, b).print();
			else update(1, 1, n, a, b);	
		}
		putchar('\n');
	}

	return 0;
}