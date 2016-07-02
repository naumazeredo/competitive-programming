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

int n, x, y, z;
char s[100];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    x = y = z = 0;
    scanf("%s", s);

    int ok = 1;
    int j = 0;
    for (; s[j] and s[j] != 'M' and ok; ++j)
      if (s[j] == '?') x++; else ok = 0;

    if (s[j++] != 'M') ok = 0;

    for (; s[j] and s[j] != 'E' and ok; ++j)
      if (s[j] == '?') y++; else ok = 0;

    if (s[j++] != 'E') ok = 0;

    for (; s[j] and ok; ++j)
      if (s[j] == '?') z++; else ok = 0;

    if (!ok or !x or !y or z-y != x) printf("no-theorem\n");
    else printf("theorem\n");
  }
  return 0;
}
