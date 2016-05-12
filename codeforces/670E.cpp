#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 5e5+5;

int n, m, p;
char s[N];
int nex[N], pre[N];
int par[N];

int main() {
  scanf("%d%d%d", &n, &m, &p);
  scanf(" %s", &s[1]);

  stack<int> st;
  for (int i = 1; s[i]; ++i) {
    nex[i] = i+1;
    pre[i] = i-1;
    if (s[i] == '(') st.push(i);
    else {
      int u = st.top(); st.pop();
      par[i] = u;
      par[u] = i;
    }
  }

  for (int i = 0; i < m; ++i) {
    char c;
    scanf(" %c", &c);

    if (c == 'R') p = nex[p];
    if (c == 'L') p = pre[p];
    if (c == 'D') {
      p = min(p, par[p]);
      nex[pre[p]] = nex[par[p]];
      pre[nex[par[p]]] = pre[p];

      p = nex[par[p]];
      if (p > n) p = pre[p];
    }
  }

  while (pre[p]) p = pre[p];

  while (p <= n) printf("%c", s[p]), p = nex[p];
  printf("\n");

  return 0;
}
