#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int a, b;
char s[10000];

int main() {
  while (scanf("%d%d %s", &a, &b, s) != EOF) {
    int l = strlen(s);
    int x = 0;
    for (int i = 0; i < l; ++i) x+=s[i]=='B';

    ll res = 0;
    int u = x-1, v = x;
    while (u >= 0 and v < l) {
      while (s[u]=='B' and u >= 0) u--;
      while (s[v]=='W' and v < l)  v++;
      if (u < 0 or v >= l) break;

      res += min(1ll*a, 1ll*(v-u)*(a-b));
      swap(s[u], s[v]);
    }
    printf("%lld\n", res);
  }
  return 0;
}
