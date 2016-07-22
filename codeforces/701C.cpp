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

int n, c[300], t;
char s[N];

int main() {
  scanf("%d %s", &n, s);

  for (int i = 0; s[i]; ++i) if (!c[s[i]]) c[s[i]]++, t++;
  for (int i = 0; i < 300; ++i) c[i]=0;

  int ans = INF, cnt;
  int l = 0, r = 0;
  while (r < n) {
    if (!c[s[r]]) cnt++;
    c[s[r]]++;
    r++;

    while (l < r and c[s[l]]>1) c[s[l]]--, l++;

    if (cnt == t) ans = min(ans, r-l);
  }

  printf("%d\n", ans);

  return 0;
}
