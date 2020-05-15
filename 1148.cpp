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

int n, e; 
int dist[NMAX][NMAX];

void addAresta(int a, int b, int c){
	if(dist[b][a] != oo){
		dist[a][b] = dist[b][a] = 0;
		return;
	}

	dist[a][b] = c;
}

void floyd_warshall() {
    for(int k = 0; k <= n; k++){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(scanf("%d %d", &n, &e), (n+e)){
    	memset(dist, oo, sizeof dist);

    	while(e--){
    		int a, b, c; scanf("%d %d %d", &a, &b, &c);

    		addAresta(a, b, c);
    	}

    	floyd_warshall();

    	int k; scanf("%d", &k);

    	while(k--){
    		int a, b; scanf("%d %d", &a, &b);

			int r = dist[a][b];

			if(r == oo) puts("Nao e possivel entregar a carta");
			else printf("%d\n", r); 
    	}

    	putchar('\n');
    }
    return 0;
}
