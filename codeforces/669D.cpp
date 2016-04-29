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

int n, q, t, x;
int p[1111111];

int main() {
  scanf("%d%d", &n, &q);

  ll dp = 0, di = 0;
  for (int i = 0; i < q; ++i) {
    scanf("%d", &t);
    if (t == 1) scanf("%d", &x), dp+=x, di+=x;
    else {
      if (di%2==0) di++, dp--;
      else di--, dp++;
    }
  }

  dp = (n + dp%n)%n;
  di = (n + di%n)%n;

  for (int i = 1; i <= n; ++i)
    p[i%2?(i+di-1)%n+1:(i+dp-1)%n+1] = i;

  for (int i = 1; i <= n; ++i) printf("%d ", p[i]);
  printf("\n");

  return 0;
}
