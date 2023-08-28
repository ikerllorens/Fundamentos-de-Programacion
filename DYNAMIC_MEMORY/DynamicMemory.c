#include <stdlib.h>
#include <stdio.h>
#include "DynamicMemory.h"


int* realloc_array(int* values,const unsigned int size);
int* malloc_array(const unsigned int size);


/**
 * @brief Creates New vector;
 * @params size of vecotr/array
 * @return Vector - new vector;
 **/
Vector newVector(const unsigned int size) {

  Vector newVec = malloc(sizeof(struct _Vector));

  if (newVec == NULL) {
    printf("Error en memoria\n");
    exit(EXIT_FAILURE);
  }

  newVec->size = size;

  if(newVec->size == 0) {
    newVec->size = 10;
  }

  newVec->numberValues = newVec->size;
  newVec->values = malloc_array(newVec->size);
  clearVector(newVec);
  
  if(newVec->values == NULL) {
    newVec = destroyVector(newVec);
    exit(EXIT_FAILURE);
  }

  return newVec;
}


/**
 * @brief  Insert a value in a especific index from the vector
 * @param Vector - Struct Vector
 * @param const unsigned int value - Value to insert
 * @param const unsigned int index Index you want to insert your value
 * @return void
 **/
void insert(Vector vec, const int value, const unsigned int index) {

  if(index >= vec->size) {

    vec->values = realloc_array(vec->values, vec->size * 2);
    if(vec->values == NULL) {
      vec = destroyVector(vec);
      exit(EXIT_FAILURE);
    } 

    vec->size *= 2;
    vec->numberValues += index - vec->numberValues;
  }

  vec->values[index] = value;
}


/**
 * @brief  Insert a value in the last element from the vector
 * @params Vector - Struct Vector
 * @return void
 **/
void push_back(Vector vec, const int value) {


  if(vec->size == vec->numberValues) {

    vec->values = realloc_array(vec->values, vec->size * 2);
    if(vec->values == NULL) {
      vec = destroyVector(vec);
      exit(EXIT_FAILURE);
    }
        
    vec->size *= 2;
    vec->numberValues++;
  }


  vec->values[vec->numberValues - 1] = value;
}


/**
 * @brief Removes the last element from the vector
 * @params Vector - Struct Vector
 * @return void
 **/
void pop_back(Vector vec) {

  vec->values = realloc_array(vec->values, vec->numberValues - 1);
  if(vec->values == NULL) {
      vec = destroyVector(vec);
      exit(EXIT_FAILURE);
  }

  vec->numberValues--;
  vec->size = vec->numberValues;
} 


/**
 * @brief Clearing all the calues from the vector by puting 0
 * @params Vector - Struct Vector
 * @return void
 **/
void clearVector(Vector vec) {
  
  for(int i = 0; i < vec->size; i++) {
    vec->values[i] = 0;
  }

  // Or using memSet
  // memset(vec->values, 0, sizeof(vec->values));
}


/**
 * @brief Destroy the vector and free memory
 * @params Vector vec -Strct Vector
 * @return Vector - Strcut Vector with values NULL
 **/
Vector destroyVector(Vector vec) {

  if(vec->values != NULL) {
    free(vec->values);
    vec->values = NULL;
  }


  
  vec->size = 0;
  vec->numberValues = 0;

  free(vec);
  vec = NULL;

  return vec;
}


/**
 * @brief Creates an array with malloc
 * @param size 
 * @return int* 
 */
int* malloc_array(const unsigned int size) {

  int* newArray = (int*) malloc(sizeof(int) * size);
  if (newArray == NULL) {
    printf("Error en memoria\n");
    return NULL;
  }

  return  newArray;
}

/**
 *@brief realloc size of an array wioth realloc
 * @param values 
 * @param size 
 * @return int* 
 */
int* realloc_array(int* values, const unsigned int size) {
  int* newArray = (int*) realloc(values, sizeof(int) * size);

  if(newArray == NULL) {
    printf("ERROR EN MEMORIA");
    return values;
  }

  return newArray;
}


/**
 * @brief Prints all the values from the vector
 * @params const Vector vec - Strcut Vector
 * @return void
 **/
void printVector(const Vector vec) {

  printf("\n\n[");

  for(int i = 0; i < vec->numberValues; i++) {

    if(i == vec->numberValues - 1) {
      
      printf(" %d ]\n\n", vec->values[i]);
    }else {
      printf(" %d,", vec->values[i]);
    }
  }
}
