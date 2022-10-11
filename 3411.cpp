#include <bits/stdc++.h>

#define NMAX 111
#define MOD 100000007
#define ll long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define dd pair<double, double>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define len(s) (int)(s).length()
#define sz(a) (int)(a).size()
#define cstr(s) (s).c_str()
#define all(a) (a).begin(), (a).end()
#define db(x) cerr << #x << " = " << x << '\n';
#define db2(x, y)                                                              \
  cerr << #x << " = " << x << " || " << #y << " = " << y << '\n';
#define db3(x, y, z)                                                           \
  cerr << #x << " = " << x << " || " << #y << " = " << y << " || " << #z       \
       << " = " << z << '\n';
#define db4(x, y, z, w)                                                        \
  cerr << #x << " = " << x << " || " << #y << " = " << y << " || " << #z       \
       << " = " << z << " || " << #w << " = " << w << '\n';
#define toRad(a) (a) * PI / 180.0
#define myabs(a) ((a) < 0 ? -(a) : (a))
#define mdc __gcd

const double EPS = 1e-9;
const double PI = acos(-1);
const int oo = 0x3f3f3f3f;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

using namespace std;

int c, l;

bool is_valid(int x, int y) { return x >= 0 && x < c && y >= 0 && y < l; }

void flood(vvi &grid, int x, int y, int n, int m) {
  grid[x][y] = n;

  for (int k = 0; k < 4; k++) {
    int i = x + dx[k];
    int j = y + dy[k];

    if (!is_valid(i, j))
      continue;

    if (grid[i][j] == m) {
      grid[i][j] = n;
      flood(grid, i, j, n, m);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> c >> l;

  vvi grid(c + 10, vi(l + 10, 0));

  for (int i = 0; i < c; i++) {
    for (int j = 0; j < l; j++) {
      cin >> grid[i][j];
    }
  }
  int x, y, n;
  cin >> x >> y >> n;

  flood(grid, x, y, n, grid[x][y]);

  for (int i = 0; i < c; i++) {
    cout << grid[i][0];
    for (int j = 1; j < l; j++) {
      cout << ' ' << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}
