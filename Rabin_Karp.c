#include <stdio.h>
#include <string.h>
#include <math.h>
#define d 10

int main()
{
  char text[] = "ccaccaacdba";
  char pattern[] = "dba";
  int q = 13;

  printf("\nRabin Karp Algorithm\n\nText String: ccaccaacdba \n\nPattern String: dba");

  int m = strlen(pattern);
  int n = strlen(text);
  int i, j, s;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i=0; i<(m-1); i++)
  {  h = (h*d)%q;       }

  for (i=0; i<m; i++)
  {
    p = (d*p + pattern[i])%q;
    t = (d*t + text[i])%q;
  }

  for (s=0; s<=(n-m); s++)
  {
    if (p==t)
    {
      for (j=0; j<m;j++)
      {
        if (text[s + j] != pattern[j])
        { break; }
      }

      if (j==m)
      {  printf("\n\nPattern found at index: %d\n", s);  }
    }

    if(s<n-m)
    {
      t=(d*(t-text[s]*h) + text[s+m])%q;

      if(t<0)
      { t = (t+q); }
    }
  }

    return 0;
}
