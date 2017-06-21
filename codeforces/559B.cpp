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
const int N = 2e5+5;

char a[N], b[N];

int equiv(string a, string b) {
  if (a == b) return 1;
  if (a.length()%2) return 0;
  int n = a.length();
  string a1 = a.substr(0, n/2), a2 = a.substr(n/2,n/2);
  string b1 = b.substr(0, n/2), b2 = b.substr(n/2,n/2);
  return (equiv(a1, b2) and equiv(a2, b1)) or (equiv(a1, b1) and equiv(a2, b2));
}

int main() {
  scanf("%s%s", a, b);
  printf("%s\n", equiv(a, b)?"YES":"NO");

  return 0;
}
