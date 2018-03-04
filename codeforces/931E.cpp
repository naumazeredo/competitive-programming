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

char t[5005];
string s;
int n, cnt[30][5005][30], ch[30];

int main() {
  scanf("%s", t);
  s = t;
  n = s.length();
  s += t;

  for (int i = 0; i < n; i++) {
    int f = s[i]-'a';
    ch[f]++;
    for (int j = 1; j < n; j++) {
      int l = s[i+j]-'a';
      cnt[f][j][l]++;
    }
  }

  int ans = 0;

  for (int f = 0; f < 26; f++) {
    int ma = 0;
    for (int j = 1; j < n; j++) {
      int k = 0;
      for (int l = 0; l < 26; l++)
        if (cnt[f][j][l] == 1) k++;
      ma = max(ma, k);
    }
    ans += ma;
  }

  printf("%.12Lf\n", ans/(ld)n);

  return 0;
}
