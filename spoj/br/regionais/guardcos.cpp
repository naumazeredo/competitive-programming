#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int d, f, g;
  while (cin >> d >> f >> g)
  {
    bool possivel = false;
    if (f < g)
    {
      float vh = sqrt(g*g - f*f);
      float t = d / vh;
      if (t <= (12.0f / f))
        possivel = true;
    }

    cout << (possivel ? 'S' : 'N') << endl;
  }
}
