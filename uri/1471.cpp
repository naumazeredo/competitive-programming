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

int n, r, x;
int a[22222];

int main() {
  while (~scanf("%d%d", &n, &r)) {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < r; ++i) scanf("%d", &x), a[x] = 1;
    vi res;
    for (int i = 1; i <= n; ++i) if (!a[i]) res.pb(i);

    if (!res.size()) printf("*");
    else for (int i = 0;  i < res.size(); ++i) printf("%d ", res[i]);
    printf("\n");
  }
  return 0;
}
