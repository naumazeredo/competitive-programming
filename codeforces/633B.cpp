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

int m;

int main() {
  scanf("%d", &m);

  vector<int> v;

  int c = 0;
  for (int i = 1; i <= 10000000; i++) {
    int x = i;
    while (x%5==0) c++, x/=5;
    if (c == m) v.pb(i);
  }

  printf("%d\n", (int)v.size());
  for (int i = 0; i < v.size(); ++i) printf("%d ", v[i]);
  if (v.size()) printf("\n");
  return 0;
}
