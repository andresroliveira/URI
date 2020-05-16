#include <bits/stdc++.h>
#define NMAX 1010

using namespace std;

int n, m; 
int tr[NMAX][NMAX], mat[NMAX][NMAX];

void update(int x, int y, int val){
    for(int i = x+1; i <= n; i += (i&-i)){
        for(int j = y+1; j <= n; j += (j&-j)){
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
    int r = 0;

    r += query(x2, y2);
    r -= query(x2, y1-1);
    r -= query(x1-1, y2);
    r += query(x1-1, y1-1);

    return r;
}

void build(){   
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            update(i, j, mat[i][j]);
        }
    }
}

void imprime(){
    for(int i=0;i<=n;i++){
        printf("%d", tr[i][0]);
        for(int j=1;j<=n;j++) printf(" %d", tr[i][j]);
        putchar('\n');
    }
}

int main(){ 
    while(scanf("%d %d", &n, &m) != EOF){
        memset(tr, 0 , sizeof tr);

        for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &mat[i][j]);

        build();

        while(m--){
            int a, b, c, d;

            scanf("%d %d", &a, &b); update(a-1, b-1, 1);
            scanf("%d %d %d %d", &a, &b, &c, &d); printf("%d\n", query(a-1, b-1, c-1, d-1));
        }
    }

    return 0;
}