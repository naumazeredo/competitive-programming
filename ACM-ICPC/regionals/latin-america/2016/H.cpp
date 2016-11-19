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

int n, k, p[N], ans;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &p[i]), ans+=p[i];

  priority_queue<int> pq;
  int m = 0;
  for (int i = 0; i < n; ++i) {
    if (m == k) pq.push(-p[i]), m-=k;
    else {
      m++;
      if (pq.size() and -pq.top() < p[i]) pq.pop(), pq.push(-p[i]);
    }
  }

  while (pq.size()) ans += pq.top(), pq.pop();
  printf("%d\n", ans);

  return 0;
}
