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
const int N = 1e4+5, G = 26;

char s[N], t[N], r[N];
int n;

vector<int> g1[30];
vector<int> g2[30][30];
int pos[N];

void solve0() {
  int cnt = 0;
  char c = 'a';
  for (int i = 0; i < n; i++) {
    t[i] = c;
    cnt++;
    if (cnt >= G*G) cnt = 0, c++;
  }

  printf("? %s\n", t);
  fflush(stdout);
  scanf("%s", r);
  if (r[0] == '0') assert(0);

  for (int i = 0; i < n; i++) g1[int(r[i]-'a')].push_back(i);
}

void solve1() {
  int cnt = 0;
  char c = 'a';
  for (int i = 0; i < n; i++) {
    t[i] = c;
    cnt++;
    if (cnt >= G) cnt = 0, c++;
    if (c-'a' >= G) c = 'a';
  }

  printf("? %s\n", t);
  fflush(stdout);
  scanf("%s", r);
  if (r[0] == '0') assert(0);

  for (int g = 0; g < G; g++) {
    for (int x : g1[g]) {
      g2[g][int(r[x]-'a')].push_back(x);
    }
  }
}

void solve2() {
  char c = 'a';
  for (int i = 0; i < n; i++) {
    t[i] = c;
    c++;
    if (c-'a' >= G) c = 'a';
  }

  printf("? %s\n", t);
  fflush(stdout);
  scanf("%s", r);
  if (r[0] == '0') assert(0);

  for (int g = 0; g < G; g++) {
    for (int sg = 0; sg < G; sg++) {
      for (int x : g2[g][sg]) {
        int l = r[x]-'a';
        pos[g*G*G + sg*G + l] = x;
        //pos[x] = g2[g][sg][l];
      }
    }
  }
}

int main() {
  scanf("%s", s);
  n = strlen(s);

  memset(pos, -1, sizeof pos);
  solve0();

  /*
  for (int g = 0; g < G; g++) {
    printf("%d: ", g);
    for (int x : g1[g]) printf("%d ", x);
    printf("\n");
  }
  */

  solve1();

  /*
  for (int g = 0; g < G; g++) {
    for (int sg = 0; sg < G; sg++) {
      printf("%d, %d: ", g, sg);
      for (int x : g2[g][sg]) printf("%d ", x);
      printf("\n");
    }
    printf("\n");
  }
  */

  solve2();

  //for (int i = 0; i < n; i++) assert(pos[i] >= 0 and pos[i] < n), db(i _ pos[i]);
  for (int i = 0; i < n; i++) t[i] = s[pos[i]];
  printf("! %s\n", t);
  fflush(stdout);

  return 0;
}
