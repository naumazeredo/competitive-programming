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
const int N = 1e4+5;

int t, n;
char cs[20];
string s[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", cs), s[i] = cs;
    sort(s, s+n);

    int ok = 1;
    for (int i = 0; i < n; ++i) {
      int len = s[i].length();
      int l, r;

      int lo = 0, hi = n;
      while (lo < hi) {
        int mid = (lo+hi)/2;
        if (s[mid].substr(0, len) < s[i]) lo = mid+1;
        else hi = mid;
      }
      l = lo;

      lo = 0, hi = n;
      while (lo < hi) {
        int mid = (lo+hi)/2;
        if (s[mid].substr(0, len) <= s[i]) lo = mid+1;
        else hi = mid;
      }
      r = lo;

      if (r-l>1) { ok = 0; break; }
    }

    printf("%s\n", ok?"YES":"NO");
  }
  return 0;
}
