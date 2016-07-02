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
const int N = 1e6+5;

int n, k, c[N], p[N], pf[N], t[N];

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }

int main() {
  for (ll i = 2; i <= N; ++i) if (!p[i]) {
    p[i] = i;
    for (ll j = i*i; j <= N; j+=i)
      p[j] = i;
  }

  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  sort(c,c+n);

  for (int i = 0; i < n; ++i) {
    if (c[i] == c[i+1]) continue;
    map<int, int> m;
    while (c[i] != 1) {
      m[p[c[i]]]++;
      pf[p[c[i]]] = max(pf[p[c[i]]], m[p[c[i]]]);
      c[i] /= p[c[i]];
    }
  }

  cl(t, 0);
  int cp = k;
  while (cp != 1) {
    t[p[cp]]++;
    cp /= p[cp];
  }

  int ok = 1;
  for (int i = 2; i <= k; ++i) if (t[i] and t[i] > pf[i]) ok=0;

  printf("%s\n", ok?"Yes":"No");

  return 0;
}
