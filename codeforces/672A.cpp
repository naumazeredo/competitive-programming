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

int n;
char s[1000];

int main() {
  scanf("%d", &n);
  int d = 0;
  for (int i = 1; i <= 1000; ++i) {
    sprintf(s, "%d", i);
    if (n <= d+strlen(s)) return 0*printf("%c\n", s[n-d-1]);
    d += strlen(s);
  }
  return 0;
}
