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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int n, a[N];
int p[N], h[N];
map<int, int> s;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a+i);

  h[0] = 1, p[0] = -1;
  s[a[0]] = 0;
  for (int i = 1; i < n; ++i) {
    s[a[i]] = i;

    auto lb = s.lower_bound(a[i]);
    if (lb != s.begin()) {
      lb--;
      p[i] = lb->nd;
    }

    lb = s.lower_bound(a[i]);
    lb++;
    if (lb != s.end() and h[p[i]] < h[lb->nd]) p[i] = lb->nd;

    h[i] = h[p[i]]+1;
  }

  for (int i = 1; i < n; ++i) printf("%d ", a[p[i]]);
  printf("\n");
  return 0;
}
