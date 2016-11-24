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

int s, d;

int main() {
  while (~scanf("%d%d", &s, &d)) {
    d = -d;
    int v[12], sum = 0;
    for (int i = 0; i < 5; ++i) v[i] = s, sum+=s;
    for (int i = 4; sum >= 0; --i) v[i] = d, sum+=d-s;
    for (int i = 5; i < 12; ++i) {
      sum -= v[i-5];
      if (sum + s < 0) v[i] = s, sum += s;
      else v[i] = d, sum += d;
      //db(i _ sum);
    }

    sum = 0;
    for (int i = 0; i < 12; ++i) sum += v[i];
    if (sum > 0) printf("%d\n", sum);
    else printf("Deficit\n");
  }
  return 0;
}
