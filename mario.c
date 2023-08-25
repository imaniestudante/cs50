#include <stdio.h>
#include <cs50.h>

int main(void)

{
  int h;
  {
    h = get_int("Heigth: ");
  }
  while (h < 1 || h > 1);
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < h; j++)
    {
      if(i + j < h - 1)

      {
        printf(" ");
      }
      else
      {
        printf("#");

    }
    printf("\n");
  }
}
}