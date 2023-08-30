/*Practica 28 Punteros por referencia
  Fundamentos de Programacion
  Emiliano Lecourtois Pérez
  10-11-20*/

  /*Programa que ayuda a determinar en que rango se encuentra el
  numero ingresado por el usuario */

#include<stdio.h>
#include<stdlib.h>
//Prototipos de las funciones
void Pedir(int Arreglo[],int n);
void Rango(int Arreglo[],int n,int *prv,int *sev,int *tev,int *otro);
int main(){
  int n;//Variable para tamaño de arreglo
  int *Arr; //Arreglo
  int pv=0,sv=0,tv=0,ot=0; //Variables para determinar el numero de valores
  //Pedir tamaño del arreglo
  printf("Ingresa numero de valores: ");
  scanf("%i",&n);

  //Reservar espacio para el arreglo
  for(int i=0;i<n;i++)
    Arr=(int *)malloc(n * sizeof(int));
  //Funciones
  Pedir(Arr,n);
  Rango(Arr,n,&pv,&sv,&tv,&ot);

  //Imprimir rangos
  printf("Valores entre 20-30: %i\n",pv);
  printf("Valores entre 31-50: %i\n",sv);
  printf("Valores entre 51-70: %i\n",tv);
  printf("Otros: %i\n",ot);
}//Fin main

//Funcion para pedir valores
void Pedir(int e[],int l){
  int i;
  for(i=0;i<l;i++){
    printf("x[%i]: ",i);
    scanf("%i",(e+i));
  }
}

//Funcion para Determinar el rango en el que se encuentra el numero
void Rango(int e[],int l,int *pv, int *sv, int *tv,int *o){
  int i=0;
  while(i<l){
    if(*(e+i)>=20 && *(e+i)<=30)
      ++ *pv;
      else if(*(e+i)>30 && *(e+i)<=50)
	++ *sv;
	else if(*(e+i)>50 && *(e+i)<=70)
	   ++ *tv;
	  else
	    ++ *o;
    i++;
  }
}