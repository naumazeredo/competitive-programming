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
const int N = 1e2+5;

int n, a[2*N], p[N][2], m[2*N];
int bit[2*N];

void add(int p, int v) {
  for (p+=2; p<2*N; p+=p&-p) bit[p] += v;
}

int sum(int p) {
  int r = 0;
  for (p+=2; p; p-=p&-p) r += bit[p];
  return r;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2*n; i++) {
    scanf("%d", &a[i]);
    p[a[i]][m[a[i]]] = i;
    m[a[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    add(p[i][0], 1);
    add(p[i][1], 1);
    m[i] = 0;
  }

  ll ans = 0;
  for (int i = 1; i <= 2*n; i++) if (!m[i] and p[a[i]][1]-p[a[i]][0] > 1) {
    //db(i _ p[a[i]][0] _ p[a[i]][1] _ sum(p[a[i]][1]-1) _ sum(i));
    ans += sum(p[a[i]][1]-1) - sum(i);
    add(p[a[i]][1], -1);
    m[p[a[i]][1]] = 1;
  }

  printf("%lld\n", ans);

  return 0;
}
