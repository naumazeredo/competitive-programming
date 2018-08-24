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

const int N = 2e7+5;

int v[N], t2[N], t5[N];
int inv[10], p2[10];
int n, m;

int main() {
  inv[1] = 1;
  inv[3] = 7;
  inv[7] = 3;
  inv[9] = 9;
  p2[0] = 1;
  p2[1] = 2;
  p2[2] = 4;
  p2[3] = 8;
  p2[4] = 6;

  v[0] = 1;
  for (int i = 1; i < N; i++) {
    v[i] = i * v[i-1];
    t2[i] = t2[i-1];
    t5[i] = t5[i-1];
    while (v[i] % 2 == 0) v[i] /= 2, t2[i]++;
    while (v[i] % 5 == 0) v[i] /= 5, t5[i]++;
    v[i] %= 10;
  }

  while (~scanf("%d%d", &n, &m)) {
    m = n-m;
    int c2 = (t2[n]-t2[m]) - (t5[n]-t5[m]);
    int ans = 1;

    if (c2 < 0) c2 = 0, ans = 5;
    if (c2) c2 = (c2-1)%4+1;

    ans *= v[n] * inv[v[m]] * p2[c2];
    ans %= 10;
    printf("%d\n", ans);
  }
  return 0;
}
