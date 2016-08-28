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
const int N = 1e5+5;

char s[N];

int main() {
  scanf("%s", s);
  int l = strlen(s);

  int i = 0;
  for (; i < l and s[i]=='a'; ++i);

  if (i == l) {
    for (int j = 0; j < l-1; ++j) printf("a");
    printf("z\n");
    return 0;
  }

  int j = i+1;
  for (; j < l and s[j]!='a'; ++j);

  for (int x = 0; x < l; ++x) {
    if (x < i or x >= j) printf("%c", s[x]);
    else if (s[x] == 'a') printf("z");
    else printf("%c", s[x]-1);
  }
  printf("\n");

  return 0;
}
