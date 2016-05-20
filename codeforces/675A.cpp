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

int a, b, c;

int main() {
  scanf("%d%d%d", &a, &b, &c);
  if (c==0) printf("%s\n", a==b?"YES":"NO");
  else printf("%s\n", (b-a)%c?"NO":((b-a)/c<0?"NO":"YES"));
  return 0;
}
