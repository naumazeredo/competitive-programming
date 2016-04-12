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

int t, n;
int adj[10000];
int m[10000];
int s[11111];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    memset(adj, 0, sizeof(adj));
    memset(m, 0, sizeof(m));
    memset(s, 0, sizeof(s));

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      if (x != i) adj[i] = x, s[x]++;
      m[x]=1;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) if (!s[i]) q.push(i);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (adj[u]) {
        s[adj[u]]--;
        if (!s[adj[u]]) q.push(adj[u]);
      }
    }

    int res0 = n, res1 = 0;
    for (int i = 1; i <= n; ++i) res0 -= m[i], res1 += !s[i];

    printf("Caso #%d: %d %d\n", tt, res0, res1);
  }
  return 0;
}
