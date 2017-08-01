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
const int N = 1e3+5;

char m[300];
char k[2][30], s[N];

int main() {
  scanf("%s%s", k[0], k[1]);
  for (int i = 0; i < 26; i++) {
    m[k[0][i]] = k[1][i];
    m[k[0][i]-'a'+'A'] = k[1][i]-'a'+'A';
  }

  scanf("%s", s);
  for (int i = 0; s[i]; i++) {
    if (isalpha(s[i])) printf("%c", m[s[i]]);
    else printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}
