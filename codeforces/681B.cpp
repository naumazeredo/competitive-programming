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

ll n, a, b, c;

int main() {
  scanf("%lld", &n);

  for (int a = 0; a <= 1000; ++a) {
    for (int b = 0; b <= 10000; ++b) {
      ll t = n - a*1234567 - b*123456;
      if (t>=0 and t%1234 == 0) {
        return 0*printf("YES\n");
      }
    }
  }

  printf("NO\n");

  return 0;
}
