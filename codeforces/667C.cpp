#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

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

char s[11111];

set<string> res;
int v[11111][5];

void go(int a, int b, string x) {
  if (v[a][b]) return;

  if (a < 5) return;
  string y (&s[a], b);
  if (x == y) return;

  res.insert(y);
  v[a][b] = 1;
  go(a-2, 2, y);
  go(a-3, 3, y);
}

int main() {
  scanf("%s", s);
  int len = strlen(s);
  db(len);

  go(len-2, 2, "");
  go(len-3, 3, "");

  printf("%d\n", (int)res.size());
  for (set<string>::iterator it = res.begin(); it != res.end(); it++)
    printf("%s\n", it->c_str());

  return 0;
}
