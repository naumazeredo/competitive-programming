#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e5+5;

char s[100];
int v[54];

void rot(int a, int b, int c, int d) {
  int t = v[d];
  v[d] = v[c];
  v[c] = v[b];
  v[b] = v[a];
  v[a] = t;
}

void F() {
  rot(0, 2, 8, 6);
  rot(1, 5, 7, 3);

  rot(42, 9,  47, 35);
  rot(43, 12, 46, 32);
  rot(44, 15, 45, 29);
}

void f() {
  rot(0, 6, 8, 2);
  rot(1, 3, 7, 5);

  rot(42, 35, 47, 9 );
  rot(43, 32, 46, 12);
  rot(44, 29, 45, 15);
}

void R() {
  rot(9,  11, 17, 15);
  rot(10, 14, 16, 12);

  rot(44, 18, 53, 8);
  rot(41, 21, 50, 5);
  rot(38, 24, 47, 2);
}

void r() {
  rot(9,  15, 17, 11);
  rot(10, 12, 16, 14);

  rot(44, 8, 53, 18);
  rot(41, 5, 50, 21);
  rot(38, 2, 47, 24);
}

void B() {
  rot(18, 20, 26, 24);
  rot(19, 23, 25, 21);

  rot(38, 27, 51, 17);
  rot(37, 30, 52, 14);
  rot(36, 33, 53, 11);
}

void b() {
  rot(18, 24, 26, 20);
  rot(19, 21, 25, 23);

  rot(38, 17, 51, 27);
  rot(37, 14, 52, 30);
  rot(36, 11, 53, 33);
}

void L() {
  rot(27, 29, 35, 33);
  rot(28, 32, 34, 30);

  rot(36, 0, 45, 26);
  rot(39, 3, 48, 23);
  rot(42, 6, 51, 20);
}

void l() {
  rot(27, 33, 35, 29);
  rot(28, 30, 34, 32);

  rot(36, 26, 45, 0);
  rot(39, 23, 48, 3);
  rot(42, 20, 51, 6);
}

void U() {
  rot(36, 38, 44, 42);
  rot(37, 41, 43, 39);

  rot(20, 11, 2, 29);
  rot(19, 10, 1, 28);
  rot(18, 9, 0, 27);
}

void u() {
  rot(36, 42, 44, 38);
  rot(37, 39, 43, 41);

  rot(20, 29, 2, 11);
  rot(19, 28, 1, 10);
  rot(18, 27, 0, 9);
}

void D() {
  rot(45, 47, 53, 51);
  rot(46, 50, 52, 48);

  rot(6, 15, 24, 33);
  rot(7, 16, 25, 34);
  rot(8, 17, 26, 35);
}

void d() {
  rot(45, 51, 53, 47);
  rot(46, 48, 52, 50);

  rot(6, 33, 24, 15);
  rot(7, 34, 25, 16);
  rot(8, 35, 26, 17);
}

void rotall() {
  for (int i = 0; s[i]; ++i) {
    if (s[i] == 'R') R();
    if (s[i] == 'r') r();
    if (s[i] == 'F') F();
    if (s[i] == 'f') f();
    if (s[i] == 'B') B();
    if (s[i] == 'b') b();
    if (s[i] == 'L') L();
    if (s[i] == 'l') l();
    if (s[i] == 'U') U();
    if (s[i] == 'u') u();
    if (s[i] == 'D') D();
    if (s[i] == 'd') d();
  }
}

bool eq() {
  for (int i = 0; i < 54; ++i) if (v[i] != i) return 0;
  return 1;
}

int main() {
  while (~scanf(" %s", s)) {
    for (int i = 0; i < 54; ++i) v[i] = i;
    int i;
    rotall();
    for (i=1; !eq(); ++i) rotall();
    printf("%d\n", i);
  }
  return 0;
}
