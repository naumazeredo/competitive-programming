#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m;
char s[N];

pii memo[N];
int bit[2][2][N];

void add(int p, int a, int x) { for (x+=2; x<N; x+=x&-x) bit[p][a][x]++; }
int query(int p, int a, int x) {
  int sum = 0;
  for (x+=2; x; x-=x&-x) sum += bit[p][a][x];
  return sum;
}

int query(int p, int a, int l, int r) {
  return query(p, a, r) - query(p, a, l);
}

pii go(int p) {
  if (memo[p].st != -1) return memo[p];
  if (p + m > n) return {0, 0};

  pii ans = { 0, 0 };

  int par = p&1;
  if (query(par, 1, p-1, p+m-1) == 0 and query(1-par, 0, p-1, p+m-1) == 0) {
    pii g = go(p+m);
    ans.st = 1 + g.st;
    ans.nd = m - query(par, 0, p-1, p+m-1) - query(1-par, 1, p-1, p+m-1) + g.nd;
  }

  pii g = go(p+1);
  if (g.st > ans.st or (g.st == ans.st and g.nd < ans.nd)) ans = g;

  return memo[p] = ans;
}

int main() {
  scanf("%d%s%d", &n, s, &m);

  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') add(i%2, 0, i);
    if (s[i] == 'b') add(i%2, 1, i);
    memo[i].st = -1;
  }

  printf("%d\n", go(0).nd);

  return 0;
}
