#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e7;
const int mod = 1e9+7;

int n, m;
char s[200005];
map<iii, ll> d;
ll cat[3000];

ll calc(int t, int a, int v) {
  printf("calc %d %d %d\n", t, a, v);

  if (a < 0) return 0;
  if (abs(a-v)%2 != t%2) return 0;
  if (abs(a-v) > t) return 0;

  if (a == v) return cat[t];

  if (d.find(iii(t, ii(a, v))) != d.end()) return d[iii(t,ii(a,v))];
  ll res = (calc(t-1, a+1, v) + calc(t-1, a-1, v)) % mod;
  d[iii(t,ii(a,v))] = res;

  printf("%d %d %d: %lld\n", t, a, v, res);

  return res;
}

int main() {
  cat[0] = cat[1] = 1;
  for (int i = 2; i <= 3000; ++i) for (int j = 0; j < i; ++j) cat[i] += cat[j]*cat[i-j-1];

  scanf("%d%d %s", &n, &m, s);

  if (n%2) { printf("0\n"); return 0; }

  int mn=0, mp=0;
  int t = 0;
  for (int i = 0; i < m; ++i) t += s[i]=='('?1:-1, mn = min(mn, t), mp = max(mp, t);

  //printf("mn %d mp %d\n", mn, mp);
  if (mp > n/2 or -mn > n/2) { printf("0\n"); return 0; }

  ll res = 0;
  for (int i = -mn; i <= n-m; ++i) for (int v = -mn; v <= min(n/2-mp, i); ++v)
    if (i>=abs(v) and n-m-i>=abs(t+v))
      res = (res + (calc(i, 0, v)*calc(n-m-i, t+v, 0)) % mod) % mod;

  printf("%lld\n", res);

  return 0;
}
