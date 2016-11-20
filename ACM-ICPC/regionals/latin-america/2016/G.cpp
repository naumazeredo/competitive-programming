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
const int N = 5e5+5;

char a[N];
int n, m, x, p[N], s[N], ans, l[300], k;
ll hp, h;

int b[N];

void kmppre() {
  b[0] = -1;
  for (int i = 0, j = -1; i < m; b[++i] = ++j)
    while (j >= 0 and ((j-p[i] >= 0) ? p[i] : -1) != p[j])
      j = b[j];
}

void kmp() {
  for (int i = 0, j = 0; i < n;) {
    while (j >= 0 and (j-s[i] >= 0 ? s[i] : -1) != p[j]) j=b[j];
    i++, j++;
    if (j == m) {
      ans++;
      j = b[j];
    }
  }
}

int main() {
  scanf("%s%d", a, &m);
  n = strlen(a);

  cl(l, -1);
  for (int i = 0; i < n; ++i) {
    x = a[i];
    s[i] = ~l[x] ? i - l[x] : -1;
    l[x] = i;
  }

  cl(l, -1);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &x);
    p[i] = ~l[x] ? i - l[x] : -1;
    l[x] = i;
  }

  kmppre();
  kmp();

  printf("%d\n", ans);

  return 0;
}
