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
const int N = 1e6+5;

int a[N];
char s[N];

int main() {
  while (gets(s)) {
    if (feof(stdout)) return 0;
    char* p = s;
    int n = 0;
    while (sscanf(p, "%d", &a[n]) == 1)
      strtol(p,&p,10), n++;

    int sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      if (sum < 0) sum = 0;
      ans = max(ans, sum);
    }
    printf("%d\n", ans);
  }
  return 0;
}
