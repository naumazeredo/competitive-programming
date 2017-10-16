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
const int N = 2e5+5, SQ = 320;

mt19937 llrand(random_device{}());

struct node {
  int val, id, add, lzadd, lzval;
  ll pri;
  node* l;
  node* r;

  node() {}
  node(int x, int i) : val(x), id(i), add(0), lzadd(0), lzval(0), pri(llrand()), l(0), r(0) {}
};

struct treap {
  node* root;
  treap() : root(0) {}

  void push(node* t) {
    if (!t) return;
    t->val += t->lzval;
    t->add += t->lzadd;

    if (t->l) {
      t->l->lzval += t->lzval;
      t->l->lzadd += t->lzadd;
    }
    if (t->r) {
      t->r->lzval += t->lzval;
      t->r->lzadd += t->lzadd;
    }

    t->lzval = 0;
    t->lzadd = 0;
  }

  node* merge(node* l, node* r) {
    push(l); push(r);
    if (!l) return r;
    if (!r) return l;

    if (l->pri > r->pri) {
      l->r = merge(l->r, r);
      return l;
    }

    r->l = merge(l, r->l);
    return r;
  }

  pair<node*, node*> split(node* t, int val) {
    if (!t) return {0, 0};
    push(t);

    if (t->val < val) {
      auto x = split(t->r, val);
      t->r = x.st;
      return { t, x.nd };
    }

    auto x = split(t->l, val);
    t->l = x.nd;
    return { x.st, t };
  }

  void insert(int val, int id) {
    node* x = new node(val, id);
    auto t = split(root, val);
    root = merge(merge(t.st, x), t.nd);
  }

  void get(node* t, vector<node*>& v) {
    if (!t) return;
    push(t);

    get(t->l, v);
    v.pb(t);
    get(t->r, v);
  }

  void process(int val) {
    auto t1 = split(root, val);
    auto t2 = split(t1.nd, 2*val);

    if (t2.nd) {
      t2.nd->lzadd += 1;
      t2.nd->lzval -= val;
      push(t2.nd);
    }

    vector<node*> v;
    get(t2.st, v);

    for (auto& x : v) {
      x->val -= val;
      x->add += 1;
      x->l = x->r = 0;

      auto t = split(t1.st, x->val);
      t1.st = merge(merge(t.st, x), t.nd);
    }

    root = merge(t1.st, t2.nd);
  }

  void print() { print(root); printf("\n"); }
  void print(node* t) {
    if (!t) return;
    push(t);
    print(t->l);
    printf("(%d,%d) ", t->id, t->val);
    print(t->r);
  }

  void get_ans(int ans[N]) { get_ans(root, ans); }
  void get_ans(node* t, int ans[N]) {
    if (!t) return;
    push(t);
    ans[t->id] = t->add;
    get_ans(t->l, ans);
    get_ans(t->r, ans);
  }
};

treap tr;

int n, k, b, ans[N];
pii v[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &v[i].st, &v[i].nd);
  sort(v, v+n, [](pii a, pii b){ return a.nd == b.nd ? a.st < b.st : a.nd > b.nd; });

  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &b);
    tr.insert(b, i);
  }

  for (int i = 0; i < n; i++) {
    int val = v[i].st;
    tr.process(val);
  }

  tr.get_ans(ans);
  for (int i = 0; i < k; i++) printf("%d ", ans[i]);
  printf("\n");

  return 0;
}
