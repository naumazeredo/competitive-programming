#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

ll addmod(ll a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

ll submod(ll a, ll b) {
  a -= b;
  if (a < MOD) a += MOD;
  return a;
}

ll mulmod(ll a, ll b) {
  return a*b % MOD;
}

struct mat {
  ll v[2][2];

  mat() {
    v[0][0] = v[1][1] = 1;
    v[0][1] = v[1][0] = 0;
  }

  mat(const mat& m) {
    v[0][0] = m.v[0][0];
    v[0][1] = m.v[0][1];
    v[1][0] = m.v[1][0];
    v[1][1] = m.v[1][1];
  }

  mat operator=(mat m) {
    v[0][0] = m.v[0][0];
    v[0][1] = m.v[0][1];
    v[1][0] = m.v[1][0];
    v[1][1] = m.v[1][1];
  }

  mat operator*(mat m) {
    mat r;
    r.v[0][0] = addmod(mulmod(v[0][0], m.v[0][0]), mulmod(v[0][1], m.v[1][0]));
    r.v[0][1] = addmod(mulmod(v[0][0], m.v[0][1]), mulmod(v[0][1], m.v[1][1]));
    r.v[1][0] = addmod(mulmod(v[1][0], m.v[0][0]), mulmod(v[1][1], m.v[1][0]));
    r.v[1][1] = addmod(mulmod(v[1][0], m.v[0][1]), mulmod(v[1][1], m.v[1][1]));
    return r;
  }
};

ll n;
ll tmp[2][2], a[2][2], b[2][2];

mat fexp(ll n) {
  mat res;
  mat a;
  a.v[0][0] = a.v[1][1] = 3;
  a.v[0][1] = a.v[1][0] = 1;

  while (n) {
    if (n&1) res = res*a;
    a = a*a;
    n /= 2;
  }

  return res;
}

int main() {
  scanf("%lld", &n);

  mat r = fexp(n);
  printf("%lld\n", r.v[0][0]);
  return 0;
}
