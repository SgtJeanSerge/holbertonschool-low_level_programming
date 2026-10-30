#include <stdio.h>

/**
 * main - Display option
 *
 * return: 0 (exit)
 */ 
int main(void)
{
  int nombre;

  printf("Simple calculator\n");
  printf("1) Add\n");
  printf("2) Substract\n");
  printf("3) Multiply\n");
  printf("4) Divide\n");
  printf("0) Quit\n");
  printf("Choice: ");
  scanf("%d", &nombre);
  
  if(nombre == 0)
  {
    printf("Bye!\n");
  }
  return (0);
}
