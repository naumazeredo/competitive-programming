#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int n, k, s[N], l, r, v;
char c;

void update(int i, int v) {
  s[i+n] = v ? v/abs(v) : 0;
  for(i+=n; i > 0; i /= 2) s[i/2] = s[i]*s[i^1];
}

char query(int l, int r) {
  int x = 1;
  l += n, r += n;
  while(l < r) {
    if (l&1) x *= s[l++];
    if (r&1) x *= s[--r];
    l /= 2, r /= 2;
  }
  return x > 0 ? '+' : x < 0 ? '-' : '0';
}

int main() {
  while(scanf("%d%d", &n, &k) != EOF) {
    for(int i=0; i<n; ++i) scanf("%d", s+i+n);
    for(int i=n; i<2*n; ++i) if (s[i]) s[i] /= abs(s[i]);

    for(int i=n-1; i>=0; --i) s[i] = s[2*i]*s[2*i+1];
    for(int i=0; i<k; ++i) {
      scanf(" %c%d%d", &c, &l, &r);
      if (c == 'C') update(l-1, r);
      else printf("%c", query(l-1, r));
    }
    printf("\n");
  }
  return 0;
}
