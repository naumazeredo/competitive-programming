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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 5e5+5;

int n, a, b, t, o[N], p[N], s[N];
char c;

int main() {
  scanf("%d%d%d%d", &n, &a, &b, &t);
  for (int i = 1; i <= n; ++i) scanf(" %c", &c), o[i]=c=='w';

  p[0] = s[0] = -a;
  for (int i = 1; i <= n; ++i) p[i] = p[i-1]+a+1+(o[i]==1)*b;
  for (int i = 1; i <= n; ++i) s[i] = s[i-1]+a+1+(o[n-i+1]==1)*b;

  int ans = 0;
  for (int i = 1; i <= n and p[i]<=t; ++i) {
    int j = upper_bound(s+1, s+n+1, t-p[i]-i*a)-s-1;
    ans= max(ans, i+j);
  }

  for (int i = 1; i <= n and s[i]+p[1]+a<=t; ++i) {
    int j = upper_bound(p+1, p+n+1, t-s[i]-(i+1)*a)-p-1;
    ans = max(ans, i+j);
  }
  printf("%d\n", min(ans, n));
  return 0;
}
