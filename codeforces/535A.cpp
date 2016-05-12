#include <cstdio>
#include <string>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  string decimal = "",
         unit = "";

  if (n % 10 == 0)
    unit = "zero";
  else if (n % 10 == 1)
    unit = "one";
  else if (n % 10 == 2)
    unit = "two";
  else if (n % 10 == 3)
    unit = "three";
  else if (n % 10 == 4)
    unit = "four";
  else if (n % 10 == 5)
    unit = "five";
  else if (n % 10 == 6)
    unit = "six";
  else if (n % 10 == 7)
    unit = "seven";
  else if (n % 10 == 8)
    unit = "eight";
  else if (n % 10 == 9)
    unit = "nine";

  if (n / 10 == 2)
    decimal = "twenty";
  else if (n / 10 == 3)
    decimal = "thirty";
  else if (n / 10 == 4)
    decimal = "forty";
  else if (n / 10 == 5)
    decimal = "fifty";
  else if (n / 10 == 6)
    decimal = "sixty";
  else if (n / 10 == 7)
    decimal = "seventy";
  else if (n / 10 == 8)
    decimal = "eighty";
  else if (n / 10 == 9)
    decimal = "ninety";

  if (n < 10)
    printf("%s\n", unit.c_str());
  else if (n == 10)
    printf("ten\n");
  else if (n == 11)
    printf("eleven\n");
  else if (n == 12)
    printf("twelve\n");
  else if (n == 13)
    printf("thirteen\n");
  else if (n == 14)
    printf("fourteen\n");
  else if (n == 15)
    printf("fifteen\n");
  else if (n == 16)
    printf("sixteen\n");
  else if (n == 17)
    printf("seventeen\n");
  else if (n == 18)
    printf("eighteen\n");
  else if (n == 19)
    printf("nineteen\n");
  else if (n % 10 == 0)
    printf("%s\n", decimal.c_str());
  else
    printf("%s-%s\n", decimal.c_str(), unit.c_str());

  return 0;
}
