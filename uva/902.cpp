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
const int N = 1e6+5;

int n;
char s[N];
map<string, int> m;

int main() {
  while (~scanf("%d %s", &n, s)) {
    m.clear();
    int l = strlen(s);

    int ma = 0;
    string ans;
    for (int i = 0; i < l-n+1; ++i) {
      string t (s+i, n);
      m[t]++;
      if (m[t] > ma) ma = m[t], ans = t;
    }

    printf("%s\n", ans.c_str());
  }

  return 0;
}
