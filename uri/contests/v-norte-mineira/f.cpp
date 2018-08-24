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
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, k, t, l, r;
int dead[N];
set<piii> s;
set<pii> v[N];

void solv(int l, int r, int t) {
  auto it = s.lower_bound({ { l, INF }, INF });
  if (it != s.begin()) it--;

  vector<piii> rem, add;

  for (; it != s.end(); it++) {
    if (it->st.nd < l) continue;
    if (it->st.st > r) break;

    rem.push_back(*it);
    v[it->nd].erase({ it->st.st, it->st.nd });

    if (it->st.st < l) {
      pii x { it->st.st, l-1 };
      add.push_back({ x, it->nd });
      v[it->nd].insert(x);
    }

    if (it->st.nd > r) {
      pii x { r+1, it->st.nd };
      add.push_back({ x, it->nd });
      v[it->nd].insert(x);
    }
  }

  for (auto& x : rem) s.erase(x);
  for (auto& x : add) s.insert(x);

  s.insert({ { l, r }, t });
  v[t].insert({ l, r });
}

void kill(int t) {
  if (t < 0) return;
  if (v[t].empty()) return;

  for (auto x : v[t]) {
    dead[x.st]++;
    dead[x.nd+1]--;
  }
}

int main() {
  while (~scanf("%d%d%d", &n, &k, &t)) {
    if (t > k) {
      for (int i = 1; i <= n; i++) printf("%d ", i);
      printf("\n");
      continue;
    }

    memset(dead, 0, sizeof dead);
    s.clear();
    for (int i = 0; i <= k; i++) v[i].clear();

    solv(1, n, 0);

    for (int i = 1; i <= k; i++) {
      kill(i-t-1);
      scanf("%d%d", &l, &r);
      solv(l, r, i);
    }
    kill(k-t);

    int tot = 0;
    for (int i = 1; i <= n; i++) dead[i] += dead[i-1], tot += !dead[i];
    printf("%d", tot);
    for (int i = 1; i <= n; i++) if (!dead[i]) printf(" %d", i);
    printf("\n");
  }
  return 0;
}
