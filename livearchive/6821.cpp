#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7;

int main() {
  while (1) {
    int a[5], x, res=0;
    for (int i = 0; i < 5; ++i) if (scanf("%d", &a[i])==EOF) return 0;
    for (int i = 0; i < 5; ++i) scanf("%d", &x), res += x^a[i];
    printf("%s\n", (res==5?"Y":"N"));
  }
  return 0;
}
