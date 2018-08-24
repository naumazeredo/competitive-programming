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
const int N = 6e5+5;

int n, l[N], r[N], o[N];
int bit[N];

void add(int p, int v) {
  for (p+=2; p < N; p+=p&-p) bit[p] = max(bit[p], v);
}

int query(int p) {
  int sum = 0;
  for (p+=2; p; p-=p&-p) sum = max(sum, bit[p]);
  return sum;
}

int main() {
  vector<int> v;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &l[i], &r[i]), o[i] = i, v.push_back(l[i]), v.push_back(r[i]);
  sort(o,o+n, [](int a, int b){ return l[a]==l[b] ? r[a] < r[b] : l[a] > l[b]; });

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int last = -1;
  for (int i = 0; i < n; i++) {
    int x = o[i];

    int rr = lower_bound(v.begin(), v.end(), r[x]) - v.begin();

    int q = query(rr);
    if (q) return printf("%d %d\n", q, x+1), 0;

    add(rr, x+1);
  }

  printf("-1 -1\n");
  return 0;
}
