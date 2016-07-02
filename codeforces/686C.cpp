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

const ld EPS = 1e-6, PI = acos(-1);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n[2], d[2], t, ans;
int main() {
  scanf("%d%d", &n[0], &n[1]);
  for (int i = 0; i < 2; ++i) {
    t = n[i]-1;
    while (t) d[i]++, t/=7;
  }
  d[0] = max(1, d[0]);
  d[1] = max(1, d[1]);
  if (d[0] + d[1] > 7) return 0*printf("0\n");

  vi v;
  for (int i = 0; i < 7; ++i) v.pb(i);

  set<vi> s;
  do {
    int a = 0;
    for (int i = 0; i < d[0]; ++i) a=a*7+v[i];
    if (a >= n[0]) continue;

    a = 0;
    for (int i = 0; i < d[1]; ++i) a=a*7+v[i+d[0]];
    if (a >= n[1]) continue;

    vi x;
    for (int i = 0; i < d[0]+d[1]; ++i) x.pb(v[i]);
    if (s.count(x)) continue;
    s.insert(x);
    ans++;
  } while (next_permutation(v.begin(), v.end()));

  printf("%d\n", ans);

  return 0;
}
