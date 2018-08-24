// @subject: 
// @diff: 

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int a, b;
vector<int> da, db;

void gd(int x, vector<int>& d) {
  while (x) {
    d.push_back(x%10);
    x /= 10;
  }
  reverse(d.begin(), d.end());
}

int solv() {
  if (da.size() > db.size()) return -1;

  sort(da.begin(), da.end());

  int ans = -1;
  do {
    if (da[0] == 0) continue;

    int tmp = 0;
    for (int i = 0; i < (int)da.size(); i++) tmp = tmp*10 + da[i];

    db(tmp);

    if (tmp <= b) ans = max(ans, tmp);
  } while (next_permutation(da.begin(), da.end()));

  return ans;
}

int main() {
  scanf("%d%d", &a, &b);

  gd(a, da);
  gd(b, db);

  printf("%d\n", solv());

  return 0;
}
