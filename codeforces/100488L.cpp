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

mt19937_64 llrand(random_device{}());

struct node {
  int cnt, rev;
  ll pri;
  char ch;
  node* l;
  node* r;

  node() {}
  node(char c) : cnt(1), rev(0), pri(llrand()), ch(c), l(0), r(0) {}
};

struct treap {
  node* root;
  treap() : root(0) {}

  int cnt(node* t) { return t ? t->cnt : 0; }

  void push(node* t) {
    if (!t or !t->rev) return;
    swap(t->l, t->r);
    if (t->l) t->l->rev = !t->l->rev;
    if (t->r) t->r->rev = !t->r->rev;
    t->rev = 0;
  }

  void update(node*& t) {
    if (!t) return;
    push(t);
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
  }

  node* merge(node* l, node* r) {
    update(l); update(r);
    if (!l) return r;
    if (!r) return l;

    if (l->pri > r->pri) {
      l->r = merge(l->r, r);
      update(l); update(r);
      return l;
    }

    r->l = merge(l, r->l);
    update(l); update(r);
    return r;
  }

  pair<node*, node*> split(node* t, int pos) {
    if (!t) return {0, 0};
    update(t);

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

  void insert(int pos, char c) {
    //if (has(root, val)) return;
    push(root);
    node* x = new node(c);
    auto t = split(root, pos);
    root = merge(merge(t.st, x), t.nd);
  }

  void reverse(int posl, int posr) {
    auto t2 = split(root, posr+1);
    auto t1 = split(t2.st, posl);

    t1.nd->rev = 1;
    push(t1.nd);

    root = merge(merge(t1.st, t1.nd), t2.nd);
  }

  char get_char(int pos) { return get_char(root, pos); }
  char get_char(node* t, int pos) {
    push(t);
    if (cnt(t->l) == pos) return t->ch;
    if (cnt(t->l) < pos) return get_char(t->r, pos-cnt(t->l)-1);
    return get_char(t->l, pos);
  }

  void print() { print(root); printf("\n"); }
  void print(node* t) {
    if (!t) return;
    push(t);
    print(t->l);
    printf("%c", t->ch);
    print(t->r);
  }
};

treap tr;
int n, l, r, m;
char c, x, y;

int main() {
  scanf("%d%d%d", &n, &l, &r); l--, r--;
  for (int i = 0; i < n; i++) scanf(" %c", &c), tr.insert(i, c);
  scanf("%d", &m);
  while (m--) {
    scanf(" %c", &c);
    if (c == 'S') scanf(" %c %c", &x, &y), (x=='L' ? l : r) += (y=='L'?-1:1);
    if (c == 'R') tr.reverse(l, r);
    if (c == 'Q') scanf(" %c", &c), printf("%c", tr.get_char(c=='L'?l:r));
  }
  return 0;
}
