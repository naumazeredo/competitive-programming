#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))

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

int n, x;

int main() {
  scanf("%d", &n);
  int s = 0, m=0;
  for (int i = 0; i < n; ++i) scanf("%d", &x), s+=x, m = max(m, x);
  s -= m;
  printf("%d\n", m - s + 1);
  return 0;
}
