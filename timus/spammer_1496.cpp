#include <cstdio>
#include <map>
#include <string>
using namespace std;

map<string, int> user;

int main()
{
  int n;
  scanf("%d", &n);

  char buffer[64];
  for (int i = 0; i < n; ++i)
  {
    scanf("%s", buffer);
    if (user.find(buffer) != user.end())
      user[buffer]++;
    else
      user[buffer] = 1;
  }

  for (map<string, int>::iterator it = user.begin();
       it != user.end();
       ++it)
    if (it->second > 1)
      printf("%s\n", it->first.c_str());

  return 0;
}
