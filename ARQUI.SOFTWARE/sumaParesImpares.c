/**
* @author  Eder Garcia Lastiri
* Programa que obtiene la suma de todos los numeros pares entre 1 y 200 
* y de todos los impares entre 1 y 200
*/

#include <stdio.h>
//Declaracion de funciones
void sumarPares (int sumap, int i);
void sumarImpares (int sumai, int i);

int main (void){
//Declaracion de variables
  int sumap, i, sumai;
//Llamada de funciones
  sumarPares (sumap, i);
  sumarImpares (sumai, i);
}

//Funcion sumarPares
//Suma todos los numeros pares entre 1 y 200
//Parámetros: sumap, resultado de la suma
//            i, contador del ciclo
//Regresa: void
//
void sumarPares (int sumap, int i){
  sumap=0;//Inciar contador
  //Ciclo para recorrer los numeros del 1 al 200
  for(i=1;i<=200;i++){
    if(i%2==0){//Determinar si es par
      sumap=sumap+i;//Agregar a la suma
    }
  }
  printf("La suma de los numeros pares entre 1 y 200 es: %d\n", sumap);//Imprimir resultado en pantalla
}

//Funcion sumarImares
//Suma todos los numeros impares entre 1 y 200
//Parámetros: sumai, resultado de la suma
//            i, contador del ciclo
//Regresa: void
//
void sumarImpares (int sumai, int i){
  sumai=0; //Inciar contador
  //Ciclo para recorrer los numeros del 1 al 200
  for(i=1;i<=200;i++){
    if(i%2!=0){ //Determinar si es impar
      sumai=sumai+i; //Agregar a la suma
    }
  }
  printf("La suma de los numeros impares entre 1 y 200 es: %d\n", sumai);//Imprimir resultado en pantalla
}
