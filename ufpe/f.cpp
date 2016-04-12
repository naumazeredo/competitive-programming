#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int t, n, x, m;
int a[2222222];
int h[2222222];
int p[2222222];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    printf("Caso #%d:\n", tt);

    memset(a, 0, sizeof(a));
    memset(h, 0, sizeof(h));
    memset(p, 0, sizeof(p));

    scanf("%d%d%d", &n, &x, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
    for (int i = 0; i < n; ++i) scanf("%1d", &a[i]);

    p[0] = (a[0] and h[0]<x);
    for (int i = 1; i < n; ++i) p[i] = p[i-1]+(a[i] and h[i]<x);

    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%d\n", p[b-1] - (a-1>0?p[a-2]:0));
    }
  }
  return 0;
}
