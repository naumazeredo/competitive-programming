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
const int N = 1e5+5;

int n;
char t[N];
string s[N];
pll p[N];
ll ans;

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", t);
    s[i] = t;

    for (int j = 0; t[j]; j++) {
      if (t[j] == 's') p[i].first++;
      else p[i].second++, ans += p[i].first;
    }
  }

  sort(p, p+n,
       [](pll a, pll b){
         return b.second * a.first > a.second * b.first;
       });

  ll ss = 0;
  for (int i = 0; i < n; i++) {
    ans += p[i].second*ss;
    ss += p[i].first;
  }

  printf("%lld\n", ans);

  return 0;
}
