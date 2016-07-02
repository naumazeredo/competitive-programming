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
const int N = 1e5+5;

int n, m;
char t[100], c;
unsigned char s[100];

int main() {
  scanf("%d", &n);
  while (n--) {
    cl(s,0);

    scanf(" %s", t);
    m = strlen(t)-2;

    for (int i = 0; i < 8; ++i) {
      scanf(" %s", t);
      for (int j = 0; j < m; ++j) {
        s[j]>>=1;
        if (t[j+1] == '\\') s[j]|=(1<<7);
      }
    }
    scanf(" %s", t);

    printf("%s\n", s);
  }

  return 0;
}
