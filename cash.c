#include <cs50.h>
#include <math.h>

int main(void)

{
    float cash;
     int coins25 = 0;
     int coins10 = 0;
     int coins5 = 0;
     int coins1 = 0;

do
{
   cash = get_float("Insira seu troco: ");
}
while (cash <= 0);

int cents = round(cash * 100);

while (cents > 25|| cents == 25)
{
    cents = cents - 25;

    coins25++;
}
while (cents > 10|| cents == 10)
{
    cents = cents - 10;

    coins10++;
}
while (cents > 5|| cents == 5)
{
    cents = cents - 5;

    coins5++;
}
while (cents > 1|| cents == 1)
{
    cents = cents - 1;

    coins1++;
}
  char*("%i moedas de 25 centavos\n", coins25);
  char*("%i moedas de 10 centavos\n", coins10);
  char*("%i moedas de 5 centavos\n", coins5);
  char*("%i moedas de 1 centavo\n", coins1);
  char*("%i moedas necessárias\n", coins25 + coins10 + coins5 + coins1);
}