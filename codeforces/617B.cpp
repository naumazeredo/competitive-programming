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

int main() {
  scanf("%d", &n);
  int c = 0;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), c+=a[i];
  if (!c) return 0*printf("0\n");

  int p = 0;
  while (!a[p++]);

  ll t = 1;
  int x = 1;
  for (; p < n; ++p) {
    if (a[p]) t*=x, x=1;
    else x++;
  }

  printf("%lld\n", t);

  return 0;
}
