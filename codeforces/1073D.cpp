// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

// Treap (probabilistic BST)
// O(logn) operations (supports lazy propagation)

mt19937_64 llrand(random_device{}());

struct node {
  int val;
  ll sum;
  int cnt, rev;
  ll pri;
  node* l;
  node* r;

  node() {}
  node(int x) : val(x), sum(x), cnt(1), rev(0), pri(llrand()), l(0), r(0) {}
};

struct treap {
  node* root;
  treap() : root(0) {}
  ~treap() { clear(); }

  int cnt(node* t) { return t ? t->cnt : 0; }
  ll sum(node* t) { return t ? t->sum : 0; }

  void clear() { del(root); }
  void del(node* t) {
    if (!t) return;
    del(t->l); del(t->r);
    delete t;
    t = 0;
  }

  void update(node*& t) {
    if (!t) return;
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
    t->sum= sum(t->l) + sum(t->r) + t->val;
  }

  node* merge(node* l, node* r) {
    node* t;
    if (!l or !r) t = l ? l : r;
    else if (l->pri > r->pri) l->r = merge(l->r, r), t = l;
    else r->l = merge(l, r->l), t = r;
    update(t);
    return t;
  }

  pair<node*, node*> split(node* t, int pos) {
    if (!t) return {0, 0};

    if (cnt(t->l) < pos) {
      auto x = split(t->r, pos-cnt(t->l)-1);
      t->r = x.st;
      update(t);
      return { t, x.nd };
    }

    auto x = split(t->l, pos);
    t->l = x.nd;
    update(t);
    return { x.st, t };
  }

  int size() { return cnt(root); }
  ll sum() { return sum(root); }

  // Position-based treap
  // used when the values are just additional data
  // the positions are known when it's built, after that you
  // query to get the values at specific positions
  void insert(int val) {
    int pos = cnt(root);
    insert(pos, val);
  }

  void insert(int pos, int val) {
    node* x = new node(val);
    auto t = split(root, pos);
    root = merge(merge(t.st, x), t.nd);
  }

  void erase(int pos) {
    auto t1 = split(root, pos);
    auto t2 = split(t1.nd, 1);
    delete t2.st;
    root = merge(t1.st, t2.nd);
  }

  void rot(int x) {
    auto t = split(root, x);
    root = merge(t.nd, t.st);
  }

  void rot() { rot(1); }

  ll sum(int n) {
    auto t = split(root, n);
    ll res = sum(t.st);
    root = merge(t.st, t.nd);
    return res;
  }

  int get_val(int pos) { return get_val(root, pos); }
  int get_val(node* t, int pos) {
    if (cnt(t->l) == pos) return t->val;
    if (cnt(t->l) < pos) return get_val(t->r, pos-cnt(t->l)-1);
    return get_val(t->l, pos);
  }

  void print() { print(root); printf("\n"); }
  void print(node* t) {
    if (!t) return;
    print(t->l);
    printf("%d ", t->val);
    print(t->r);
  }
};

int n, a[N];
ll t;

int main() {
  scanf("%d%lld", &n, &t);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  treap tr;
  for (int i = 0; i < n; i++) tr.insert(a[i]);

  ll ans = 0;
  while (tr.size()) {
    //db(t _ tr.size() _ tr.sum());
    ans += t/tr.sum()*tr.size();
    t %= tr.sum();
    //db(t _ ans);

    /*
    while (tr.get_val(0) <= t) {
      db(tr.get_val(0));
      t -= tr.get_val(0), ans++, tr.rot();
    }
    tr.erase(0);
    */

    int lo = 0, hi = tr.size();
    while (lo < hi) {
      int md = (lo+hi+1)/2;

      if (tr.sum(md) > t) hi = md-1;
      else lo = md;
    }

    //db(lo);

    ans += lo;
    t -= tr.sum(lo);
    tr.rot(lo);
    tr.erase(0);
  }

  printf("%lld\n", ans);

  return 0;
}
