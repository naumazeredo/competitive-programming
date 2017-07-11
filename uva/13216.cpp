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

int t, n;
char s[N];

int main() {
  scanf("%d ", &t);
  while (t--) {
    fgets(s, N, stdin);
    int l = strlen(s)-1;
    if (l == 1) {
      int ans = 1;
      int m = s[0]-'0';
      for (int i = 0; i < m; i++)
        ans = (ans*66)%100;
      printf("%d\n", ans);
      continue;
    }

    n = (s[l-1]-'0'+3)%5;
    int ans = 56;
    for (int i = 0; i < n; i++)
      ans = (ans*66)%100;
    printf("%d\n", ans);
  }
  return 0;
}
