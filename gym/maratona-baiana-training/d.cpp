// @subject: 
// @diff: 

#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
ll x;

ll reverse(stack<char> &s) {
  ll v = 1;
  while(!s.empty()) {
    if(s.top() == 'l') v = 2*v;
    else v = 2*v + 1;
    s.pop();
  }

  return v;
}

void calc(ll x) {
  ll aux = x;
  int l = 0, o = 0;
  stack<char> s;
  while(aux != 1) {
    if(aux & 1) s.push('l'), l++;
    else s.push('o'), o++;
    aux /= 2;
  }

  if(l < o) printf("%lld\n", x);
  else if(l > o) printf("%lld\n", reverse(s));
  else printf("%lld\n", min(reverse(s), x));
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &x);
    calc(x);
  }
  return 0;
}
