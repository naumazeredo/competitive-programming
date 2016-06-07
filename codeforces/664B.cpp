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

int a, b, n;
vector<char> order;

int main() {
  a++;
  while (1) {
    char c;
    scanf("%c ", &c);
    if (c == '+') a++;
    if (c == '-') b++;
    if (c == '=') break;
    if (c != '?') order.pb(c);
  }

  scanf("%d", &n);

  if (a*n-b<n or a-n*b>n) return 0*printf("Impossible\n");

  printf("Possible\n");

  int ans = a*n-b-n;
  vi v[2];
  for (int i = 0; i < a; ++i) v[0].pb(n);
  for (int i = 0; i < b; ++i) v[1].pb(1);

  for (int i = 0; i < b and ans; ++i) {
    if (ans < n) v[1][i]+=ans, ans = 0;
    else ans -= n-v[1][i], v[1][i]=n;
  }
  for (int i = 0; i < a and ans; ++i) {
    if (ans < n) v[0][i]-=ans, ans = 0;
    else ans -= v[0][i]-1, v[0][i]=1;
  }

  int x = 1, y = 0;
  printf("%d", v[0][0]);
  for (int i = 0; i < order.size(); ++i) {
    if (order[i]=='+') printf(" + %d", v[0][x++]);
    else printf(" - %d", v[1][y++]);
  }
  printf(" = %d\n", n);

  return 0;
}
