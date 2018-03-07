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
const int N = 1e2+5;

int n;
char s[N];

bool v(char c) {
  for (int i = 0; i < 6; i++)
    if (c == "aeiouy"[i]) return 1;
  return 0;
}

int main() {
  scanf("%d%s", &n, s);
  printf("%c", s[0]);
  for (int i = 1; i < n; i++) {
    if (v(s[i-1]) and v(s[i])) continue;
    printf("%c", s[i]);
  }
  printf("\n");

  return 0;
}
