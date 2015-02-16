#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

struct Point
{
  double x, y;
};

struct Line
{
  Line() {}
  Line(Point a, Point b) : f(a), l(b) {}

  double magnitude()
  {
    double dx = l.x - f.x,
           dy = l.y - f.y;
    return std::sqrt(dx * dx + dy * dy);
  }

  Point f, l;
};

std::vector<double> allRoutes(Point q, Point p,
                              std::vector<Point> teles,
                              bool teleEdges[50][50],
                              int teleLeft,
                              std::vector<Line> murais);
double minDistance(Point p1, Point p2, std::vector<Line> murais);
bool intersects(const Line& l1, const Line& l2, Point* p = NULL);

int main()
{
  Point q, p;

  int teleLeft;
  int c;
  std::vector<Point> teles;
  bool teleEdges[50][50];

  int m;
  std::vector<Line> murais;

  std::vector<double> distances;

  //while (std::cin >> teleLeft >> m >> c)
  while (scanf("%d%d%d", &teleLeft, &m, &c) != EOF)
  {
    // Input
    murais.resize(m);
    for (int i = 0; i < m; ++i)
      std::cin >> murais[i].f.x >> murais[i].f.y >>
                  murais[i].l.x >> murais[i].l.y;

    teles.resize(c);
    for (int i = 0; i < c; ++i)
      std::cin >> teles[i].x >> teles[i].y;

    std::cin >> q.x >> q.y >> p.x >> p.y;

    // Teleport edges
    for (int i = 0; i < c; ++i)
      teleEdges[i][i] = false;

    for (int i = 0; i < c; ++i)
    {
      for (int j = i + 1; j < c; ++j)
      {
        bool isfree = true;
        for (int k = 0; k < m; ++k)
        {
          Point p;
          if (intersects(Line(teles[i], teles[j]), murais[k], &p))
          {
            teleEdges[i][j] = false;
            teleEdges[j][i] = false;
            isfree = false;
            break;
          }
        }

        if (isfree)
        {
          teleEdges[i][j] = true;
          teleEdges[j][i] = true;
        }
      }
    }

    std::vector<double> distances = allRoutes(
      q, p, teles, teleEdges, teleLeft, murais
    );

    std::sort(distances.begin(), distances.end());

    printf("%.1f\n", distances[0]);
  }

  return 0;
}

std::vector<double> allRoutes(Point q, Point p,
                              std::vector<Point> teles,
                              bool teleEdges[50][50],
                              int teleLeft,
                              std::vector<Line> murais)
{
  std::vector<double> distances;

  // Straight to finish
  distances.push_back(minDistance(q, p, murais));

  if (teleLeft > 0)
  {
    for (int i = 0; i < teles.size(); ++i)
    {
      double distToTele = minDistance(q, teles[i], murais);
      for (int j = 0; j < teles.size(); ++j)
      {
        if (teleEdges[i][j])
        {
          std::vector<double> routes = allRoutes(
            teles[j], p, teles, teleEdges, teleLeft - 1, murais
          );

          for (int k = 0; k < routes.size(); ++k)
          {
            distances.push_back(distToTele + routes[k]);
          }
        }
      }
    }
  }

  return distances;
}

double minDistance(Point p1, Point p2, std::vector<Line> murais)
{
  int closest = -1;
  double minDist = -1.0;
  for (int i = 0; i < murais.size(); ++i)
  {
    Point p;
    if (intersects(Line(p1, p2), murais[i], &p))
    {
      double dist = Line(p1, p).magnitude();
      if (minDist < 0.0 || minDist > dist)
      {
        minDist = dist;
        closest = i;
      }
    }
  }

  if (closest >= 0)
  {
    murais.erase(murais.begin() + closest);
    double dist1 = minDistance(p1, murais[closest].f, murais) +
                   minDistance(murais[closest].f, p2, murais);
    double dist2 = minDistance(p1, murais[closest].l, murais) +
                   minDistance(murais[closest].l, p2, murais);
    return std::min(dist1, dist2);
  }

  return Line(p1, p2).magnitude();
}

bool intersects(const Line& l1, const Line& l2, Point* p)
{
  double a1, b1, c1,
         a2, b2, c2;

  a1 = l1.l.y - l1.f.y;
  b1 = l1.f.x - l1.l.x;
  c1 = a1 * l1.f.x + b1 * l1.f.y;

  a2 = l2.l.y - l2.f.y;
  b2 = l2.f.x - l2.l.x;
  c2 = a2 * l2.f.x + b2 * l2.f.y;

  double det = a1 * b2 - a2 * b1;
  if (std::abs(det) < 0.000001)
  {
    return false;
  }
  else
  {
    double x = (b2 * c1 - b1 * c2) / det;
    double y = (a1 * c2 - a2 * c1) / det;
    if (p != NULL)  // nullptr?
      p->x = x, p->y = y;

    if (x < std::min(l1.f.x, l1.l.x) ||
        x > std::max(l1.f.x, l1.l.x) ||
        y < std::min(l1.f.y, l1.l.y) ||
        y > std::max(l1.f.y, l1.l.y) ||
        x < std::min(l2.f.x, l2.l.x) ||
        x > std::max(l2.f.x, l2.l.x) ||
        y < std::min(l2.f.y, l2.l.y) ||
        y > std::max(l2.f.y, l2.l.y))
      return false;
    return true;
  }
}
