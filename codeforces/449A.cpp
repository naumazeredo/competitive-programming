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

char s[N];

int main() {
  scanf("%s", s);

  int n = 0, c = 0, l = 0;
  for (int i = 0; s[i]; ++i) {
    if (s[i] == '#') n++, l = c-1;

    if (s[i] == '(') c++;
    else c--;

    if (c < 0) return 0*printf("-1\n");
  }

  int ans = c, j = 0;
  c=0;
  for (int i = 0; s[i]; ++i) {
    if (s[i] == '#') {
      j++;
      c -= j==n?ans:0;
    }

    if (s[i] == '(') c++;
    else c--;

    if (c < 0) return 0*printf("-1\n");
  }

  for (int i = 0; i < n-1; ++i) printf("1\n");
  printf("%d\n", ans+1);

  return 0;
}
