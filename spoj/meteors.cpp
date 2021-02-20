#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define db(x) cerr<<#x<<" == "<<x<<endl
#define _ <<", "<<

const ll INF = 0x3f3f3f3f;
const int N = 3e5+5;

int n, m, k, p[N], o[N], l[N], r[N], a[N], ans[N];
vector<int> own[N];
ll bit[N];

void add(int i, int v) {
  for (i+=2; i < N; i+=i&-i) bit[i] += v;
}

ll query(int i) {
  ll r = 0;
  for (i+=2; i; i-=i&-i) r += bit[i];
  return r;
}

void apply(int i, int c) {
  if (l[i] <= r[i]) {
    add(l[i], c * a[i]);
    add(r[i]+1, -c * a[i]);
  } else {
    add(1, c * a[i]);
    add(r[i]+1, -c * a[i]);

    add(l[i], c * a[i]);
    add(m+1, -c * a[i]);
  }
}

void go(int lo, int hi, vector<int> v) {
  if (v.empty()) return;

  if (lo == hi) {
    for (int x : v) ans[x] = lo;
    return;
  }

  int mid = (lo + hi)/2;
  vector<int> left, right;

  for (int i = lo; i <= mid; i++)
    apply(i, 1);

  for (int x : v) {
    ll cnt = 0;
    for (int xx : own[x])
      cnt = min(INF, cnt+query(xx));

    if (cnt >= p[x]) left.push_back(x);
    else right.push_back(x);
  }

  go(mid+1, hi, std::move(right));

  for (int i = lo; i <= mid; i++)
    apply(i, -1);

  go(lo, mid, std::move(left));
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", &o[i]), own[o[i]].push_back(i);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) scanf("%d%d%d", &l[i], &r[i], &a[i]);

  vector<int> all;
  for (int i = 1; i <= n; i++) all.push_back(i);

  go(1, k+1, std::move(all));

  for (int i = 1; i <= n; i++) {
    if (ans[i] == k+1) printf("NIE\n");
    else printf("%d\n", ans[i]);
  }

  return 0;
}
