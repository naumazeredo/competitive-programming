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

int n, q;

char s[N];
stack<int> a, b;

int main() {
  scanf("%d%d", &n, &q);

  scanf("%s", s);

  for(int i = 0; i < q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a.push(x-1);
    b.push(y-1);
  }

  while(!a.empty()) {
    swap(s[a.top()], s[b.top()]);
    a.pop();
    b.pop();
  }

  printf("%s\n", s);
  return 0;
}
