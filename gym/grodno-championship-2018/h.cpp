// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
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

int t;
ll l, k;
char s[100];

string solve1(ll sz, ll k) {
  if (sz == 1) return k ? "1" : "0";

  ll op = (sz+6)%8+1;
  ll last = 1ll<<(sz-1);
  ll right = (k >= last);
  if (right) k -= last;

  switch (op) {
    case 1: return solve1(sz-1, k) + "01"[right];
    case 2: return "01"[right] + solve1(sz-1, k);
    case 3: return solve1(sz-1, k) + "10"[right];
    case 4: return "10"[right] + solve1(sz-1, k);
    case 5: return solve1(sz-1, right ? last-1-k : k) + "01"[right];
    case 6: return "01"[right] + solve1(sz-1, right ? last-1-k : k);
    case 7: return solve1(sz-1, right ? last-1-k : k) + "10"[right];
    case 8: return "10"[right] + solve1(sz-1, right ? last-1-k : k);
  }
  assert(0);
}

ll solve2(int l, int r) {
  if (l == r) return s[l] == '0' ? 0 : 1;

  ll sz = r-l+1;
  ll op = (sz+6)%8+1;
  ll last = 1ll<<(sz-1);

  ll right = 0;
  switch (op) {
    case 1: right = (s[r] == '1'); break;
    case 2: right = (s[l] == '1'); break;
    case 3: right = (s[r] == '0'); break;
    case 4: right = (s[l] == '0'); break;
    case 5: right = (s[r] == '1'); break;
    case 6: right = (s[l] == '1'); break;
    case 7: right = (s[r] == '0'); break;
    case 8: right = (s[l] == '0'); break;
  }

  switch (op) {
    case 1: return right * last + solve2(l, r-1);
    case 2: return right * last + solve2(l+1, r);
    case 3: return right * last + solve2(l, r-1);
    case 4: return right * last + solve2(l+1, r);
    case 5: return right * (2*last-1) + (right ? -1 : 1) * solve2(l, r-1);
    case 6: return right * (2*last-1) + (right ? -1 : 1) * solve2(l+1, r);
    case 7: return right * (2*last-1) + (right ? -1 : 1) * solve2(l, r-1);
    case 8: return right * (2*last-1) + (right ? -1 : 1) * solve2(l+1, r);
  }

  assert(0);
}

int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    char c;
    scanf(" %c", &c);

    if (c == 'H') {
      scanf("%lld%lld", &l, &k);
      printf("%s\n", solve1(l, k-1).c_str());
    } else {
      scanf("%s", s);
      printf("%lld\n", solve2(0, strlen(s)-1)+1);
    }
  }
  return 0;
}
