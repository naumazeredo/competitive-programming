#include <bits/stdc++.h>
using namespace std;

int main() {
  long double PI=3.14159;
  long double g=9.80665;
  int p1,p2,n;
  long double h,vel,angulo,rad,alcance;
  while (scanf("%Lf",&h) != EOF) {
    scanf("%d%d%d",&p1,&p2, &n);

    while (n--) {
      scanf("%Lf%Lf",&angulo,&vel);

      rad = angulo * PI/180.0;
      long double vx = vel*cos(rad);
      long double vy = vel*sin(rad);
      long double t = vy + sqrt(vy*vy + 2*g*h);
      alcance = t * vx / g;

      if (alcance < p2 + 1e-9 && alcance > p1 - 1e-9)
        printf("%.5Lf -> DUCK\n",alcance);
      else
        printf("%.5Lf -> NUCK\n",alcance);
    }
  }
}
