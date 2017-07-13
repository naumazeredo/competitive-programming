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
const int N = 1e5+5;

int q, t, x, l, r, m[300];
char s[N], e[20], c;

int bit[4][12][12][N];

void addi(char c, int t, int p, int v) {
  c = m[c];
  int x = p%t;
  for (p+=2; p < N; p+=p&-p) bit[c][t][x][p] += v;
}

void add(char c, int p) {
  for (int i = 1; i <= 10; i++) addi(s[p], i, p, -1);
  for (int i = 1; i <= 10; i++) addi(c, i, p, +1);
  s[p] = c;
}

int query(char c, int t, int p) {
  c = m[c];
  int x = p%t;
  int sum = 0;
  for (p+=2; p>0; p-=p&-p) sum += bit[c][t][x][p];
  return sum;
}

int main() {
  m['A'] = 0; m['T'] = 1; m['G'] = 2; m['C'] = 3;
  scanf("%s%d", s, &q);
  for (int i = 0; s[i]; i++) for (int j = 1; j <= 10; j++) addi(s[i], j, i, +1);

  for (int i = 0; i < q; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %c", &x, &c); x--;
      add(c, x);
    } else {
      scanf("%d%d %s", &l, &r, e); l--; r--;
      int ans = 0;
      int len = strlen(e);
      int dx = (r-l+1)/len*len+l;
      for (int j = 0; e[j]; j++) {
        ans += query(e[j], len, (dx+j>r?dx+j-len:dx+j));
        ans -= query(e[j], len, l+j-len);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
