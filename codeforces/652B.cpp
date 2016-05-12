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
int a[2000];
int b[2000];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a+n);

  int p = 0;
  int i = 0, j = n-1;
  while (i <= j) {
    b[p++] = a[i++];
    if (i <= j) b[p++] = a[j--];
  }

  for (int i = 0; i < n; ++i) printf("%d ", b[i]);
  printf("\n");

  return 0;
}
