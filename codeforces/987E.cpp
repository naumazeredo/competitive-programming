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
const int N = 1e6+5;

int n, a[N], p[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    p[a[i]] = i;
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) if (p[i] != i) {
    int t = p[i];
    swap(a[i], a[p[i]]);
    p[a[t]] = t;

    /*
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    */

    cnt++;
  }
  //db(cnt);

  if ((3*n - cnt) % 2 == 0) printf("Petr\n");
  else printf("Um_nik\n");

  return 0;
}
