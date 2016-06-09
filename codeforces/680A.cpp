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

int t[10], b, r[200];

int main() {
  for (int i = 0; i < 5; ++i) scanf("%d", &t[i]), b+=t[i], r[t[i]]++;
  int ans = b;
  for (int i = 0; i < 5; ++i) if (r[t[i]]>1)
    ans=min(ans, b-min(r[t[i]],3)*t[i]);
  printf("%d\n", ans);

  return 0;
}
