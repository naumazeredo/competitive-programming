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

int n, p[N];

int main() {
  for (ll i = 2; i*i < N; ++i) if (!p[i])
    for (ll j = i*i; j < N; j+=i) p[j] = 1;

  scanf("%d", &n);

  for (int i = 1; i <= 1e3; ++i) if (p[n*i+1]) return 0*printf("%d\n", i);
  return 0;
}
