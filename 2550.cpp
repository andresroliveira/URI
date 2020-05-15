#include<bits/stdc++.h>
#define NMAX 1010
#define ll long long
#define oo 0x3f3f3f3f

using namespace std;

struct aresta{
    int a, b, c;

    bool operator<(const aresta v)const{
        return c < v.c;
    }
};

vector <aresta> grafo;
vector < vector <int> > adj;
int pai[NMAX];
int visitado[NMAX];

int findset(int u){
    if(pai[u] == u) return u;

    return pai[u] = findset(pai[u]);
}

void unionset(int u, int v){
    u = findset(u);
    v = findset(v);

    pai[v] = u;
}

int dfs(int u){
    visitado[u] = 1;
    int r = 1;

    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];

        if(visitado[v]) continue;

        r += dfs(v);
    }

    return r;
}

int main(){
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF){
        grafo.clear(); adj.assign(NMAX, vector <int> ());
        memset(visitado, 0, sizeof visitado);
        for(int i=1;i<=n;i++) pai[i] = i;

        while(m--){
            int a, b, c; scanf("%d %d %d", &a, &b, &c);

            aresta aux = {a, b, c};
            grafo.push_back(aux);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int r = dfs(1);

        if(r != n){
            puts("impossivel");
            continue;
        }

        sort(grafo.begin(), grafo.end());

        int ans = 0;

        for(int i=0;i<grafo.size();i++){
            int a = grafo[i].a;
            int b = grafo[i].b;
            int c = grafo[i].c;

            if(findset(a) != findset(b)){
                unionset(a, b);
                ans += c;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
