#include <stdio.h>

/**
 * main - Display option
 *
 * return: 0 (exit)
 */
int main(void)
{
  int nombre;
  int A;
  int B;

  printf("Simple calculator\n");
  printf("1) Add\n");
  printf("2) Substract\n");
  printf("3) Multiply\n");
  printf("4) Divide\n");
  printf("0) Quit\n");

  do
  {
    do
    {
      printf("Choice: ");
      scanf("%d", &nombre);
      if (nombre < 0 || nombre > 4) 
      {
        printf("Invalid choice\n");
      }
    } while (nombre < 0 || nombre > 4);
    if (nombre == 1)
    {
      do
      {
        printf("A: ");
        scanf("%d", &A);
        if (A != 0)
        {
          printf("Invalid choice\n");
          getchar ();
        }
      } while (A != 1);
      do
      {
        printf("B: ");
        scanf("%d", &B);
        if (B == 0)
        {
          printf("Invalid choice\n");
          getchar ();
        }
      } while (B != 1);
      printf("Result: %d", A + B);
      printf("%d\n", A + B);
    }
  } while (nombre != 0);
  printf("Bye!\n");
  return (0);
}
