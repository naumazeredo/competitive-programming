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
const int N = 1e5;

int k;
string s;

void go(char c) {
  //db(k _ c);
  if (k <= 0) return;

  ll lo = 1, hi = N;
  while (lo < hi) {
    ll mid = (lo+hi+1)/2;
    //db(lo _ mid _ hi _ (mid*(mid+1)/2) _ k);
    if (mid*(mid+1)/2 > k) hi = mid-1;
    else lo = mid;
  }
  for (int i = 0; i <= lo; i++) s+=c;
  k -= lo*(lo+1)/2;
  go(c+1);
}

int main() {
  scanf("%d", &k);
  if (k == 0) return printf("a\n"), 0;
  go('a');
  assert(s.size() <= N);
  printf("%s\n", s.c_str());
  return 0;
}
