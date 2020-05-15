#include <bits/stdc++.h>
#define NMAX 505
#define MOD 100000007
#define ll long long
#define ii pair<int,int>
#define iii pair<int, ii >
#define dd pair<double,double>
#define vi vector< int >
#define vii vector< ii >
#define vvi vector< vi >
#define vvii vector< vii >
#define len(s) (int)(s).length()
#define sz(a) (int)(a).size()
#define cstr(s) (s).c_str()
#define all(a) (a).begin(), (a).end()
#define ok(a) cerr << "OK " << a << '\n';
#define db(x) cerr << #x << " = " << x << '\n';
#define db2(x, y) cerr << #x << " = " << x << " || " << #y << " = " << y << '\n';
#define db3(x, y, z) cerr << #x << " = " << x << " || " << #y << " = " << y << " || " << #z << " = " << z << '\n';
#define db4(x, y, z, w) cerr << #x << " = " << x << " || " << #y << " = " << y << " || " << #z << " = " << z << " || " << #w << " = " << w << '\n';
#define toRad(a) (a)*PI/180.0
#define myabs(a) ((a) < 0 ? -(a) : (a))
#define mdc __gcd

const double EPS = 1e-9;
const double PI = acos(-1);
const int oo = 0x3f3f3f3f;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

using namespace std;

struct aresta{
	int a, b;
	double c;
};

bool ord(aresta u, aresta v){
	return u.c < v.c;
}

vector < aresta > grafo;

void addAresta(int a, int b, double c){
	aresta aux = {a, b, c};

	grafo.push_back(aux);
}

int p[NMAX];

int findset(int u){
	if(u == p[u]) return u;

	return p[u] = findset(p[u]);
}

void unionset(int u, int v){
	u = findset(u);
	v = findset(v);

	p[v] = u;
}

int main(){
    int c; scanf("%d", &c);

    while(c--){
    	int n; scanf("%d", &n);

    	int x[n], y[n];

    	for(int i=0;i<n;i++) scanf("%d %d", x + i, y + i), p[i] = i;

    	grafo.assign(n+1, aresta());

    	for(int i=0;i<n;i++){
    		for(int j=i+1;j<n;j++){
    			double dist = hypot(x[i]-x[j], y[i] - y[j]);
    			addAresta(i, j, dist/100.0);
    		}
    	}

    	sort(all(grafo), ord);
    	double r = 0;

    	for(int i=0;i<sz(grafo);i++){
    		int a = grafo[i].a;
    		int b = grafo[i].b;
    		double c = grafo[i].c;

    		if(findset(a) != findset(b)){
    			unionset(a, b);
    			r += c;
    		}
    	}

    	printf("%.2lf\n", r);
    }

    return 0;
}
