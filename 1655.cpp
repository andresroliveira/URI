#include <bits/stdc++.h>
#define NMAX 111
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

long double prob[NMAX][NMAX];

void addAresta(int ori, int des, long double p){
	prob[ori][des] = p/100.0;
	prob[des][ori] = p/100.0;
}

void floyd(int v){
	for(int k=1;k<=v;k++){
		for(int i=1;i<=v;i++){
			for(int j=1;j<=v;j++){
				prob[i][j] = max(prob[i][j], prob[i][k]*prob[k][j]);
			}
		}
	}
}

void imprime(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cerr << prob[i][j] << " ";
		cerr << "\n";
	}
	cerr << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while(scanf("%d", &n), n){
    	scanf("%d", &m);

    	for(int i=0;i<=n;i++) for(int j=i;j<=n;j++) prob[i][j] = prob[j][i] = 0.0;

    	while(m--){
    		int a, b, c; scanf("%d %d %d", &a, &b, &c);
    		addAresta(a, b, c);
    	}

    	floyd(n);

    	long double ans = 100*prob[1][n];
    	cout << fixed << setprecision(6) << ans << " percent\n";
    }

    return 0;
}
