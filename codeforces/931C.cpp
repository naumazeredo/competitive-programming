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

int n, x[N], m, q[3];
int v[3], ans, t;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);

  sort(x,x+n);
  m = x[0];

  for (int i = 0; i < n; i++) x[i] -= m, q[x[i]]++;
  for (int i = 0; i < 3; i++) v[i] = q[i];
  ans = n;

  if (v[2]) {
    while (v[2] and v[0]) v[1]+=2, v[2]--, v[0]--;
    t = min(q[0],v[0])+min(q[1],v[1])+min(q[2],v[2]);
    ans = min(t, ans);

    while (v[1] >= 2) {
      v[1] -= 2, v[0]++, v[2]++;
      t = min(q[0],v[0])+min(q[1],v[1])+min(q[2],v[2]);
      ans = min(ans, t);
    }

    while (ans != t and v[2] and v[0]) {
      v[1]+=2, v[2]--, v[0]--;
      t = min(q[0],v[0])+min(q[1],v[1])+min(q[2],v[2]);
      if (ans == t) break;
    }
  }

  printf("%d\n", ans);
  for (int i = 0; i < 3; i++)
    for (; v[i]; v[i]--)
      printf("%d ", i+m);
  printf("\n");

  return 0;
}
