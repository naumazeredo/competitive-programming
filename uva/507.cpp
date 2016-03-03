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

int b, s;
int a[30000];

int main() {
  scanf("%d", &b);
  for (int r = 1; r <= b; ++r) {
    scanf("%d", &s);
    for (int i = 0; i < s-1; ++i) scanf("%d", &a[i]);

    int bx=0, by=-1;
    int m = 0, mfs = 0, x=0;
    for (int i = 0; i < s-1; ++i) {
      m += a[i];
      if (m < 0) m = 0, x=i+1;
      else if (m > mfs) mfs = m, bx=x, by=i;
      else if (m == mfs and i-x > by-bx) bx=x, by=i;
    }

    if (mfs) printf("The nicest part of route %d is between stops %d and %d\n", r, bx+1, by+2);
    else printf("Route %d has no nice parts\n", r);
  }
  return 0;
}
