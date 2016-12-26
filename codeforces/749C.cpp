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
const int N = 2e5+5;

int n, x[N], t[2], v[2];
char p[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf(" %c", &p[i]);
    if (p[i]=='D') v[1]++;
    else v[0]++;
  }

  int u = 1;
  while (v[0] and v[1]) {
    if (x[u]) { u = u%n+1; continue; }

    if (p[u] == 'D') {
      if (t[0]) {
        t[0]--;
        v[1]--;
        x[u]=1;
      } else t[1]++;
    } else {
      if (t[1]) {
        t[1]--;
        v[0]--;
        x[u]=1;
      } else t[0]++;
    }

    u = u%n+1;
  }

  printf("%c\n", p[u]);

  return 0;
}
