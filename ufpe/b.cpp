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

int t, n, m, k;
int p[2222222];
int q[2222222];

int main() {
  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &q[i]);

    sort(p, p+n);
    int val = 0;
    for (int i = 0; i < k; ++i) val += p[i];

    int res = INF;
    int acc = 0;
    int i = 0;
    for (int j = 0; j < m; ++j) {
      acc += q[j];
      while (acc - q[i] >= val) acc-=q[i++];
      if (acc >= val) res = min(res, j-i+1);
    }

    printf("Caso #%d: %d\n", tt, res<=m?res:-1);
  }
  return 0;
}
