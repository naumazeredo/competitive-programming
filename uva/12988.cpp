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

int t, a[20], s[20];
char c;

int solve(int x) {
  if (x == 16) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) printf("%d", s[i*4+j]);
      printf("\n");
    }
    return 1;
  }

  if (a[x]) return solve(x+1);

  int l = x/4, c = x%4;
  int bl = l/2, bc = c/2, il = l%2, ic = c%2;
  for (int i = 1; i <= 4; ++i) {
    s[x] = i;

    int ok = 1;
    for (int j = 0; j < 4; ++j) {
      if (l*4+j != x and s[l*4+j] == s[x]) ok = 0;
      if (j*4+c != x and s[j*4+c] == s[x]) ok = 0;
      int jl = bl*2+(j/2), jc = bc*2+(j%2);
      if (jl*4+jc != x and s[jl*4+jc] == s[x]) ok = 0;
    }

    if (ok and solve(x+1)) return 1;
    s[x] = 0;
  }

  return 0;
}

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    printf("Case #%d:\n", tt);

    for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
      scanf(" %c", &c);
      if (c == '*') a[i*4+j]=s[i*4+j]=0;
      else a[i*4+j]=s[i*4+j]=c-'0';
    }

    solve(0);
  }
  return 0;
}
