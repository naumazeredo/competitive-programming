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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int noden;
int nodev[55];
int node[55][2];

int n, k, x;
set<string> s;
string st;

void add(int u, int v) {
  if (!nodev[u]) {
    nodev[u] = v;
    return;
  }

  if (v < nodev[u]) {
    if (!node[u][0]) node[u][0] = ++noden;
    add(node[u][0], v);
  } else {
    if (!node[u][1]) node[u][1] = ++noden;
    add(node[u][1], v);
  }
}

void prefix(int u) {
  st += '1';
  if (!node[u][0]) st+='0';
  else prefix(node[u][0]);
  if (!node[u][1]) st+='0';
  else prefix(node[u][1]);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    noden = 0;
    cl(nodev, 0);
    cl(node, 0);

    for (int j = 0; j < k; ++j) scanf("%d", &x), add(0, x);
    st.clear();
    prefix(0);

    s.insert(st);
  }

  printf("%d\n", (int)s.size());

  return 0;
}
