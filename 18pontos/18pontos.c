#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, m;
  int *p, *q;
  int aux = 0, pf = 0, count = 0;
  int belady0[3], belady1[3], disc = 0;

  belady0[0] = -1;

  scanf("%d", &n);

  p = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &p[i]);
  }
  do
  {
    pf = 0;
    count = 0;
    aux = 0;

    scanf("%d", &m);

    if (m == EOF)
    {
      break;
    }

    q = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
      aux = 0;
      for (int j = 0; j < m; j++)
      {
        if (q[j] == p[i])
        {
          aux = 1;
        }
      }

      if (aux == 0)
      {
        q[count] = p[i];
        count++;
        pf++;
        if (count >= m)
        {
          count = 0;
        }
      }
    }
    printf("%d\n", pf);
    // testando a partir daqui ^0 .. ~1
    if (belady0[0] == -1)
    {
      belady0[0] = m;
      belady0[1] = pf;
      belady1[0] = m;
      belady1[1] = pf;
    }
    else
    {
      belady1[0] = m;
      belady1[1] = pf;

      if (belady1[0] > belady0[0] && belady1[1] > belady0[1])
      {
        disc = 1;
      }

      else if (belady1[0] < belady0[0] && belady1[1] < belady0[1])
      {
        disc = 1;
      }

      if (belady0[0] > belady1[0])
      {
        belady0[0] = belady1[0];
        belady0[1] = belady1[1];
      }
    }

  } while (1);

  if (disc == 1)
  {
    printf("Belady detectado\n");
  }
  else
  {
    printf("Sem anomalia\n");
  }

  return 0;
}
