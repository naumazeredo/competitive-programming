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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int p[200];
char s[10];

int main() {
  for (int i = 2; i <= 100; ++i) if (!p[i])
    for (int j = i*i; j <= 100; j+=i) p[j]=1;

  int pf=101;
  int r = 0;
  int tot = 100;
  for (int i = 2; i <= min(tot,71); ++i) if (!p[i]) {
    printf("%d\n", i); fflush(stdout);
    scanf(" %s", s); r += s[0]=='y';
    if (r>1) break;
    if (s[0]=='y') tot/=i, pf = i;
  }

  if (r==1) for (int i = pf*pf; i <= 100; i*=pf) {
    printf("%d\n", i); fflush(stdout);
    scanf(" %s", s); r += s[0]=='y';
    if (r>1) break;
  }

  if (r<=1) printf("prime\n");
  else printf("composite\n");
  fflush(stdout);
  return 0;
}
