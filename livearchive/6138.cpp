#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

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
const int N = 1e7+5;

int v[200];
int x;

int main() {
  for (int i = 0; i < 720; ++i) {
    int m = (i%60);
    int h = i/12;
    int ma = max(h, m), mi = min(h, m);
    v[min(ma-mi, 360+mi-ma)*6] = 1;
  }

  while (~scanf("%d", &x))
    printf("%c\n", v[x]?'Y':'N');

  return 0;
}
