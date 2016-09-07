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
const int N = 1e6+5;

int m, b[N];
char p[N];

void kmppre() {
  int i = 0, j = -1; b[0] = -1;
  while (i<m) {
    while (j>=0 and p[i]!=p[j]) j=b[j];
    b[++i]=++j;
  }
}

int main() {
  while (~scanf("%s", p) and !(strlen(p) == 1 and p[0] == '.')) {
    m = strlen(p);
    kmppre();
    int j = m-1;
    while (j>=0 and m%(m-b[j+1])) j=b[j];
    printf("%d\n", m/(m-b[j+1]));
  }
  return 0;
}
