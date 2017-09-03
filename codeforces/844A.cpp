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

char s[1005];
int k, d[300];

int main() {
  scanf("%s%d", s, &k);
  int t = 0, n = strlen(s);

  for (int i = 0; s[i]; i++) t+=!d[s[i]], d[s[i]]++;
  if (t >= k) return printf("0\n"), 0;
  if (n < k) return printf("impossible\n"), 0;
  int ans = 0;
  for (char i = 'a'; i <= 'z' and t<k; i++) if (!d[i]) ans++, t++;
  printf("%d\n", ans);

  return 0;
}
