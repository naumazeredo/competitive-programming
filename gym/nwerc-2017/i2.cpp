#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
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

map<ll, char> mp, cmp;
set<ll> ds, cds;
char c;
ll p;

void add(ll k, char c) {
  map<ll, char> nmp;
  nmp[k] = c;
  for(auto p : mp) nmp[p.first < k ? p.first : p.first+1] = p.second;
  mp = nmp;
}

void del(ll k) {
  if (mp.count(k)) mp.erase(k);
  else {
    ll n = k;
    for(auto p : mp) if (p.first <= k) n--;
    for(auto d : ds) if (d <= n) n++;
    ds.insert(n);
  }

  map<ll, char> nmp;
  for(auto p : mp) nmp[p.first < k ? p.first : p.first-1] = p.second;
  mp = nmp;
}

void get() {
  while(1) {
    scanf(" %c", &c);
    if (c == 'E') return;
    else if (c == 'D') scanf("%lld", &p), del(p);
    else if (c == 'I') scanf("%lld %c", &p, &c), add(p, c);
  }
}

int main() {
  get();
  cmp = mp, cds = ds;
  mp.clear(), ds.clear();
  get();

  printf("%d\n", !(cmp == mp and cds == ds));
  return 0;
}
