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
const int N = 4e3+5;

int a, p[N];
ll ans;
char s[N];
map<int, ll> m;

int main() {
  scanf("%d%s", &a, s);
  ll n = strlen(s);
  for (int i = 0; s[i]; i++) p[i+1] = p[i]+(s[i]-'0');
  for (int i = 1; i <= n; i++) for (int j = 0; j < i; j++) m[p[i]-p[j]]++;
  if (a == 0) ans = m[0]*(n+1)*n - m[0]*m[0];
  int i = 1;
  for (i = 1; i*i < a; i++) if(a%i==0) ans += 2*m[i]*m[a/i];
  if (i*i == a) ans += m[i]*m[i];
  printf("%lld\n", ans);
  return 0;
}
