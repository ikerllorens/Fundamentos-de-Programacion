/**
 * @file Circulo.c
 * @brief Programa que calcula el radio, perímetro, área y volumen de un círculo/esfera
 * @author Iker Llorens
 * 
 * Este programa solicita al usuario el diámetro de un círculo y calcula:
 * - Radio
 * - Perímetro (circunferencia)
 * - Área del círculo
 * - Volumen de la esfera
 */

#include <stdio.h>

/**
 * @brief Función principal del programa
 * 
 * Solicita al usuario el diámetro de un círculo y calcula el radio,
 * perímetro, área y volumen. Muestra todos los resultados en pantalla.
 * 
 * @return 0 si el programa se ejecutó correctamente
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
