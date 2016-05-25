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

int n, k;
char s[N];

int main() {
  scanf("%d%d %s", &n, &k, s);
  for (int i = 0; s[i]; ++i) s[i]-='a';

  int ans = 0;
  int l = 0, r = 0, c = 0;
  while (r < n) {
    if (!s[r]) {
      if (c==k) {
        while (s[l]) l++;
        l++;
        c--;
      }
      c++;
    }
    r++;
    ans = max(ans, r-l);
  }

  l = 0, r = 0, c = 0;
  while (r < n) {
    if (s[r]) {
      if (c==k) {
        while (!s[l]) l++;
        l++;
        c--;
      }
      c++;
    }
    r++;
    ans = max(ans, r-l);
  }

  printf("%d\n", ans);

  return 0;
}
