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

struct pt {
  ll x, y;
  pt() : x(0), y(0) {}
  pt(ll x, ll y) : x(x), y(y) {}
  pt operator+(pt p) { return pt(x+p.x, y+p.y); }
  pt operator-(pt p) { return pt(x-p.x, y-p.y); }
  ll operator*(pt p) { return x*p.x + y*p.y; }
  ll operator%(pt p) { return x*p.y - y*p.x; }
};

int n, m[N];
pt p[N];

bool coll(int a, int b, int c) {
  return !((p[b]-p[a])%(p[c]-p[a]));
}

bool test(int a, int b) {
  memset(m, 0, sizeof m);

  m[a] = 1; m[b] = 1;
  for (int i = 0; i < n; i++)
    if (i != a and i != b and coll(a, b, i))
      m[i] = 1;

  vector<int> c;
  for (int i = 0; i < n and c.size() < 2; i++) if (!m[i]) {
    m[i] = 1;
    c.push_back(i);
  }

  if (c.size() < 2) return 1;

  for (int i = 0; i < n; i++) if (!m[i]) {
    if (!coll(c[0], c[1], i)) return 0;
    m[i] = 1;
  }

  for (int i = 0; i < n; i++) if (!m[i]) return 0;

  return 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);

  if (n <= 2) return printf("YES\n"), 0;

  int k = 2;
  while (k < n and coll(0, 1, k)) k++;

  if (k == n) return printf("YES\n"), 0;
  printf("%s\n", test(0, 1) or test(0, k) or test(1, k) ? "YES" : "NO");

  return 0;
}
