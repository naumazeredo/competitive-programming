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

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }

int n, a[30];
int odd, g;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), odd+=a[i]%2, g = i?gcd(g,a[i]):a[i];

  if (odd > 1) {
    printf("0\n");
    for (int i = 0; i < n; ++i) for (int j = 0; j < a[i]; ++j) printf("%c", i+'a');
    printf("\n");
    return 0;
  }

  printf("%d\n", g);
  string s[2];

  for (int i = 0; i < n; ++i) for (int j = 0; j < a[i]/g/2; ++j) s[0]+=i+'a';
  for (int i = 0; i < n; ++i) if ((a[i]/g)&1) s[0]+=i+'a';
  for (int i = n-1; i >= 0; --i) for (int j = 0; j < a[i]/g/2; ++j) s[0]+=i+'a';

  for (int i = s[0].size()-1; i >= 0; --i) s[1]+=s[0][i];
  for (int i = 0; i < g; ++i) printf("%s", s[i%2].c_str());
  printf("\n");
  return 0;
}
