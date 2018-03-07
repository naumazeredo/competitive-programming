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
  #define db(x)
  #define dbs(x)
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

char s[105];
int c;

int main() {
  scanf("%s", s);
  int n = strlen(s);

  for (int i = 0; i < n-4; i++) {
    int ok = 1;
    for (int j = 0; j < 5; j++) if (s[i+j] != "Danil"[j]) ok = 0;
    if (ok) c++;
  }
  db(c);

  for (int i = 0; i < n-3; i++) {
    int ok = 1;
    for (int j = 0; j < 4; j++) if (s[i+j] != "Olya"[j]) ok = 0;
    if (ok) c++;
  }
  db(c);

  for (int i = 0; i<n-4; i++) {
    int ok = 1;
    for (int j = 0; j < 5; j++) if (s[i+j] != "Slava"[j]) ok = 0;
    if (ok) c++;
  }

  for (int i = 0; i<n-2; i++) {
    int ok = 1;
    for (int j = 0; j < 3; j++) if (s[i+j] != "Ann"[j]) ok = 0;
    if (ok) c++;
  }

  for (int i = 0; i<n-5; i++) {
    int ok = 1;
    for (int j = 0; j < 6; j++) if (s[i+j] != "Nikita"[j]) ok = 0;
    if (ok) c++;
  }

  db(c);
  printf("%s\n", c==1?"YES":"NO");

  return 0;
}
