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

const ld EPS = 1e-6, PI = acos(-1);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

char c;
ll n, x, a, b;

int main() {
  scanf("%lld%lld", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf(" %c%lld", &c, &a);
    if (c == '+') x+=a;
    else {
      if (x >= a) x-=a;
      else b++;
    }
  }

  printf("%lld %lld\n", x, b);
  return 0;
}
