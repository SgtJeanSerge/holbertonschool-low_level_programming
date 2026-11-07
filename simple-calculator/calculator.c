#include <stdio.h>

/**
 * read_number - loop until the right input 
 * @prompt: text displayed before the input
 *
 * Return: the number typed by the user
 */
int read_number(char *prompt)
{
  int n;
  int ok;
  
  do
  {
    printf("%s", prompt);
    ok = scanf("%d", &n);
    if (ok == 1 && getchar() == '\n')
    {
      return (n);
    }
    else
    {
      printf("Only digit accepted\n");
      while (getchar() != '\n')
      {
        ;
      }
    }
  } while (1);
}

/**
 * main - Menu option
 *
 * return: 0 (exit)
 */
int main(void)
{
  int nombre;
  int A;
  int B;

  do
  {
    printf("Simple calculator\n");
    printf("1) Add\n");
    printf("2) Substract\n");
    printf("3) Multiply\n");
    printf("4) Divide\n");
    printf("0) Quit\n");
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
      A = read_number("A: ");
      B = read_number("B: ");
      printf("\033[4mResult\033[0m: \033[1;32m%d\033[0m\n\n", A + B);
    }
    if (nombre == 2)
    {
      A = read_number("A: ");
      B = read_number("B: ");
      printf("\033[4mResult\033[0m: \033[1;32m%d\033[0m\n\n", A - B);
    }
    if (nombre == 3)
    {
      A = read_number("A: ");
      B = read_number("B: ");
      printf("\033[4mResult\033[0m: \033[1;32m%d\033[0m\n\n", A * B);
    }
    if (nombre == 4)
    {
      A = read_number("A: ");
      B = read_number("B: ");
      printf("\033[4mResult\033[0m: \033[1;32m%d\033[0m\n\n", A / B);
    }
  } while (nombre != 0);
  printf("Bye!\n");
  return (0);
}
