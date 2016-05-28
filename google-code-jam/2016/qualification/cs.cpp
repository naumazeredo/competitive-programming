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
  ll v = (1ll<<15)+1;
  while (v < (1ll<<16) and q < 50) {
    bitset<16> b(v);

    vi a;

    int ok = 1;
    for (int i = 2; i <= 10 and ok; ++i) {
      ll num = 0;
      for (int j = 15; j >= 0; --j) num*=i, num+=b[j];

      int valid = 0;
      for (ll p = 3; p*p <= num; p+=2) if (num%p==0) { a.pb(p); valid = 1; break; }
      if (!valid) ok = 0;
    }

    if (ok) {
      printf("%s", b.to_string().c_str());
      for (int i = 0; i < a.size(); ++i) printf(" %d", a[i]);
      printf("\n");
      q++;
    }

    v+=2;
  }

  return 0;
}
