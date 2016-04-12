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

int t;
char s[200];
int r[300];
int c[110][110];

int main() {
  for (int i = 0; i < 110; ++i) c[i][0] = 1;
  for (int i = 1; i < 110; ++i) for (int j = 1; j <= i; ++j) c[i][j] = c[i-1][j-1]+c[i-1][j];

  scanf("%d", &t);
  for (int tt = 1; tt <= t; ++tt) {
    memset(r, 0, sizeof(r));

    scanf(" %s", s);
    for (int i = 0; s[i]; ++i) r[s[i]]++;

    int res = 1;
    for (char x = 'a'; x <= 'z'; ++x) {
      int a = r[x], b = r[x-'a'+'A'];
      res *= c[a+b][a];
    }

    printf("Caso #%d: %d\n", tt, res-1);
  }
  return 0;
}
