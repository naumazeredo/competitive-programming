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

int n, q, l, r;
char s[20];

int main() {
  scanf("%d", &n);
  unordered_map<string, set<int>> h;
  for (int i = 0; i < n; ++i) {
    scanf(" %s", s);
    for (int j = 0; s[j]; ++j)
      for (int k = j; s[k]; ++k)
        h[string (&s[j], k-j+1)].insert(i);
  }

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d %s", &l, &r, s);
    printf("%d\n", (int)distance(h[s].lower_bound(l-1), h[s].upper_bound(r-1)));
  }
  return 0;
}
