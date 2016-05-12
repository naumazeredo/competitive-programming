#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 2e9;

const int MAXN = 1e7;
const int MAXLOGN = 30;

int p, d, m, k;
ll tri[405][405][2];

ll gcd(ll a,ll b){
  return b?gcd(b,a%b):a;
}

int main() {
  tri[0][1][0] = 1; tri[0][1][1] = 1;

  for (int i = 1; i <= 400; ++i) {
    int a = 0, b = 1;
    for (int j = i+1; j > 1; --j) {
      ll num = i * tri[i-1][j-1][0],
         den = j * tri[i-1][j-1][1];
      ll g = gcd(num, den);
      num/=g;
      den/=g;
      if (den < 0) num = -num, den = -den;
      tri[i][j][0] = num;
      tri[i][j][1] = den;

      num = a * tri[i][j][1] + b * tri[i][j][0];
      den = b * tri[i][j][1];
      g = gcd(num, den);
      a = num/g;
      b = den/g;
    }

    ll g = gcd(b-a, b);
    ll num = (b-a)/g, den = b/g;
    if (den < 0) num = -num, den = -den;
    tri[i][1][0] = num;
    tri[i][1][1] = den;
  }

  scanf("%d", &p);
  while (p--) {
    scanf("%d%d%d", &d, &m, &k);
    printf("%d ", d);
    if (tri[m][k][1] == 1) printf("%lld\n", tri[m][k][0]);
    else printf("%lld/%lld\n", tri[m][k][0], tri[m][k][1]);
  }
  return 0;
}
