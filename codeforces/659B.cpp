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

int n, m;
char name[222222][20];
vector<pii> r[22222];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x, s;
    scanf(" %s%d%d", name[i], &x, &s);
    r[x].pb(mp(-s,i));
  }

  for (int i = 1; i <= m; ++i) sort(r[i].begin(), r[i].end());
  for (int i = 1; i <= m; ++i) {
    if (r[i].size() > 2 and r[i][1].st == r[i][2].st) printf("?\n");
    else printf("%s %s\n", name[r[i][0].nd], name[r[i][1].nd]);
  }

  return 0;
}
