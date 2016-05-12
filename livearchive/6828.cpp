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

int n;
int a[2000];

int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a+n);
    int m = 0;
    for (int i = 0; i < n; i+=2) m += min(a[i+1]-a[i], 24-a[i+1]+a[i]);

    int m2 = min(a[n-1]-a[0], 24-a[n-1]+a[0]);
    for (int i = 1; i < n-1; i+=2) m2 += min(a[i+1]-a[i], 24-a[i+1]+a[i]);

    printf("%d\n", min(m, m2));
  }
  return 0;
}
