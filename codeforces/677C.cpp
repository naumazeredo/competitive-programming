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

int n, ans, cnt;
char s[N];

ll fexp(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b&1) res=(res*a)%MOD;
    b>>=1;
    a = (a*a)%MOD;
  }
  return res;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    int r;
    char c = s[i];
    if (c >= '0' and c <= '9') r = c-'0';
    if (c >= 'A' and c <= 'Z') r = c-'A'+10;
    if (c >= 'a' and c <= 'z') r = c-'a'+36;
    if (c == '-') r = 62;
    if (c == '_') r = 63;

    cnt += 6-(bitset<6>(r)).count();
  }

  printf("%lld\n", fexp(3, cnt));

  return 0;
}
