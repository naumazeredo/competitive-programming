#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second
#define mp make_pair

typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int n;
pii p[1000005];
int st[4000005], v[1000005];

void build(int p, int l, int r) {
    if (l == r) st[p] = v[l];
    else {
        build(2*p, l, (l+r)/2);
        build(2*p+1, (l+r)/2+1, r);
        st[p] = min(st[2*p], st[2*p+1]);
    }
}
void build() {build(1, 0, n-1);}

int query(int p, int l, int r, int i, int j) {
    if (i>r || j<l) return INF;
    if (l >= i && r <= j) return st[p];
    int p1 = query(2*p, l, (l+r)/2, i, j);
    int p2 = query(2*p+1, (l+r)/2+1, r, i, j);
    return min(p1, p2);
}

int query(int i, int j) {return query(1, 0, n-1, i, j);}

int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]), p[i]=mp(-v[i], i);
    build();

    sort(p, p+n);

    vector<int> a, t;
    set<int> s;
    for (int i = 0; i < n; ++i) {
      int x = p[i].nd, vx = -p[i].st;
      int l=0, r=n-1;

      set<int>::iterator it;
      it = s.lower_bound(x);
      if (it != s.begin()) it--, l = *it;
      it = s.upper_bound(x);
      if (it != s.end()) r = *it;

      if (vx-max(query(l, x), query(x, r)) >= 150000)
        a.pb(x+1);

      if (i == n-1 or p[i].st != p[i+1].st) {
        s.insert(x);
        for (int j = 0; j < t.size(); ++j) s.insert(t[j]);
        t.clear();
      } else {
        t.pb(x);
      }
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) printf("%d%c", a[i], i==a.size()-1?'\n':' ');
  }
  return 0;
}
