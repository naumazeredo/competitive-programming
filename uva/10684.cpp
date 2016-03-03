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
int a[20000];

int main() {
  while (~scanf("%d", &n) and n) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int msf = 0, m = 0;
    for (int i = 0; i < n; ++i) {
      m = max(0, m+a[i]);
      msf = max(m, msf);
    }

    if (msf) printf("The maximum winning streak is %d.\n", msf);
    else printf("Losing streak.\n");
  }

  return 0;
}
