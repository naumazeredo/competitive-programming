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

int n, m;
char s[N], t[N];
int ansr[N], ansl[N];
vector<int> p[30];

bool solv(int pos) {
  int c = s[pos]-'a';
  if (p[c].empty()) return 0;

  int lo = 0, hi = p[c].size()-1;
  while (lo < hi) {
    int mid = (lo+hi)/2;
    int mp = p[c][mid];

    bool l = mp == 0 or ansl[mp-1] < pos;
    bool r = mp == m-1 or ansr[mp+1] > pos;

    if (!l and !r) return 0;
    if (l and r) return 1;

    if (!l) hi = mid;
    else lo = mid+1;
  }

  int mp = p[c][lo];
  bool l = mp == 0 or ansl[mp-1] < pos;
  bool r = mp == m-1 or ansr[mp+1] > pos;
  return l and r;
}

int main() {
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);

  for (int i = 0; i < m; i++) p[t[i]-'a'].push_back(i);
  for (int i = 0; i < m; i++) ansl[i] = INF, ansr[i] = -INF;

  int pm;
  pm = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == t[pm]) ansl[pm++] = i;

  pm = m-1;
  for (int i = n-1; i >= 0; i--)
    if (s[i] == t[pm]) ansr[pm--] = i;

  for (int i = 0; i < n; i++) if (!solv(i)) {
    return printf("No\n"), 0;
  }

  printf("Yes\n");
  return 0;
}
