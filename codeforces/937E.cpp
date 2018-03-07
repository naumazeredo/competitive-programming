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
const int N = 2e3+5;

int n;
char s[N], t[N], tmp[N];
vector<int> ans;

void apply(int x) {
  ans.push_back(x);
  for (int i = 0; i < n; i++) tmp[i] = s[i];
  for (int i = 0; i < x; i++) s[i] = tmp[n-i-1];
  for (int i = x; i < n; i++) s[i] = tmp[i-x];
}

int main() {
  scanf("%d%s%s", &n, s, t);

  int m = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[j] == t[i]) {
        apply(n-j-1);
        apply(1);
        apply(n);
        m--;
        break;
      }
      if (j == m-1) return printf("-1\n"), 0;
    }
  }

  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x);
  printf("\n");

  return 0;
}
