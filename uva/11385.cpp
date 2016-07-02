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
const int N = 1e3+5;

int t, n, a[N];
ll f[50];
char s[1000], ans[1000];

int main() {
  f[0] = f[1] = 1;
  for (int i = 2; i < 50; ++i) f[i] = f[i-2]+f[i-1];

  scanf("%d", &t);
  while (t--) {
    cl(s,0);
    cl(ans,' ');

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d ", &a[i]);

    int i = 0;
    while (~scanf("%c", &s[i]) and s[i] != '\n') if (s[i] >= 'A' and s[i] <= 'Z') i++;

    int l = 0;
    for (int i = 0; i < n; ++i) {
      int j = 1;
      while (f[j] != a[i])j++;
      l = max(l, j);
      ans[j-1] = s[i];
    }
    ans[l] = 0;
    printf("%s\n", ans);
  }
  return 0;
}
