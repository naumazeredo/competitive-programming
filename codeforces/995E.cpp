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

int u, v, p;
set<int> m[2];
map<int, pii> rec[2];

ll fexp(ll a, ll b, ll m) {
  ll r = 1;
  for (a%=m; b; a = (a*a)%m, b>>=1) if (b&1) r = (r*a)%m;
  return r;
}

void solv() {
  if (u == v) {
    printf("0\n");
    return;
  }

  queue<pii> q;
  q.push({ 0, u });
  q.push({ 1, v });

  while (q.size()) {
    pii x = q.front(); q.pop();
    int t = x.st;
    int a = x.nd;

    if (m[1-t].count(a)) {
      vector<int> ans;
      int k = a;
      while (k != u) {
        pii r = rec[0][k];
        ans.push_back(r.nd);
        k = r.st;
      }

      reverse(ans.begin(), ans.end());
      k = a;
      while (k != v) {
        pii r = rec[1][k];
        ans.push_back(r.nd);
        k = r.st;
      }

      printf("%d\n", (int)ans.size());
      for (int x : ans) printf("%d ", x);
      printf("\n");
      return;
    }

    int b;

    b = (a+1)%p;
    if (!m[t].count(b)) {
      m[t].insert(b);
      rec[t][b] = { a, t==0 ? 1 : 2 };
      q.push({t, b});
    }

    b = (a+p-1)%p;
    if (!m[t].count(b)) {
      m[t].insert(b);
      rec[t][b] = { a, t==0 ? 2 : 1 };
      q.push({t, b});
    }

    b = fexp(a,p-2,p);
    if (!m[t].count(b)) {
      m[t].insert(b);
      rec[t][b] = { a, 3 };
      q.push({t, b});
    }
  }
}

int main() {
  scanf("%d%d%d", &u, &v, &p);
  solv();
  return 0;
}
