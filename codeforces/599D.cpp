#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Essa questão é de matemática.

// Dado um retângulo nxm, temos:
// (assumindo que n >= m)
// quadrados de tam 1: n*m
// quadrados de tam 2: (n-1)*(m-1)
// quadrados de tam 3: (n-2)*(m-2)
// ...
// quadrados de tam m-1: (n-(m-1))*(m-(m-1))

// n*m + (n-1)*(m-1) + .. + (n-(m-1))*(m-(m-1)) = x
// 3*m^2*n - m^3 + 3*m*n + m = 6*x

// Se n = m:
// 3*m^3 - m^3 + 3*m^2 + m = 6*x
// m^3 <= 3*x
// m <= (3*x)^(1/3)

// Portanto o número máximo de m que vamos calcular vai ser
// (3*10^18)^(1/3) <= 2*10^6
// Então conseguimos testar todos esse valores de m (!!!)
// Devemos "chutar" um valor de m, calcular o valor de n,
// e ver se é possível usando a fórmula calculada

// n = (6*x + m^3 - m)/(3*m*(m+1))


ll x;

int main() {
  scanf("%lld", &x);

  vector<ll> a, b;
  for (ll m = 1; ; ++m) {
    ll n = (6*x - m + m*m*m)/(3*m*(m+1));
    if (m > n) break;

    if (3*m*m*n - m*m*m + 3*m*n + m == 6*x)
      a.push_back(m), b.push_back(n);
  }

  printf("%d\n", 2*a.size() - (a.back() == b.back())); // se a.back() == b.back(), temos n == m e não devemos imprimir denovo esse par!

  // ordem direta
  for (int i = 0; i < a.size(); ++i)
    printf("%lld %lld\n", a[i], b[i]);

  // ordem inversa
  for (int i = a.size()-1 - (a.back() == b.back()); i >= 0; --i) // temos que tratar o caso de a.back() == b.back() denovo, para não imprimir em dobro
    printf("%lld %lld\n", b[i], a[i]);

  return 0;
}
