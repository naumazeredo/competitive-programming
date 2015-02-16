#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int PREMIO_MCDU  = 3000;
const int PREMIO_CDU   = 500;
const int PREMIO_DU    = 50;
const int PREMIO_BICHO = 16;

int main()
{
  double v;
  int n, m;

  while (scanf("%lf %d %d", &v, &n, &m) != EOF && (v >= 0.01f || n || m))
  {
    int nm = (n / 1000) % 10;
    int nc = (n / 100) % 10;
    int nd = (n / 10) % 10;
    int nu = n % 10;

    int mm = (m / 1000) % 10;
    int mc = (m / 100) % 10;
    int md = (m / 10) % 10;
    int mu = m % 10;

    if (nm == mm && nc == mc && nd == md && nu == mu)
      printf("%.2lf\n", v * PREMIO_MCDU);
    else if (nc == mc && nd == md && nu == mu)
      printf("%.2lf\n", v * PREMIO_CDU);
    else if (nd == md && nu == mu)
      printf("%.2lf\n", v * PREMIO_DU);
    else
    {
      int b1 = ((10 * nd + nu + 99) % 100) / 4;
      int b2 = ((10 * md + mu + 99) % 100) / 4;

      if (b1 == b2)
        printf("%.2lf\n", v * PREMIO_BICHO);
      else
        printf("%.2lf\n", 0.0f);
    }
  }

  return 0;
}
