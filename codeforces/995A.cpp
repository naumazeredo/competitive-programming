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
const int N = 55;

int n, k, f;
int g[4][N];
vector<piii> ans;

void print() {
  printf("\n");
  for (int i = 1; i <= 2; i++) {
    for (int j = 0; j < n; j++) printf("%d ", g[i][j]);
    printf("\n");
  }
  printf("\n");
}

void tryfit() {
  for (int i = 0; i < n; i++) {
    if (g[1][i] and g[1][i] == g[0][i]) {
      ans.push_back({ g[1][i], { 1, i+1 } });
      g[1][i] = 0;
      k--;
    }
  }

  for (int i = 0; i < n; i++) {
    if (g[2][i] and g[2][i] == g[3][i]) {
      ans.push_back({ g[2][i], { 4, i+1 } });
      g[2][i] = 0;
      k--;
    }
  }
}

void rot() {
  int r = -1, c = 0;
  for (int i = 1; i <= 2; i++)
    for (int j = 0; j < n; j++)
      if (!g[i][j]) r = i, c = j;

  if (r == -1) { f = 1; return; }

  for (int i = 0; i < 2*n-1; i++) {
    int lr = r, lc = c;

    c += (r==1)?1:-1;
    if (c > n-1) c = n-1, r = 2;
    if (c < 0) c = 0, r = 1;

    if (g[r][c]) {
      ans.push_back({ g[r][c], { lr+1, lc+1 } });
      swap(g[r][c], g[lr][lc]);
    }
    //printf("-- %d %d %d\n", ans.back().st, ans.back().nd.st, ans.back().nd.nd);
    //print();
  }
}

void solv() {
  tryfit();
  while (k and ans.size() <= 20000 and !f) {
    //db(k _ ans.size());
    rot();
    tryfit();
  }

  if (ans.size() > 20000) f = 1;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &g[i][j]);

  solv();

  if (!f) {
    printf("%d\n", (int)ans.size());
    for (auto x : ans) printf("%d %d %d\n", x.st, x.nd.st, x.nd.nd);
  } else {
    printf("-1\n");
  }
  return 0;
}
