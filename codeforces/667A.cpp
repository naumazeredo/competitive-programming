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

ll d, h, v, e;

int main() {
  scanf("%lld%lld%lld%lld", &d, &h, &v, &e);

  double vh = 4*v/(d*d*3.141592);

  if (vh > e) {
    printf("YES\n%f\n", h / (vh - e));
  } else
    printf("NO\n");

  return 0;
}
