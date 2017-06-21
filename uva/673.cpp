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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
char s[200];

int main() {
  scanf("%d%*c", &n);
  while (n--) {
    gets(s);
    stack<int> a, b;
    int ok = 1;
    for (int i = 0; s[i] and ok; ++i) {
      if (s[i] == '(') a.push(i);
      if (s[i] == '[') b.push(i);
      if (s[i] == ')') {
        if (a.empty()) { ok = 0; break; }
        if (b.size() and b.top() > a.top()) { ok = 0; break; }
        a.pop();
      }
      if (s[i] == ']') {
        if (b.empty()) { ok = 0; break; }
        if (a.size() and a.top() > b.top()) { ok = 0; break; }
        b.pop();
      }
    }
    ok = ok and a.empty() and b.empty();

    printf("%s\n", ok?"Yes":"No");
  }
  return 0;
}
