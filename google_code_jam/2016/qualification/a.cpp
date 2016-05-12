#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

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

int t, n;

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    printf("Case #%d: ", tt);

    scanf("%d", &n);
    if (n == 0) { printf("INSOMNIA\n"); continue; }

    int i = n;
    int c[10] = {};
    while (1) {
      int t = n;
      while (t) c[t%10]=1, t/=10;

      int v = 0;
      for (int j = 0; j < 10; ++j) v+=c[j];
      if (v==10) break;

      n += i;
    }

    printf("%d\n", n);
  }

  return 0;
}
