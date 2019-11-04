// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
const int N = 2e5+5;

int n, h[N], m[N];
vector<int> adj[N];
queue<set<int>> v;

int main() {
  scanf("%d", &n);
  for (int a, b, i = 0; i < n-1; i++) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  set<int> s;
  s.insert(1);
  v.push(s);
  m[1] = 1;

  for (int a, i = 0; i < n; i++) {
    scanf("%d", &a);

    if (!v.front().count(a)) return !printf("No\n");
    v.front().erase(a);
    if (v.front().empty()) v.pop();

    s.clear();
    for (int v : adj[a]) if (!m[v]) m[v] = 1, s.insert(v);
    if (s.size()) v.push(s);
  }

  printf("Yes\n");
  return 0;
}
