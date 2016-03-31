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
int a[222222];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a+n);

  vi res;
  int l = 0;
  for (int i = 1; i <= 1e9; ++i) {
    if (a[l] == i) { l++; continue; }
    if (m >= i) m-=i, res.pb(i);
    else break;
  }

  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); ++i) printf("%d ", res[i]);
  printf("\n");

  return 0;
}
