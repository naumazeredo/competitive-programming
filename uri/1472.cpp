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

int n, d, x;

int main() {
  while (~scanf("%d", &n)) {
    vi a;
    d = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &x), a.pb(d+x), d+=x;
    for (int i = 1; i < n; ++i) a.pb(a[i]+d);

    if (d%3 != 0) printf("0\n");
    else {
      int res = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] >= a[0]+d/3) break;
        if (binary_search(a.begin(), a.end(), a[i]+d/3) and binary_search(a.begin(), a.end(), a[i]+2*d/3))
          res++;
      }
      printf("%d\n", res);
    }
  }
  return 0;
}
