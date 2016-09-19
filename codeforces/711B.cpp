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
const int N = 1e3+5;

int n, a[N][N], l, c;

int main() {
  scanf("%d", &n);
  if (n == 1) return 0*printf("1\n");

  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    scanf("%d", &a[i][j]);
    if (!a[i][j]) l=i, c=j;
  }

  ll sum = 0;
  for (int j = 0; j < n; ++j) sum += l?a[0][j]:a[1][j];

  int ok = 1;
  ll ans = sum;
  for (int i = 0; i < n; ++i) {
    ll tmp = 0;
    if (i == l) for (int j = 0; j < n; ++j) ans-=a[i][j];
    else {
      for (int j = 0; j < n; ++j) tmp+=a[i][j];
      if (tmp != sum) ok = 0;
    }
  }

  if (ans <= 0) ok = 0;

  for (int j = 0; j < n; ++j) {
    ll tmp = 0;
    for (int i = 0; i < n; ++i) tmp+=a[i][j];
    if (tmp + (j==c?ans:0) != sum) ok = 0;
  }

  ll tmp = 0;
  for (int i = 0; i < n; ++i) tmp+=a[i][i];
  if (tmp + (l==c?ans:0) != sum) ok = 0;

  tmp = 0;
  for (int i = 0; i < n; ++i) tmp+=a[n-i-1][i];
  if (tmp + (n-l-1==c?ans:0) != sum) ok = 0;

  printf("%lld\n", ok?ans:-1);

  return 0;
}
