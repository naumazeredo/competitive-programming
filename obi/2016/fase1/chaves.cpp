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

int n, t;
char s[200];

int main() {
  scanf("%d%*c", &n);
  for (int i = 0; i < n; ++i) {
    fgets(s, 100, stdin);
    for (int j = 0; s[j]; ++j) {
      if (s[j] == '{') t++;
      if (s[j] == '}') t--;
    }
    if (t < 0) break;
  }

  printf("%c\n", t?'N':'S');
  return 0;
}
