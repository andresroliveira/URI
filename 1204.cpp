#include <bits/stdc++.h>
#define NMAX 1000010
#define MOD 100000007
#define ll long long
#define ii pair<int,int>
#define iii pair<int, ii >
#define dd pair<double,double>
#define vi vector< int >
#define vd vector< double >
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

double a, b;

double tempo(double x, double y, double vx, double vy){
    return (-((vx*x)/(a*a)) - (vy*y)/(b*b) + sqrt(b*b*vx*vx + a*a*vy*vy - vy*vy*x*x + 2*vx*vy*x*y - vx*vx*y*y)/(a*b))/(vx*vx/(a*a) + vy*vy/(b*b));
}

double dot(vd v, vd u){
    return v[0]*u[0] + v[1]*u[1];
}

void normalize(vd &u){
    double len = sqrt(dot(u, u));
    u[0] /= len;
    u[1] /= len;
}

vd multiplica_escalar(double a, vd v){
    return {a*v[0], a*v[1]};
}

vd soma(vd u, vd v){
    return {u[0]+v[0], u[1]+v[1]};
}

vd reflete(vd v, double x, double y){
    vd u = {-2*y/(b*b), 2*x/(a*a)};
    normalize(u);

    // printf("|u|^2 = %lf\n", dot(u,u));

    return soma(multiplica_escalar(2*dot(u,v), u), multiplica_escalar(-1, v));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double x, y, vx, vy;

    while(cin >> x >> y >> vx >> vy >> a >> b){
        vd p = {x, y};
        vd v = {vx, vy};
        int cont = 0;

        do{
            double t = tempo(p[0], p[1], v[0], v[1]);

            p[0] += t*v[0];
            p[1] += t*v[1];

            printf("%.3lf %.3lf\n", p[0], p[1]);

            v = reflete(v, p[0], p[1]);
            cont++;
        }while(cont <= 1);
    }

    return 0;
}
