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

int n, x;
char s[100];
vector<string> vs; vi vx;
priority_queue<int> pq;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" %s%d", s, &x);
    if (s[0] == 'i') pq.push(-x);
    if (s[0] == 'r') {
      if (pq.empty()) vs.pb("insert"), vx.pb(1), pq.push(1);
      pq.pop();
    }
    if (s[0] == 'g') {
      while (!pq.empty() and -pq.top() < x) vs.pb("removeMin"), vx.pb(0), pq.pop();
      if (pq.empty() or -pq.top() > x) vs.pb("insert"), vx.pb(x), pq.push(-x);
    }
    vs.pb(s); vx.pb(x);
  }

  printf("%d\n", (int)vs.size());
  for (int i = 0; i < vs.size(); ++i) {
    string a = vs[i];
    if (a[0] == 'r') printf("%s\n", a.c_str());
    else printf("%s %d\n", a.c_str(), vx[i]);
  }

  return 0;
}
