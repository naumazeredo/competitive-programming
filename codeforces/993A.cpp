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

int x[8], y[8];
ld xx[2], yy[2];

int dot(int a, int b, int i) {
  int dx0 = x[b]-x[a];
  int dy0 = y[b]-y[a];

  int dx1 = x[i]-x[a];
  int dy1 = y[i]-y[a];

  int d = dx0*dy1 - dy0*dx1;

  return d >= 0 ? d > 0 ? 1 : 0 : -1;
}

int dot2(int a, int b, int i) {
  ld dx0 = x[b]-x[a];
  ld dy0 = y[b]-y[a];

  ld dx1 = xx[i]-x[a];
  ld dy1 = yy[i]-y[a];

  ld d = dx0*dy1 - dy0*dx1;

  return d > -EPS ? d > EPS ? 1 : 0 : -1;
}

int main() {
  for (int i = 0; i < 8; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 0; i < 4; i++) xx[0] += x[i], yy[0] += y[i];
  for (int i = 4; i < 8; i++) xx[1] += x[i], yy[1] += y[i];
  xx[0] /= 4; yy[0] /= 4;
  xx[1] /= 4; yy[1] /= 4;

  for (int i = 4; i < 8; i++) {
    int o = dot(0, 1, i);
    int ok = 1;
    for (int j = 1; j < 4 and ok; j++) {
      int no = dot(j, (j+1)%4, i);
      if (!no) continue;

      if (!o) o = no;
      if (no != o) ok = 0;
    }
    if (ok) return !printf("YES\n");
  }

  for (int i = 0; i < 4; i++) {
    int o = dot(4, 5, i);
    int ok = 1;
    for (int j = 5; j < 8 and ok; j++) {
      int no = dot(j, 4+((j+1)%4), i);
      if (!no) continue;

      if (!o) o = no;
      if (no != o) ok = 0;
    }
    if (ok) return !printf("YES\n");
  }

  {
    int o = dot(4, 5, 0);
    int ok = 1;
    for (int j = 5; j < 8 and ok; j++) {
      int no = dot2(j, 4+((j+1)%4), 0);
      if (!no) continue;

      if (!o) o = no;
      if (no != o) ok = 0;
    }
    if (ok) return !printf("YES\n");
  }

  {
    int o = dot2(0, 1, 1);
    int ok = 1;
    for (int j = 1; j < 4 and ok; j++) {
      int no = dot2(j, (j+1)%4, 1);
      if (!no) continue;

      if (!o) o = no;
      if (no != o) ok = 0;
    }
    if (ok) return !printf("YES\n");
  }

  printf("NO\n");

  return 0;
}
