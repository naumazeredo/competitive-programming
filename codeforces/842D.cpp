#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

int n, m, a, x, k;
int trie[32*N][2], trien=1, triesz[32*N];

void add(int r, int d, int v) {
  if (d < 0) { triesz[r] = 1; return; }
  int x = (v>>d)&1;
  if (!trie[r][x]) trie[r][x] = ++trien;
  add(trie[r][x], d-1, v);
  triesz[r] = triesz[trie[r][0]] + triesz[trie[r][1]];
}

int query(int r, int d, int v) {
  if (d < 0) return 0;
  int x = (v>>d)&1;
  if (triesz[trie[r][x]] < (1<<d)) return query(trie[r][x], d-1, v);
  return query(trie[r][1-x], d-1, v)+(1<<d);
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    add(1, 25, a);
  }

  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    k^=x;
    printf("%d\n", query(1, 25, k));
  }
  return 0;
}
