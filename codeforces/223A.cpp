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

char s[N];
int n, m[N], b[N];
int bl, br, bb, l=INF;

int main() {
  scanf("%s", s+1);
  n = strlen(s+1);
  cl(m, 63);

  vector<int> v;

  for (int i = 1; i <= n; i++) {
    b[i] = b[i-1];
    if (s[i] == '(') { v.push_back(i); }
    if (s[i] == '[') { v.push_back(i); }

    if (s[i] == ')') {
      if (v.empty() or s[v.back()] != '(') {
        v.clear();
      } else {
        int l = v.back();
        m[i] = min(l, m[l-1]);
        v.pop_back();
        if (b[i]-b[m[i]-1] >= bb) {
          bl = m[i];
          br = i;
          bb = b[br] - b[bl-1];
        }
      }
    }

    if (s[i] == ']') {
      if (v.empty() or s[v.back()] != '[') {
        v.clear();
      } else {
        int l = v.back();
        m[i] = min(l, m[l-1]);
        v.pop_back();
        b[i]++;
        if (b[i]-b[m[i]-1] >= bb) {
          bl = m[i];
          br = i;
          bb = b[br] - b[bl-1];
        }
      }
    }
  }

  if (bb == 0) return printf("0\n\n"), 0;

  printf("%d\n", bb);
  for (int i = bl; i <= br; i++) printf("%c", s[i]);
  printf("\n");

  return 0;
}
