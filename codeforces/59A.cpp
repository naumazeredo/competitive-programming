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

char s[200];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int t = 0;

  for (int i = 0; i < n; ++i) if (islower(s[i])) t++;
  if (2*t >= n) {
    for (int i = 0; i < n; ++i) if (isupper(s[i])) s[i]+='a'-'A';
  } else {
    for (int i = 0; i < n; ++i) if (islower(s[i])) s[i]+='A'-'a';
  }
  printf("%s\n", s);
  return 0;
}
