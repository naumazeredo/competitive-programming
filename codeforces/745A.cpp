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

char s[100];
set<string> se;

int main() {
  scanf("%s", s);
  int n = strlen(s);

  for (int i = 0; i < n; ++i) {
    string st;
    for (int j = i; j < n; ++j) st.pb(s[j]);
    for (int j = 0; j < i; ++j) st.pb(s[j]);
    se.insert(st);
  }

  printf("%d\n", (int)se.size());
  return 0;
}
