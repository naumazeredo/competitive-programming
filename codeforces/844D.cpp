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

int n, s, x, t[N], val[N], nex[N];
int best, bestv;

int main() {
  scanf("%d%d%d", &n, &s, &x);
  vi v;
  for (int i = 1; i <= n; i++) v.pb(i);

  srand(time(0));
  random_shuffle(v.begin(), v.end());

  int a = 1;
  printf("? %d\n", s);
  fflush(stdout);
  scanf("%d%d", &val[s], &nex[s]); t[s] = 1; t[nex[s]] = 1;

  if (val[s] >= x) {
    printf("! %d\n", val[s]);
    fflush(stdout);
    return 0;
  }

  int p = 0;
  best = s, bestv = val[s];
  while (x - bestv > 2000-a and a < 1900) {
    while (t[v[p]]) p++;
    if (p >= n) break;

    int cur = v[p];

    printf("? %d\n", cur);
    fflush(stdout);
    scanf("%d%d", &val[cur], &nex[cur]); t[cur] = 1; t[nex[cur]] = 1;

    if (val[cur] <= x and val[cur] > bestv) {
      if (nex[cur] == -1) {
        printf("! -1\n");
        fflush(stdout);
        return 0;
      }
      best = cur, bestv = val[cur];
    }
    a++;
  }

  while (bestv < x and a < 1999 and nex[best] != -1) {
    best = nex[best];
    printf("? %d\n", best);
    fflush(stdout);
    scanf("%d%d", &bestv, &nex[best]);
    a++;
  }

  if (bestv < x) printf("! -1\n");
  else printf("! %d\n", bestv);
  fflush(stdout);
  return 0;

  return 0;
}
