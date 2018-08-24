// @subject: 
// @diff: 

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

int n, x, v[N];
ll p, t, c;

int main() {
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]), t += v[i];
  sort(v+1,v+n+1, greater<int>());

  int k;
  for (k = 1; k <= n; k++) {
    c += x;
    p += v[k];
    if (c >= t) break;
  }

  multiset<int> l, lb;
  multiset<pll> t, b, o;
  for (int i = 1; i <= k; i++) t.insert({ x - v[i], 0 });
  for (int i = k+1; i <= n; i++) l.insert(v[i]);

  while (l.size() or lb.size()) {
    if (l.empty()) while (lb.size()) l.insert(*lb.begin()), lb.erase(lb.begin());

    int k = *l.begin();
    pll x = *t.rbegin();

    db(k _ x.first _ x.second);

    l.erase(l.begin());
    t.erase(t.find(x));

    if (x.first > k) {
      b.insert({ x.first - k, x.second + k });
    } else {
      o.insert({ 0, x.second + x.first });

      if (k - x.first)
        lb.insert(k - x.first);
    }

    if (t.empty()) while (b.size()) t.insert(*b.begin()), b.erase(b.begin());
  }

  while (b.size()) o.insert(*b.begin()), b.erase(b.begin());
  ll ans = 0;
  for (auto x : o) ans = max(ans, x.second);
  printf("%d %lld\n", k, ans);

  return 0;
}
