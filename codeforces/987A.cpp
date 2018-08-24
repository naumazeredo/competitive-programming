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

int main() {
  map<string, string> m;
  m["purple"] = "Power";
  m["green"] = "Time";
  m["blue"] = "Space";
  m["orange"] = "Soul";
  m["red"] = "Reality";
  m["yellow"] = "Mind";

  int n;
  scanf("%d", &n);

  set<string> s;
  string t;
  for (int i = 0; i < n; i++) cin >> t, s.insert(t);

  set<string> ans;
  for (auto& x : m)
    if (!s.count(x.st)) ans.insert(x.nd);

  printf("%d\n", (int)ans.size());
  for (auto& x : ans) printf("%s\n", x.c_str());

  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  return 0;
}
