#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

char s[20], c;
int r[10];

int main() {
  int p = 0;
  ll n;
  while (~scanf("%lld", &n)) {
    char t[20];
    p = 0;
    while (n) t[p++] = n%10, n/=10;
    for (int i = 0; i < p; ++i) s[i] = t[p-i-1];
    for (int i = 0; i < 10; ++i) r[i]=0;

    int x = 0;
    while (1) {
      if (x == p) break;
      if (s[x] < 0) {
        for (int i = x; i < p; ++i) s[i] = 9;
        x--;
        r[s[x]]--;
        s[x]--;
        continue;
      }
      if (r[s[x]] < 2) { r[s[x]]++; x++; continue; }
      s[x]--;
      for (int i = x+1; i < p; ++i) s[i] = 9;
    }

    x = 0;
    while (!s[x]) x++;

    while (x < p) printf("%c", s[x++]+'0');
    printf("\n");

    p = 0;
  }
  return 0;
}
