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
const int N = 3e5+5;

int n, cnt[3];
char s[N];

int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; s[i]; i++) cnt[(int)s[i]-'0']++;

  if (cnt[0] < n/3) { // 1 -> 0, 2 -> 0
    for (int i = 0; s[i] and cnt[0] < n/3; i++) if (cnt[(int)s[i]-'0'] > n/3) {
      cnt[0]++;
      cnt[(int)s[i]-'0']--;
      s[i] = '0';
    }
  }

  if (cnt[2] < n/3) { // 0 -> 2
    for (int i = n-1; i >= 0 and cnt[2] < n/3; i--) if (cnt[(int)s[i]-'0'] > n/3) {
      cnt[2]++;
      cnt[(int)s[i]-'0']--;
      s[i] = '2';
    }
  }

  if (cnt[0] <= n/3) {
    if (cnt[1] < n/3) { // 2 -> 1
      for (int i = 0; s[i] and cnt[1] < n/3; i++) if (cnt[(int)s[i]-'0'] > n/3) {
        cnt[1]++;
        cnt[(int)s[i]-'0']--;
        s[i] = '1';
      }
    }
  } else { //if (cnt[0] > n/3)
    if (cnt[1] < n/3) { // 1 -> 2, 0 -> 2
      for (int i = n-1; i >= 0 and cnt[1] < n/3; i--) if (cnt[(int)s[i]-'0'] > n/3) {
        cnt[1]++;
        cnt[(int)s[i]-'0']--;
        s[i] = '1';
      }
    }
  }

  printf("%s\n", s);

  return 0;
}
