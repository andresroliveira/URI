#include <bits/stdc++.h>
#define NMAX 1000010
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
#define ok(a) cerr << "OK " << a << '\n'
#define db(x) cerr << #x << " = " << x << '\n'
#define db2(x, y) cerr << #x << " = " << x << " || " << #y << " = " << y << '\n'
#define db3(x, y, z) cerr << #x << " = " << x << " || " << #y << " = " << y << " || " << #z << " = " << z << '\n'
#define db4(x, y, z, w) cerr << #x << " = " << x << " || " << #y << " = " << y << " || " << #z << " = " << z << " || " << #w << " = " << w << '\n'
#define toRad(a) (a)*PI/180.0
#define myabs(a) ((a) < 0 ? -(a) : (a))
#define mdc __gcd

const double EPS = 1e-9;
const double PI = acos(-1);
const int oo = 0x3f3f3f3f;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

using namespace std;

map <char, int> dic;
map <char, int> :: iterator it;

void preCalc(){
	for(char i='0';i<='9';i++) dic[i] = sz(dic) - 1;
	for(char i='A';i<='Z';i++) dic[i] = sz(dic) - 1;
	for(char i='a';i<='z';i++) dic[i] = sz(dic) - 1;
}

bool valid(char c){
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    preCalc();

    string s;

    while(cin >> s){
    	int maior = -1;
    	int sum = 0;
    	for(int i=0;s[i];i++){
    		if(!valid(s[i])) continue;
    		int atu = dic[s[i]];
    		sum += atu;
    		maior = max(maior, atu);
    	}

    	if(maior == 0){
    		puts("2");
    		continue;
    	}
    	
    	int r = -1;

    	for(int i=maior;i<=62 && !(r+1);i++){
    		if(sum % i == 0) r = i + 1;
    	}

    	if(r == -1) puts("such number is impossible!");
    	else printf("%d\n", r);
    }

    return 0;
}
