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
const int N = 1e5+5;

char s[N];
int c[300], n;

int main() {
  scanf("%s", s);
  n = strlen(s);

  for (int i = 0; i < n; i++) c[s[i]]++;

  if (!(c['a'] and c['b'] and c['c'] and (c['c'] == c['a'] or c['c'] == c['b'])))
    return printf("NO\n"), 0;

  int i = 0;
  for (; s[i] == 'a' and i < n; i++) ;
  for (; s[i] == 'b' and i < n; i++) ;
  for (; s[i] == 'c' and i < n; i++) ;

  printf("%s\n", i==n ? "YES" : "NO");

  return 0;
}
