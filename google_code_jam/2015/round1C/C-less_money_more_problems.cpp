#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> ds;

int main()
{
  int t, c, d, v;
  scanf("%d", &t);

  for (int tt = 1; tt <= t; ++tt) {
    ds.clear();

    printf("Case #%d: ", tt);

    scanf("%d%d%d", &c, &d, &v);

    ds.reserve(d);
    for (int i = 0; i < d; ++i)
    {
      int a;
      scanf("%d", &a);
      ds.push_back(a);
    }

    sort(ds.begin(), ds.end());

    int m = 0;
    if (ds[0] > 1) {
      ds.insert(ds.begin(), 1);
      m++;
    }
    //fprintf(stderr, "m: %d\n", m);

    long long ma = c;

    for (int i = 1; i < (int)ds.size(); ++i) {
      if (ma < ds[i] - 1) {
        //fprintf(stderr, "insert: %d\n", ma + 1);
        ds.insert(ds.begin() + i, ma + 1);
        //fprintf(stderr, "insert: %lld\n", ma + 1);
        m++;
      }

      ma += ds[i] * c;
    }
    //fprintf(stderr, "ma: %d\n", ma);
    //fprintf(stderr, "m: %d\n", m);

    while (ma < v) {
      ds.push_back(ma + 1);
      //fprintf(stderr, "insert: %lld\n", ma + 1);
      ma += (ma + 1) * c;
      m++;
    }
    //fprintf(stderr, "m: %d\n", m);

    printf("%d\n", m);
    fprintf(stderr, "Case #%d: %d\n", tt, m);
  }

  return 0;
}
