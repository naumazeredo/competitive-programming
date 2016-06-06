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

int a[4];

int main() {
  for (int i = 0; i < 4; ++i) scanf("%d", &a[i]);
  a[0] -= a[2];
  a[1] -= a[3];
  if (!a[0] and !a[1]) printf("0\n");
  else if (a[0] and a[1]) printf("1\n");
  else printf("2\n");
  return 0;
}
