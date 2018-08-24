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
const int N = 1e4+5;

int c[30], t;
char s[N];

int main() {
  for (int i = 0; i < 26; i++) scanf("%d", &c[i]), t+=c[i];

  //for (int i = 0; i < t; i++) s[i] = 'x';

  int b = 0, e = t-1;
  for (int i = 0; i < 26; i++) if (c[i]%2 == 0) {
    while (c[i]) {
      s[b++] = 'a'+i;
      s[e--] = 'a'+i;
      c[i]-=2;
    }
  }

  int x = -1;
  for (int i = 0; i < 26; i++) if (c[i]%2)
    if (x == -1 or c[i] > c[x]) x = i;

  for (int i = 0; i < 26; i++) if (i != x) {
    while (c[i] > 1) {
      s[b++] = 'a'+i;
      s[e--] = 'a'+i;
      c[i]-=2;
    }
  }

  while (c[x] > 1) {
    s[b++] = 'a'+x;
    s[e--] = 'a'+x;
    c[x]-=2;
  }
  s[b++] = 'a'+x;
  c[x]--;

  for (int i = 0; i < 26; i++) if (c[i]) {
    s[b++] = 'a'+i;
  }

  printf("%s\n", s);

  return 0;
}
