// @subject: 
// @diff: 

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
const int N = 3e5+5;

int n;
char s[N];
map<int, ll> cl, op;
ll ans;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);

    int t = 0, a = 0;
    for (int j = 0; s[j]; j++) {
      if (s[j] == '(') t++;
      if (s[j] == ')') {
        if (t) t--;
        else a++;
      }
    }

    if (t and !a) op[t]++;
    if (!t and a) cl[a]++;
    if (!t and !a) ans++;
  }

  ans = ans*ans;
  for (auto x : op)
    ans += x.nd * cl[x.st];
  printf("%lld\n", ans);

  return 0;
}
