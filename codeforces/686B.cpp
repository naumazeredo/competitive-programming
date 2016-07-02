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

const ld EPS = 1e-6, PI = acos(-1);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  while (1) {
    int l = 0;
    while (l < n and a[l] <= a[l+1]) l++;
    if (l >= n-1) break;

    int r = l+1;
    while (r+2 < n and a[r+1] > a[r+2]) r+=2;
    //if (r == l+1) break;
    printf("%d %d\n", l+1, r+1);

    for (int i = l; i < r; i+=2) swap(a[i], a[i+1]);
  }
  return 0;
}
