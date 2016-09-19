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

int n;
char s[N][10];

int main() {
  scanf("%d", &n);
  int ok = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    if (!ok and s[i][0] == 'O' and s[i][1] == 'O') ok = 1, s[i][0] = s[i][1] = '+';
    if (!ok and s[i][3] == 'O' and s[i][4] == 'O') ok = 1, s[i][3] = s[i][4] = '+';
  }

  if (ok) {
    printf("YES\n");
    for (int i = 0; i < n; ++i) printf("%s\n", s[i]);
  } else printf("NO\n");

  return 0;
}
