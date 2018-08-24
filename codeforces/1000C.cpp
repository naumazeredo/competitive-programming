// @subject: line sweep (sparse)
// @diff: 1

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int n;
ll l, r;
map<ll, int> m;
ll ans[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &l, &r);
    m[l]++;
    m[r+1]--;
  }

  ll l = 0, k = 0;
  for (auto x : m) {
    ll p = x.st;
    int c = x.nd;

    ans[k] += p-l;
    k += c;

    l = p;
  }

  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  printf("\n");


  return 0;
}
