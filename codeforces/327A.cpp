#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

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

int n;
int a[200];
int p[200];

int main() {
  scanf("%d", &n);
  int t = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), t+=a[i];
  p[1] = a[1];
  for (int i = 2; i <= n; ++i) p[i] = p[i-1]+a[i];

  int m = 0;
  for (int i = 1; i <= n; ++i) for (int j = i; j <= n; ++j)
    m = max(m, j-i+1-p[j]+p[i-1]+p[i-1]+t-p[j]);

  printf("%d\n", m);

  return 0;
}
