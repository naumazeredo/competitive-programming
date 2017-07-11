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

int n, c[300];
char s[300];

int main() {
  scanf("%d%*c", &n);
  for (int i = 0; i < n; ++i) {
    cl(c,0);
    gets(s);
    for (int j = 0; s[j]; ++j) {
      if (s[j] >= 'a' and s[j] <= 'z') c[s[j]]++;
      if (s[j] >= 'A' and s[j] <= 'Z') c[s[j]-'A'+'a']++;
    }

    int f = 0;
    set<char> sc;
    for (char i = 'a'; i <= 'z'; ++i) {
      if (c[i] < f) continue;
      if (c[i] > f) f = c[i], sc.clear();
      sc.insert(i);
    }

    for (char x : sc) printf("%c", x);
    printf("\n");
  }
  return 0;
}
