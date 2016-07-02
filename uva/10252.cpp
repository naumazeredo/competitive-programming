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
const int N = 1e5+5;

char a[2][2000], c;
int f[2][300], l;

int main() {
  while (1) {
    fgets(a[0],2000, stdin);
    fgets(a[1],2000, stdin);
    if (feof(stdin)) break;
    a[0][strlen(a[0])-1] = 0;
    a[1][strlen(a[1])-1] = 0;

    cl(f,0);
    for (int i = 0; i < 2; ++i) {
      l = strlen(a[i]);
      for (int j = 0; j < l; ++j) f[i][a[i][j]]++;
    }

    for (int i = 0; i < 300; ++i) f[0][i] = min(f[0][i], f[1][i]);
    for (int i = 0; i < 300; ++i) for (int j = 0; j < f[0][i]; ++j) printf("%c", i);
    printf("\n");
  }
  return 0;
}
