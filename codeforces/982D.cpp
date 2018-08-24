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
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
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

int n, a[N], l[N], r[N], sz[N];
set<pii> s;
map<int, int> m;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s.insert({ a[i], i });
  }

  int k = 0, tot = 0;

  for (auto x : s) {
    int p = x.first;
    int v = x.second;

    l[v] = r[v] = v;
    sz[v] = 1;

    if (l[v-1]) {
      l[v] = l[v-1];

      m[sz[v-1]]--;
      if (m[sz[v-1]] == 0) m.erase(sz[v-1]);
    }

    if (r[v+1]) {
      r[v] = r[v+1];

      m[sz[v+1]]--;
      if (m[sz[v+1]] == 0) m.erase(sz[v+1]);
    }

    r[l[v]] = r[v];
    l[r[v]] = l[v];

    sz[l[v]] = sz[r[v]] = r[v] - l[v] + 1;
    m[sz[l[v]]]++;

    if (m.size() == 1) {
      if (m.begin()->nd > tot) {
        tot = m.begin()->nd;
        k = p;
      }
    }
  }

  printf("%d\n", k+1);

  return 0;
}
