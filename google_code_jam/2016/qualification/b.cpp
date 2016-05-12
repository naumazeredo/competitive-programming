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
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

int t;
char s[200];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    scanf(" %s", s);

    int res = 0;
    for (int i = 1; s[i]; ++i) {
      if (s[i] == s[0]) continue;
      s[0] = s[0]=='+'?'-':'+';
      res++;
    }

    if (s[0] == '-') res++;
    printf("Case #%d: %d\n", tt, res);
  }
  return 0;
}
