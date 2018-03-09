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
const int N = 2e5+5;

char s[N];
set<int> a[2];

int main() {
  scanf("%s", s);
  for (int i = 0; s[i]; i++)
    a[s[i]-'0'].insert(i+1);

  int k = a[0].size() - a[1].size();

  vector<vector<int>> ans;
  db(1);

  int cnt;
  for (cnt = 0; cnt < k and a[0].size(); cnt++) {
    vector<int> res;

    res.push_back(*a[0].begin());
    int l = *a[0].begin();

    if (a[1].lower_bound(l) != a[1].end()) {
      auto it = a[1].lower_bound(l);
      res.push_back(*it);
      a[1].erase(it);
      a[0].erase(l);
    } else break;

    ans.push_back(res);
  }
  db(2);

  for (auto& v : ans) {
    if (a[0].empty()) break;

    auto it = a[0].lower_bound(v.back());
    if (it == a[0].end()) continue;
    v.push_back(*it);
    int l = *it;
    a[0].erase(it);

    int t = 1;
    while (a[t].lower_bound(l) != a[t].end()) {
      auto it = a[t].lower_bound(l);
      v.push_back(*it);
      l = *it;
      a[t].erase(it);
      t^=1;
    }

    if (t == 0) return printf("-1\n"), 0;
  }
  db(3);

  for (; cnt < k and a[0].size(); cnt++) {
    vector<int> res;

    res.push_back(*a[0].begin());
    int l = *a[0].begin();
    a[0].erase(a[0].begin());

    ans.push_back(res);
  }
  db(4);

  if (cnt != k) return printf("-1\n"), 0;
  if (a[0].size() or a[1].size()) return printf("-1\n"), 0;

  db(5);

  printf("%d\n", (int)ans.size());
  for (auto& v : ans) {
    printf("%d ", (int)v.size());
    for (int x : v) printf("%d ", x);
    printf("\n");
  }

  return 0;
}
