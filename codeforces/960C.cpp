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

int x, d, ok;
vector<ll> ans;
ll last;

void solv() {
  int lo = 1, hi = 60;
  while (lo < hi) {
    int md = (lo+hi+1)/2;
    if (((1ll<<md)-1) <= x) lo = md;
    else hi = md - 1;
  }

  x -= (1ll<<lo)-1;
  for (int i = 0; i < lo; i++) ans.push_back(last+d);
  last = last+d+lo-1;

  if (ans.size() > 1e4) ok = 0;
}

int main() {
  scanf("%d%d", &x, &d);
  ok = 1;
  while (x and ok) solv();

  if (!ok) return printf("-1\n"), 0;

  printf("%d\n", (int)ans.size());
  for (ll v : ans) printf("%lld ", v);
  printf("\n");
  return 0;
}
