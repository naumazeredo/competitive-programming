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
  int pos;
  int val;
  int cnt, rev;
  ll sum;
  ll pri;
  node* l;
  node* r;

  node() {}
  node(int p, int x) : pos(p), val(x), cnt(1), rev(0), sum(x), pri(llrand()), l(0), r(0) {}
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
    t->sum = sum(t->l) + sum(t->r) + t->val;
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

  // Position-based treap
  // used when the values are just additional data
  // the positions are known when it's built, after that you
  // query to get the values at specific positions
  /*
  void insert(int val) {
    node* x = new node(val);
    root = merge(root, x);
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
  */

  // Value-based treap
  // used when the values needs to be ordered
  int order(node* t, int pos) {
    if (!t) return 0;
    if (t->pos< pos) return cnt(t->l) + 1 + order(t->r, pos);
    return order(t->l, pos);
  }

  /*
  bool has(node* t, int pos) {
    if (!t) return 0;
    if (t->val == pos) return 1;
    return has((t->pos > pos? t->l : t->r), pos);
  }
  */

  void insert(int pos, int val) {
    //if (has(root, pos)) return; // avoid repeated values
    node* x = new node(pos, val);
    auto t = split(root, order(root, pos));
    root = merge(merge(t.st, x), t.nd);
  }

  void erase(int pos) {
    //if (!has(root, pos)) return;

    auto t1 = split(root, order(root, pos));
    auto t2 = split(t1.nd, 1);
    delete t2.st;
    root = merge(t1.st, t2.nd);
  }

  ll query(int m) {
    int extra = cnt(root)%m;
    if (!extra) extra = min(cnt(root), m);

    auto t = split(root, cnt(root) - extra);
    ll res = 2 * sum(t.st) + sum(t.nd);
    root = merge(t.st, t.nd);
    return res;
  }
  // ------------------

  void print() { print(root); printf("\n"); }
  void print(node* t) {
    if (!t) return;
    print(t->l);
    printf("%d ", t->val);
    print(t->r);
  }
};

int c, n, m, p[N];
ll t;

int main() {
  scanf("%d", &c);
  while (c--) {
    scanf("%d%d%lld", &n, &m, &t);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    treap tr;

    ll ans_b = 0, ans_d = t;
    ll d = t;
    set<pii> s;

    for (int i = 0; i < n; i++) {
      if (p[i] > d) continue;
      //db(i _ d);

      tr.insert(i, p[i]);
      s.insert({ p[i], i });

      while (tr.query(m) > t) {
        int v = s.rbegin()->st;
        d = min<ll>(d, v-1);
        while (s.size() and s.rbegin()->st == v) {
          tr.erase(s.rbegin()->nd);
          s.erase(*s.rbegin());
        }
      }

      while (1) {
        i++;
        while (i < n and p[i] > d) i++;
        if (i >= n) break;

        tr.insert(i, p[i]);
        //db(i _ tr.query(m));

        if (tr.query(m) > t) {
          tr.erase(i);
          i--;
          break;
        }

        s.insert({ p[i], i });
      }

      //d = (s.size() ? s.rbegin()->st : 0);
      if (ans_b < (int)s.size()) {
        ans_b = s.size();
        ans_d = d;
      }
      //db(i _ d _ ans_b _ ans_d);
      //dbs("");
    }

    printf("%lld %lld\n", ans_b, ans_d);
  }
  return 0;
}
