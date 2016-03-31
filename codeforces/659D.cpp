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

int n;
int x[2222], y[2222];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n+1; ++i) scanf("%d%d", &x[i], &y[i]);
  int t = 0;
  for (int i = 2; i < n+1; ++i) {
    t += ((x[i]>x[i-1] and y[i-1]<y[i-2]) or
          (x[i]<x[i-1] and y[i-1]>y[i-2]) or
          (y[i]<y[i-1] and x[i-1]<x[i-2]) or
          (y[i]>y[i-1] and x[i-1]>x[i-2]));
  }
  printf("%d\n", t);
  return 0;
}
