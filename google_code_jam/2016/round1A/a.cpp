#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))

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

int t, tt;
char s[2000];

int main() {
  scanf("%d", &t);
  while (tt++ < t) {
    scanf(" %s", s);
    char ns[2001];
    int b = 1000, e = 1000;
    ns[b] = s[0];
    for (int i = 1; s[i]; ++i) {
      if (s[i] < ns[b]) ns[++e] = s[i];
      else ns[--b] = s[i];
    }

    printf("Case #%d: ", tt);
    for (int i = b; i <= e; ++i) printf("%c", ns[i]);
    printf("\n");
  }
  return 0;
}
