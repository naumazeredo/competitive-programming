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
  #define db(x)
  #define dbs(x)
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

mt19937 llrand(random_device{}());

struct node {
  int val, cnt, mn, mx, mindiff;
  ll pri;
  node* l;
  node* r;

  node() {}
  node(int x) : val(x), cnt(1), mn(x), mx(x), mindiff(INF), pri(llrand()), l(0), r(0) {}
};

struct treap {
  node* root;
  treap() : root(0) {}

  int cnt(node* t) { return t ? t->cnt : 0; }
  int mn (node* t) { return t ? t->mn  : INF; }
  int mx (node* t) { return t ? t->mx  : -INF; }
  int mindiff(node* t) { return t ? t->mindiff : INF; }

  void update(node*& t) {
    if (!t) return;
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
    t->mn = min(t->val, min(mn(t->l), mn(t->r)));
    t->mx = max(t->val, max(mx(t->l), mx(t->r)));
    t->mindiff = min(mn(t->r) - t->val, min(t->val - mx(t->l), min(mindiff(t->l), mindiff(t->r))));
  }

  node* merge(node* l, node* r) {
    if (!l) return r;
    if (!r) return l;
    update(l); update(r);

    if (l->pri > r->pri) {
      l->r = merge(l->r, r);
      update(l); update(r);
      return l;
    }

    r->l = merge(l, r->l);
    update(l); update(r);
    return r;
  }

  pair<node*, node*> split(node* t, int pos, int acc) {
    if (!t) return {0, 0};

    update(t);
    int key = acc + cnt(t->l);

    if (key < pos) {
      auto x = split(t->r, pos, key+1);
      t->r = x.st;
      update(t);
      return { t, x.nd };
    }

    auto x = split(t->l, pos, acc);
    t->l = x.nd;
    update(t);
    return { x.st, t };
  }

  int order(node* t, int val) {
    if (!t) return 0;
    if (t->val < val) return cnt(t->l) + 1 + order(t->r, val);
    return order(t->l, val);
  }

  bool has(node* t, int val) {
    if (!t) return 0;
    if (t->val == val) return 1;
    return has((t->val > val ? t->l : t->r), val);
  }

  void insert(int val) {
    if (has(root, val)) return;
    node* x = new node(val);
    auto t = split(root, order(root, val), 0);
    root = merge(merge(t.st, x), t.nd);
  }

  void erase(int val) {
    if (!has(root, val)) return;

    auto t1 = split(root, order(root, val), 0);
    auto t2 = split(t1.nd, 1, 0);
    delete t2.st;
    root = merge(t1.st, t2.nd);
  }

  int querymax(int i, int j) {
    if (i == j) return -1;
    auto t1 = split(root, j+1, 0);
    auto t2 = split(t1.st, i, 0);

    int ans = mx(t2.nd) - mn(t2.nd);
    root = merge(merge(t2.st, t2.nd), t1.nd);
    return ans;
  }

  int querymin(int i, int j) {
    if (i == j) return -1;
    auto t1 = split(root, j+1, 0);
    auto t2 = split(t1.st, i, 0);

    int ans = mindiff(t2.nd);
    root = merge(merge(t2.st, t2.nd), t1.nd);
    return ans;
  }

  void print(node* t) {
    if (!t) return;
    print(t->l);
    printf("%d\n", t->val);
    print(t->r);
  }
};

treap t;

int main() {
  int n, a, b;
  scanf("%d", &n);

  while (n--) {
    char c;
    scanf(" %c", &c);
    if (c == 'I') scanf("%d", &a), t.insert(a);
    if (c == 'D') scanf("%d", &a), t.erase(a);
    if (c == 'N') scanf("%d%d", &a, &b), printf("%d\n", t.querymin(a, b));
    if (c == 'X') scanf("%d%d", &a, &b), printf("%d\n", t.querymax(a, b));
  }
  return 0;
}
