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

int n, s[N], t[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
  sort(s,s+n);
  for (int i = 0; i < n; ++i) t[i&1?n-1-i/2:i/2] = s[n-1-i];

  ll ans = t[n-1]*t[0];
  for (int i = 0; i < n-1; ++i) ans += t[i]*t[i+1];

  printf("%.3f\n", (double)(ans * sin(2*PI/n) / 2));

  return 0;
}
