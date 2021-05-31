#include <stdio.h>

int main (int argc, char *argv[])
{
  int res = 0;

  for (int i = 1; i < argc; i++)
    for (char *ch = argv[i]; *ch != '\0'; ch++)
      res ^= *ch;

  printf ("xor of all strings: %d\n", res);
  return 0;
}
