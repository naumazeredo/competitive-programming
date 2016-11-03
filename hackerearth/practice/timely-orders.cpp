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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int q, c, t, x;
map<ll, ll> bit;

void add(int p, int v) { for (p+=2; p < INF; p+=p&-p) bit[p]+=v; }
ll query(int p) {
  ll sum = 0;
  for (p+=2; p; p-=p&-p) sum+=bit[p];
  return sum;
}

int main() {
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d", &c, &x, &t);
    if (c == 1) add(t, x);
    else {
      printf("%lld\n", query(t) - query(t-x-1));
    }
  }
  return 0;
}
