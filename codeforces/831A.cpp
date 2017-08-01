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
const int N = 1e2+5;

int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int s = 0, ok = 1;
  for (int i = 1; i < n; i++) {
    if (s == 0 and a[i] == a[i-1]) s = 1;
    else if (s == 0 and a[i] < a[i-1]) s = 2;
    else if (s == 1 and a[i] < a[i-1]) s = 2;
    else if (s == 1 and a[i] > a[i-1]) { ok = 0; break; }
    else if (s == 2 and a[i] >= a[i-1]) { ok = 0; break; }
  }
  printf("%s\n", ok?"YES":"NO");
  return 0;
}
