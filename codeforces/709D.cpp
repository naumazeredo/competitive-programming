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
const int N = 1e6;

int a[4], p[N];

int main() {
  for (int i = 0; i < 4; ++i) scanf("%d", &a[i]);

  if (a[0]+a[1]+a[2]+a[3]==0) return 0*printf("0\n");

  ll n[2] = {1, 1};
  while (n[0]*(n[0]-1) < 2*a[0]) n[0]++;
  while (n[1]*(n[1]-1) < 2*a[3]) n[1]++;

  if (a[1]+a[2] == 0) {
    if (a[0] and !a[3] and n[0]*(n[0]-1)==2*a[0] and n[0] <= N) {
      for (int i = 0; i < n[0]; ++i) printf("0");
      printf("\n");
      return 0;
    }

    if (a[3] and !a[0] and n[1]*(n[1]-1)==2*a[3] and n[1] <= N) {
      for (int i = 0; i < n[1]; ++i) printf("1");
      printf("\n");
      return 0;
    }

    printf("Impossible\n");
    return 0;
  }

  if (n[0]*(n[0]-1) != 2*a[0] or n[1]*(n[1]-1) != 2*a[3] or n[0]+n[1]>N or a[1]+a[2]!=n[0]*n[1]) {
    printf("Impossible\n");
    return 0;
  }

  int t = 0;
  int c = n[1];
  for (int i = 0; i < n[0]; ++i) {
    if (a[1]-t < c) {
      int d = a[1]-t;
      for (int j = 0; j < c-d; ++j) printf("1");
      c = d;
    }
    t += c;
    printf("0");
  }

  int d = a[1]-t;
  for (int j = 0; j < c-d; ++j) printf("1");
  c = d;

  printf("\n");

  return 0;
}
