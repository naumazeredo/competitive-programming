#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e3+5;

char s[N];
int d[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);

  for (int i = 1; i <= n; i++) d[i] += d[i-1] + (s[i-1]!='a');

  int ans = 0;
  int l = n;
  for (int i = 0; i <= n; i++) {
    if (i and s[i-1] != 'a') l--;

    int l2 = l;
    for (int j = i; j <= n; j++) {
      if (j != i and s[j-1] != 'b') l2--;
      ans = max(ans, l2 - (d[n] - d[j]));
    }
  }

  printf("%d\n", ans);

  return 0;
}
