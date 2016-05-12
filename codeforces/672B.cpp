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
const int N = 1e5+5;

int n;
char s[N];

int c[300];

int main() {
  scanf("%d %s", &n, s);
  int d = 0, d0 = 0;
  for (int i = 0; i < n; ++i) d += !!c[s[i]], c[s[i]]=1;
  for (int i = 0; i < 300; ++i) d0 += c[i];

  if (d+d0>26) printf("-1\n");
  else printf("%d\n", d);

  return 0;
}
