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

int n, m, a, b, c;
map<int, int> lis[N];
int ans;

void add() {
  auto ita = lis[a].lower_bound(c);
  auto itb = lis[b].upper_bound(c);

  int v;

  if (ita == lis[a].begin()) {
    v = 1;
  } else {
    ita--;
    v = ita->nd + 1;
  }

  if (itb == lis[b].begin()) {
    lis[b][c] = v;
  } else {
    itb--;
    lis[b][c] = max(itb->nd, v);
  }

  itb = lis[b].find(c);
  int last = itb->nd;
  for (itb++; itb != lis[b].end() and itb->nd <= last;) {
    auto it = itb; it++;
    lis[b].erase(itb);
    itb = it;
  }

  ans = max(ans, lis[b][c]);
}

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d%d", &a, &b, &c);
    add();
  }

  printf("%d\n", ans);

  return 0;
}
