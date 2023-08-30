/**
* @author  Juan Carlos Rosales Alvarez
* Programa que suma un día a la fecha que se ingrese
* tomando en cuenta todas las variables posibles
* como por ejemplo si es año bisiesto
*/

#include <stdio.h>

//funciones
void ConseguirFecha (int *dd, int *mm, int *aa);
void Sumar (int dd, int mm, int aa, int dia, int mes, int anho);

//funcion principal
int main (void)
{
  //variables
  int dd, mm, aa, dia, mes, anho;
  //llamado de funciones
  ConseguirFecha (&dd, &mm, &aa);
  Sumar (dd, mm, aa, dia, mes, anho);
}

//funcion que pregunta por las fechas
void ConseguirFecha(int *dd, int *mm, int *aa)
{
  printf("Introduzca una fecha con el formato DD MM AA:\n");
  scanf ("%d %d %d", dd, mm, aa);
}


//funcion que suma un dia tomando en cuenta todas las posibles variables
void Sumar (int dd, int mm, int aa, int dia, int mes, int anho)
{
  if ((((dd<32)&&((dd!=31)||(dd!=30)))&&((mm==1)||(mm==3)||(mm==5)||(mm==7)||(mm==8)||(mm==10)))){
  int dia1=dd+1;
  int mes1= mm;
  int anho1=aa;
  printf("El siguiente dia es: %d %d %d\n", dia1, mes1, anho1);
  }

else {
  if ((((dd<31)&&((dd!=31)||(dd!=30)))&&((mm==4)||(mm==6)||(mm==9)||(mm==11)))){
  int dia1=dd+1;
  int mes1= mm;
  int anho1=aa;
  printf("El siguiente dia es: %d %d %d\n", dia1, mes1, anho1);
  }

else {
  if ((dd<29)&&(dd!=28)&&(mm==02)){
  int dia1=dd+1;
  int mes1= mm;
  int anho1=aa;
  printf("El siguiente dia es: %d %d %d\n", dia1, mes1, anho1);
  }

  else {

  if ((dd==31)&& ((mm==1)||(mm==3)||(mm==5)||(mm==7)||(mm==8)||(mm==10) ) )
  {
    mes=mm+1;
    dia=1;
    anho=aa;
    printf("El siguiente dia es: %d %d %d\n", dia, mes, anho);
  }

else {
    if ((dd==30)&&((mm==4)||(mm==6)||(mm==9)||(mm==11)))
    {
      mes=mm+1;
      dia=01;
      anho=aa;
      printf("El siguiente dia es: %d %d %d\n", dia, mes, anho);
}


else {
    if ((dd==31)&&(mm==12))
    {
      mes=01;
      dia=01;
      anho=aa+1;
      printf("El siguiente dia es: %d %d %d\n", dia, mes, anho);
  }

else {
  if ((aa%4==0)&&(dd==28)&&(mm=2))
  {
    mes=02;
    dia=29;
    anho=aa;
    printf("El siguiente dia es: %d %d %d\n", dia, mes, anho);
}

else {
if ((dd==28)&&(mm=2))
{
  mes=03;
  dia=01;
  anho=aa;
  printf("El siguiente dia es: %d %d %d\n", dia, mes, anho);
 }

 else {
   if((dd==29)&&(mm==2)&&(aa%4==0)){
     mes=03;
     dia=01;
     anho=aa;
     printf("El siguiente dia es: %d %d %d\n", dia, mes, anho);
   }

else {
  if ((dd>=32)||(mm>=13)){
  printf("La fecha es invalida\n");
  }

  else {
    if ((dd>=32)&& ((mm==1)||(mm==3)||(mm==5)||(mm==7)||(mm==8)||(mm==10)))
  {
    printf("La fecha es invalida\n");
  }

else {
    if ((dd>=31)&&((mm==4)||(mm==6)||(mm==9)||(mm==11)))
    {
      printf("La fecha es invalida\n");
    }

else {
  if ((dd>=29)&&(mm==2)&&(aa%4!=0))
    {
      printf("La fecha es invalida\n");
    }
else {
  if ((dd>=30)&&(mm==2)&&(aa%4==0))
    {
      printf("La fecha es invalida\n");
    }

}
}
}
}
}
}
}
}
}
}
}
}
}
}
