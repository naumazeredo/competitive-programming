#include <cstdio>
#include <bitset>
using namespace std;

const int INF = 0x3f3f3f3f;

bitset<32> dir[30];

int main() {
  int t, m, d, c, key;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i) {
    scanf("%d %d", &m, &d);

    for (int j = 0; j < d; ++j) {
      dir[j] = bitset<32>();
      scanf("%d", &c);
      for (int k = 0; k < c; ++k)
        scanf("%d", &key), dir[j].set(key);
    }

    int mindirs = INF;
    for (int j = 0; j < (1<<d); ++j) {
      bitset<20> s(j);
      bitset<32> keys;
      for (int k = 0; k < 32; ++k) if (s[k]) keys |= dir[k];
      if (keys.count() >= m) mindirs = min(mindirs, (int)s.count());
    }

    if (mindirs < 100) printf("%d\n", mindirs);
    else printf("Desastre!\n");
  }

  return 0;
}
