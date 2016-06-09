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
const int N = 1e5+5;

char s[5];

int main() {
  ll lo = 1, hi = 1000000;
  while (lo < hi) {
    ll mid = (lo+hi+1)>>1;
    printf("%lld\n", mid);
    fflush(stdout);
    scanf(" %s", s);
    if (s[0] == '<') hi = mid-1;
    else lo = mid;
  }

  printf("! %lld\n", lo);

  return 0;
}
