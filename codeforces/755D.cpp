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
const int N = 1e6+5;

int n, k;
int bit[N], v[N];

void add(int p) { for (p+=2; p < N; p+=p&-p) bit[p]++; }
ll sum(int p) {
  ll r = 0;
  for (p+=2; p; p-=p&-p) r+=bit[p];
  return r;
}

int main() {
  scanf("%d%d", &n, &k);
  k = min(k, n-k);

  ll c = 1;
  int p = 0;
  while (!v[p]) {
    v[p] = 1;
    ll nv = 1;

    if (p + k >= n) {
      nv += sum(n) - sum(p);
      nv += sum((p+k)%n-1);
    } else {
      nv += sum(p+k-1) - sum(p);
    }

    c += nv;
    printf("%lld ", c);

    add(p);
    p = (p+k)%n;
    add(p);
  }
  printf("\n");

  return 0;
}
