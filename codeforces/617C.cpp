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
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;

pii a[3];

int main() {
  for (int i = 0; i < 3; ++i) scanf("%d%d", &a[i].st, &a[i].nd);

  if (a[0].st == a[1].st and a[0].st == a[2].st) return 0*printf("1\n");
  if (a[0].nd == a[1].nd and a[0].nd == a[2].nd) return 0*printf("1\n");

  if (a[0].st == a[1].st or a[0].st == a[2].st or a[1].st == a[2].st) {
    for (int i = 0; i < 3; ++i) swap(a[i].st, a[i].nd);
    sort(a, a+3);
    if (a[0].st == a[1].st or a[1].st == a[2].st) printf("2\n");
    else printf("3\n");
    return 0;
  }

  if (a[0].nd == a[1].nd or a[0].nd == a[2].nd or a[1].nd == a[2].nd) {
    sort(a, a+3);
    if (a[0].st == a[1].st or a[1].st == a[2].st) printf("2\n");
    else printf("3\n");
    return 0;
  }

  printf("3\n");

  return 0;
}
