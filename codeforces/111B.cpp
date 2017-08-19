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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, x, y, l[N];

vector<int> divs(int a) {
  vector<int> v;
  int i;
  for (i = 1; i*i < a; i++) if (a%i==0) v.pb(i), v.pb(a/i);
  if (i*i == a) v.pb(i);
  sort(v.begin(), v.end());
  return v;
}

int main() {
  cl(l, -1);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    auto v = divs(x);
    int ans = 0;
    for (int d : v) {
      if (l[d] < i-y) ans++;
      l[d] = i;
    }
    printf("%d\n", ans);
  }
  return 0;
}
