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

int t, b[N], m;
char p[N];

void kmppre() {
  int i = 0, j = -1; b[0] = -1;
  while (i < m) {
    while (j>=0 and p[i] != p[j]) j=b[j];
    i++, j++, b[i]=j;
  }
}

int main() {
  scanf("%d", &t);
  int f = 1;
  while (t--) {
    scanf("%s", p);

    m = strlen(p);
    kmppre();
    int j = m-1;
    while (j>=0 and m%(m-b[j+1])!=0) j=b[j];
    printf("%s%d\n", f?"":"\n", m-b[j+1]);
    f = 0;
  }
  return 0;
}
