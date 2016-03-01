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
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int i, j;

ll solve(ll x) {
  if (x == 1) return 1;
  if (x%2 == 1) return solve(3*x+1)+1;
  return solve(x/2)+1;
}

int main() {
  while (scanf("%d%d", &i, &j) != EOF) {
    int x = min(i, j), y = max(i, j);
    ll m = 0;
    for (int a = x; a <= y; ++a) m = max(m, solve(a));
    printf("%d %d %lld\n", i, j, m);
  }
  return 0;
}
