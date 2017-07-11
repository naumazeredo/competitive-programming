#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n, a, b, k;
int p[N], r[N];
map<int, int> bit[N];

void add(int p, int x) {
  for (p+=2; p < N; p+=p&-p) bit[p][x] += 1;
}

int query(int p, int x) {
  int sum = 0;
  for (p+=2; p; p-=p&-p) sum += bit[p][x];
  return sum;
}

int main() {
  for (ll i = 2; i < N; i++) if (!p[i])
    for (ll j = 2*i; j < N; j+=i) p[j] += i;
  for (ll i = 2; i < N; i++) r[i] = 1+r[p[i]], add(i, r[i]);

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a, &b, &k);
    printf("%d\n", query(b, k) - query(a-1, k));
  }

  return 0;
}
