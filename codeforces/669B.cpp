#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))

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

int n, x;
int d[111111];
int v[111111];
char c;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf(" %c", &c), d[i] = c=='>'?1:-1;
  for (int i = 0; i < n; ++i) scanf("%d", &x), d[i] *= x;

  int p = 0;
  int ok = 1;
  while (d[p]+p>=0 && d[p]+p<n) {
    if (v[p]) { ok = 0; break; }
    v[p] = 1;
    p += d[p];
  }

  printf("%s\n", ok?"FINITE" : "INFINITE");

  return 0;
}
