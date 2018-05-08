#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;

const int N = 5e3+5, M = 1e6+5;

int n, ans[N];
int v[N], prv[N];

int p[M];
vector<int> pp;

int proc(int x) {
  int res = 1;
  if (x == 0) return 0;
  if (x < 0) res *= -1, x *= -1;

  for (ll p : pp) {
  //for (ll p = 2; p*p <= x; p += p==2?1:2) {
    if (p*p > x) break;
    if (x % p) continue;

    int cnt = 0;
    while (x % p == 0) cnt = 1-cnt, x /= p;
    if (cnt) res *= p;
  }
  if (x > 1) res *= x;

  return res;
}

int main() {
  for (ll i = 2; i < M; i++) if (!p[i]) {
    for (ll j = 2*i; j < M; j+=i) p[j] = 1;
    pp.push_back(i);
  }

  scanf("%d", &n);
  for (int x, i = 0; i < n; i++) {
    scanf("%d", &x);
    v[i] = proc(x);
  }

  memset(prv, -1, sizeof prv);
  for (int i = 0; i < n; i++) {
    for (int j = i-1; j >= 0; j--) {
      if (v[i] == v[j]) {
        prv[i] = j;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    int gr = 0;
    for (int j = i; j < n; j++) {
      if (prv[j] < i and v[j] != 0) gr++;
      ans[max(1, gr)]++;
    }
  }

  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
