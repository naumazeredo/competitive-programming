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
const int N = 1e2+5;

int n, r[N], p[N], d[N], qnt[N];
bitset<N> ans[N*N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &r[i]), p[i] = i;
  if (n == 1) return 0*printf("%d\n0\n", r[0]);

  sort(p,p+n,[](int a, int b){ return r[a] > r[b]; });

  if (r[p[0]] == r[p[n-1]]) return 0*printf("%d\n0\n", r[0]);
  if (n == 2) {
    int ma = max(r[0], r[1]);
    printf("0\n%d\n", ma);
    for (int i = 0; i < ma; ++i) printf("11\n");
    return 0;
  }

  int ma = r[p[0]], mi = r[p[n-1]];
  int s = ma-mi;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < r[i]-mi; ++j)
      ans[j].set(i);

  // > 5
  for (int i = 0; i < s; ++i) if (ans[i].count() > 5) {
    for (int j = 0; j < n and ans[i].count() > 5; ++j) if (ans[i][j]) {
      int k;
      for (k = 0; k < s and (ans[k][j] or ans[k].count()>=5); ++k) ;
      s = max(s, k+1);

      ans[i].reset(j);
      ans[k].set(j);
    }
  }

  // < 2
  for (int i = 0; i < s; ++i) if (ans[i].count() < 2) {
    for (int j = 0; j < n and ans[i].count() < 2; ++j) if (!ans[i][j]) {
      int k;
      for (k = 0; k < s and (!ans[k][j] or ans[k].count()<=2); ++k) ;
      if (k == s) continue;

      ans[i].set(j);
      ans[k].reset(j);
    }
  }

  // possible
  while (mi > 0) {
    int ok = 1;
    for (int i = 0; i < s; ++i) if (ans[i].count() < 2) {
      ok = 0; break;
    }

    if (ok) break;
    else {
      mi--;
      s++;
      for (int j = 0; j < n; ++j) {
        int k;
        for (k = 0; k < s and (ans[k][j] or ans[k].count() >= 5); ++k) ;
        s = max(s, k);
        ans[k].set(j);
      }

      for (int i = 0; i < s; ++i) if (ans[i].count() < 2) {
        for (int j = 0; j < n and ans[i].count() < 2; ++j) if (!ans[i][j]) {
          int k;
          for (k = 0; k < s and (!ans[k][j] or ans[k].count()<=2); ++k) ;
          if (k == s) continue;

          ans[i].set(j);
          ans[k].reset(j);
        }
      }
    }

    /*
    printf("mi: %d\n", mi);
    for (int i = 0; i < s; ++i) {
      for (int j = 0; j < n; ++j) printf("%d", ans[i].test(j));
      printf("\n");
    }
    printf("--------\n");
    */
  }

  if (mi == 0) {
    for (int i = 0; i < s; ++i) if (ans[i].count() < 2) {
      for (int j = 0; j < n and ans[i].count() < 2; ++j) if (!ans[i][j])
        ans[i].set(j);
    }
  }

  printf("%d\n%d\n", mi, s);
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < n; ++j) printf("%d", ans[i].test(j));
    printf("\n");
  }

  return 0;
}
