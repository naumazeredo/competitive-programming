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

int main() {
  printf("Case #1:\n");

  int q = 0;
  bitset<33> b;
  b.set(0);
  b.set(31);

  while (!b[32] and q < 500) {
    vi a;

    int ok = 1;
    for (int i = 2; i <= 10 and ok; ++i) {
      int valid = 0;
      for (ll p = 3; p <= 1e5; p+=2) {
        ll num = 0;
        for (int j = 31; j >= 0; j--) num*=i, num+=b[j], num%=p;
        if (num==0) { a.pb(p); valid = 1; break; }
      }
      if (!valid) ok = 0;
    }

    if (ok) {
      for (int i = 31; i >= 0; i--) printf("%d", b.test(i));
      for (int i = 0; i < a.size(); ++i) printf(" %d", a[i]);
      printf("\n");
      q++;
    }


    int x = 1;
    while (1) {
      b.flip(x);
      if (b[x]) break;
      x++;
    }
  }

  return 0;
}
