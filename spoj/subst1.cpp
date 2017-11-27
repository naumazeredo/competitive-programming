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
  #define db(x)
  #define dbs(x)
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

// Suffix Array O(nlogn)
char s[N];
int n, r, ra[N], sa[N], tra[N], tsa[N], c[N]; // n = strlen(s)

void count(int k) {
  int sum = 0, x = max(300, n); cl(c, 0);
  for (int i = 0; i < n; ++i) c[i+k<n ? ra[i+k] : 0]++;
  for (int i = 0; i < x; ++i) sum += c[i], c[i] = sum-c[i];
  for (int i = 0; i < n; ++i) tsa[c[sa[i]+k<n ? ra[sa[i]+k] : 0]++] = sa[i];
  for (int i = 0; i < n; ++i) sa[i] = tsa[i];
}

void suffixarray() {
  for (int i = 0; i < n; ++i) ra[i] = s[i], sa[i] = i;
  for (int k = 1; k < n; k <<= 1) {
    count(k); count(0);
    tra[sa[0]] = r = 0;
    for (int i = 1; i < n; ++i)
      tra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] and ra[sa[i]+k] == ra[sa[i-1]+k]) ? r : ++r;
    for (int i = 0; i < n; ++i) ra[i] = tra[i];
    if (ra[sa[n-1]] == n-1) break;
  }
}

// Longest Common Prefix with SA O(n)
int phi[N], plcp[N], lcp[N];
void calcLCP() {
  int l = 0;
  phi[sa[0]] = -1; plcp[sa[0]] = 0;
  for (int i = 1; i < n; ++i) phi[sa[i]] = sa[i-1];
  for (int i = 0; i < n; ++i) {
    if (phi[i] == -1) continue;
    while (s[i+l] == s[phi[i]+l]) l++;
    plcp[i] = l;
    l = max(l-1, 0);
  }
  for (int i = 0; i < n; ++i) lcp[i] = plcp[sa[i]];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    strcat(s, "$");
    n = strlen(s);
    suffixarray();
    calcLCP();

    ll ans = 0;
    for (int i = 0; i < n; i++)
      ans += n-sa[i]-lcp[i]-1;
    printf("%lld\n", ans);
  }
  return 0;
}
