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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

int n, x, l;
char s[200];

int b[] = { 1980, 1900, 2000, 0, 0, 0, 0, 0, 0 };
int e[] = { 1990, 2000, 3000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
int v[] = { 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099 };

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf(" IAO\'%s", s);

    l = strlen(s);
    sscanf(s,"%d",&x);

    if (x < v[l-1]) printf("%d\n", e[l-1]+x);
    else printf("%d\n", b[l-1]+x);
  }
  return 0;
}
