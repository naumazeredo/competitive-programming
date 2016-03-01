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
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int n, p, e;
int a[300000];
int c[300000];
int b[300000];

int main() {
  scanf("%d", &n);
  int x, y;
  for (int i = 0; i < n; ++i) scanf("%d", a+i), x=a[i]==1?i:x;
  for (int i = 0; i < n; ++i) scanf("%d", b+i), y=b[i]==1?i:y;

  int e = 0;
  for (int i = 0; i < n; ++i) {
    if (!a[(i+x)%n]) x++;
    if (!b[(i+y)%n]) y++;
    if (a[(i+x)%n] != b[(i+y)%n]) {
      printf("NO\n"); return 0;
    }
  }

  printf("YES\n");

  return 0;
}
