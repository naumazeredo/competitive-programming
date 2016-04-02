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

int l, c;
int a[500][500];
int lo[500], co[500];

int main() {
  while (~scanf("%d%d", &l, &c)) {
    for (int i = 0; i < l; ++i) for (int j = 0; j < c; ++j) scanf("%d", &a[i][j]), a[i][j]--;

    int ok = 1;
    for (int i = 0; i < l and ok; ++i) {
      int r = a[i][0]/c;
      for (int j = 1; j < c and ok; ++j) {
        if (a[i][j]/c != r) {
          printf("*\n"); ok = 0;
        }
      }
    }

    for (int i = 0; i < c and ok; ++i) {
      int r = a[0][i]%c;
      for (int j = 1; j < l and ok; ++j) {
        if (a[j][i] % c != r) {
          printf("*\n"); ok = 0;
        }
      }
    }

    if (!ok) continue;

    for (int i = 0; i < l; ++i) lo[i] = a[i][0]/c;
    for (int i = 0; i < c; ++i) co[i] = a[0][i]%c;

    int res = 0;
    for (int i = 0; i < l; ++i) while (lo[i] != i) swap(lo[i], lo[lo[i]]), res++;
    for (int i = 0; i < c; ++i) while (co[i] != i) swap(co[i], co[co[i]]), res++;

    printf("%d\n", res);
  }
  return 0;
}
