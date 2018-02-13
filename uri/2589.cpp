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
const int N = 1e5+5, V = 1e9+1;

/*
  // Precalculate prime gaps
  char p[V];
  ll x, l, n, d;

  int main() {
  l = 2, d = -1;
  for (ll i = 2; i < V; i++) if (!p[i]) {
  if (i - l > d) {
  d = i-l;
  printf("v[%lld] = %lld; d[%lld] = %lld;\n", n, i, n, d);
  n++;
  }

  for (ll j = i*i; j < V; j+=i) p[j]=1;
  l = i;
  }

  return 0;
  }
  */

int g() {
  char c;
  while (isspace(c = getchar_unlocked())) ;
  int n = c-'0';
  while (~(c = getchar_unlocked()) and c >= '0' and c <= '9') n = 10*n+c-'0';
  if (c == EOF) return EOF;
  return n;
}

int v[35], d[35], x;

int main() {

  v[0] = 2; d[0] = 0;
  v[1] = 3; d[1] = 1;
  v[2] = 5; d[2] = 2;
  v[3] = 11; d[3] = 4;
  v[4] = 29; d[4] = 6;
  v[5] = 97; d[5] = 8;
  v[6] = 127; d[6] = 14;
  v[7] = 541; d[7] = 18;
  v[8] = 907; d[8] = 20;
  v[9] = 1151; d[9] = 22;
  v[10] = 1361; d[10] = 34;
  v[11] = 9587; d[11] = 36;
  v[12] = 15727; d[12] = 44;
  v[13] = 19661; d[13] = 52;
  v[14] = 31469; d[14] = 72;
  v[15] = 156007; d[15] = 86;
  v[16] = 360749; d[16] = 96;
  v[17] = 370373; d[17] = 112;
  v[18] = 492227; d[18] = 114;
  v[19] = 1349651; d[19] = 118;
  v[20] = 1357333; d[20] = 132;
  v[21] = 2010881; d[21] = 148;
  v[22] = 4652507; d[22] = 154;
  v[23] = 17051887; d[23] = 180;
  v[24] = 20831533; d[24] = 210;
  v[25] = 47326913; d[25] = 220;
  v[26] = 122164969; d[26] = 222;
  v[27] = 189695893; d[27] = 234;
  v[28] = 191913031; d[28] = 248;
  v[29] = 387096383; d[29] = 250;
  v[30] = 436273291; d[30] = 282;
  v[31] = INF;

  while (~(x = g())) {
    int i = 0;
    for (; v[i] <= x; i++) ;
    printf("%d\n", d[i-1]);
  }

  return 0;
}
