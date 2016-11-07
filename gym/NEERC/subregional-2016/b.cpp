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

int t, n, l[100], h[100];
char c;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n == 1) { printf("! 1 1\n"), fflush(stdout); continue; }

    for (int i = 1; i <= n; i+=2) {
      l[i] = h[i] = i;
      if (i < n) {
        printf("? %d %d\n", i, i+1); fflush(stdout);
        scanf(" %c", &c);
        if (c == '<') h[i] = i+1;
        if (c == '>') l[i] = i+1;
      }
    }

    int cl = l[1], ch = h[1];
    for (int i = 3; i <= n; i+=2) {
      printf("? %d %d\n", cl, l[i]); fflush(stdout);
      scanf(" %c", &c);
      if (c == '>') cl = l[i];

      printf("? %d %d\n", ch, h[i]); fflush(stdout);
      scanf(" %c", &c);
      if (c == '<') ch = h[i];
    }

    printf("! %d %d\n", cl, ch); fflush(stdout);
  }
  return 0;
}
