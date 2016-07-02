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

char t;
unsigned char c;

int main() {
  for (int i = 0; i < 11; ++i) scanf("%*c");
  while (1) {
    scanf("%c", &t);
    if (t == '_') break;

    c = 0;
    scanf("%*c");
    for (int i = 0; i < 8; ++i) {
      scanf("%c", &t);
      if (t == '.') scanf("%c", &t);
      if (t == 'o') c+=(1<<(7-i));
    }
    scanf("%*c");

    printf("%c", c);
  }
  return 0;
}
