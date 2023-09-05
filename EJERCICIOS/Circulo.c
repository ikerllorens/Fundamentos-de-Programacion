#include <stdio.h>


/*
  

 */
int main(void)
{
  const int Pi = 3.14159;
  float diametro;
  float radio;
  float perimetro;
  float area;
  float volumen;


  printf("Dame el diámetro\n");
  scanf("%f", &diametro);

  radio = diametro/2;

  perimetro = Pi * diametro;

  area = Pi * radio * radio;

  volumen = (4/3)*Pi*radio*radio*radio;

  printf("Radio: %f\n", radio);
  printf("Perimetro: %f\n", perimetro);
  printf("Area: %f\n", area);
  printf("Volumen: %f\n", volumen);

  
  return 0;
}
