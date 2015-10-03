#include <bits/stdc++.h>
using namespace std;

int n, m, r;

int bx[2005], by[2005], bz[2005], br[2005];
int tx[15], ty[15], tz[15], tb[15];
int ex, ey, ez;

int bs[15][2005];
int bl[15];
double li[15];

double mli = 0.0;

void calcli(int l) {
  double etx = ex-tx[l];
  double ety = ey-ty[l];
  double etz = ez-tz[l];
  double et = etx*etx+ety*ety+etz*etz;

  li[l] = tb[l] / et;

  bl[l]=0;
  for (int i = 0; i < n; ++i) {
    bs[l][i]=0;

    double br2 = br[i]*br[i];

    double btx = bx[i]-tx[l];
    double bty = by[i]-ty[l];
    double btz = bz[i]-tz[l];
    double bt = btx*btx+bty*bty+btz*btz;

    double ebx = bx[i]-ex;
    double eby = by[i]-ey;
    double ebz = bz[i]-ez;
    double eb = ebx*ebx+eby*eby+ebz*ebz;

    if (bt <= br2 && eb <= br2) {
      continue;
    } else if (bt <= br2 || eb <= br2) {
      bs[l][i]=1;
      bl[l]++;
    } else {
      double k = btx*etx + bty*ety + btz*etz;
      k /= et;

      double px = etx*k,
             py = ety*k,
             pz = etz*k;
      double dp = px*px+py*py+pz*pz;

      double x = btx-px;
      double y = bty-py;
      double z = btz-pz;
      double d = x*x+y*y+z*z;

      double sp = etx*px+ety*py+etz*pz;

      if (d < br2 && sp >= 0 && dp <= et) {
        bs[l][i]=1;
        bl[l]++;
      }
    }
  }
}

void cs(int l, int rr) {
  if (rr - bl[l] < 0 || l == m) {
    double cli = 0.0;
    for (int i = 0; i < m; ++i) {
      if (bl[i] == 0)
        cli += li[i];
    }
    if (mli < cli) mli = cli;
    return;
  }

  vector<int> cbs[15];

  rr -= bl[l];
  for (int i = 0; i < n; ++i) {
    if (bs[l][i]) {
      for (int j = 0; j < m; ++j) {
        if (bs[j][i]) {
          bs[j][i]=0;
          bl[j]--;

          cbs[j].push_back(i);
        }
      }
    }
  }

  for (int i = l+1; i <= m; ++i) { cs(i, rr); }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < (int)cbs[i].size(); ++j) {
      bs[i][j]=1;
      bl[i]++;
    }
  }
  rr += bl[l];
}

int main() {
  while (scanf("%d%d%d", &n, &m, &r) && n && m && r) {
    for (int i = 0; i < n; ++i)
      scanf("%d%d%d%d", &bx[i], &by[i], &bz[i], &br[i]);
    for (int i = 0; i < m; ++i) {
      scanf("%d%d%d%d", &tx[i], &ty[i], &tz[i], &tb[i]);
    }
    scanf("%d%d%d", &ex, &ey, &ez);

    for (int i = 0; i < m; ++i)
      calcli(i);

    mli = 0.0;
    cs(0, r);
    printf("%f\n", mli);
  }

  return 0;
}
