# 📖 Fundamentos de Programación en C

Esta carpeta contiene los ejemplos fundamentales para aprender programación en lenguaje C. Cada archivo está diseñado para enseñar conceptos específicos de manera práctica y con comentarios detallados.

## 🔧 ¿Qué es un Compilador?

Antes de empezar con los ejemplos, es importante entender qué es un **compilador** y por qué lo necesitamos:

### Definición
Un **compilador** es un programa que traduce código fuente escrito en un lenguaje de programación (como C) a código máquina que el procesador puede ejecutar directamente.

### ¿Por qué necesitamos un compilador?
- **Los procesadores no entienden C**: Solo entienden instrucciones en código máquina (0s y 1s)
- **Traducción necesaria**: El compilador convierte nuestro código legible en instrucciones que la máquina puede ejecutar
- **Verificación de errores**: Durante la compilación, el compilador detecta errores de sintaxis y algunos errores lógicos

### El proceso de compilación en C:
1. **Código fuente** (archivo `.c`) → Escribes tu programa
2. **Compilador** (`gcc`) → Traduce el código
3. **Archivo ejecutable** → Programa que puedes ejecutar

### Ejemplo práctico:
```bash
# Tienes un archivo: programa.c
# Compilas con: gcc -o programa programa.c
# Ejecutas con: ./programa
```

### GCC - Nuestro Compilador
En estos ejemplos usamos **GCC** (GNU Compiler Collection):
- Es gratuito y ampliamente utilizado
- Viene incluido en la mayoría de sistemas Linux/Mac
- Para Windows, se puede instalar a través de MinGW o similar

**Recuerda**: Sin compilador, tu código C es solo texto. ¡El compilador lo convierte en un programa funcional!

## 📚 Contenido de los Ejemplos

### 1. EstructuraBasicaPrograma.c
**Concepto principal**: Estructura básica de un programa en C

**Lo que aprenderás**:
- Directivas del preprocesador (`#include`)
- Declaración de funciones
- Función principal `main()`
- Declaración de variables
- Uso de funciones de entrada y salida (`printf`, `scanf`)
- Llamadas a funciones definidas por el usuario
- Valor de retorno de la función `main`

**Funciones que incluye**:
- `Suma()`: Función que suma dos números enteros
- `Resta()`: Función que resta dos números enteros

**Ejemplo de compilación**:
```bash
gcc -o estructura EstructuraBasicaPrograma.c
./estructura
```

### 2. Comentarios.c
**Concepto principal**: Documentación y comentarios en código C

**Lo que aprenderás**:
- Comentarios de una sola línea (`//`)
- Comentarios de múltiples líneas (`/* */`)
- Documentación de funciones con formato estándar
- Buenas prácticas de documentación
- Diferentes estilos de comentarios

**Funciones que incluye**:
- `Cuadrado()`: Calcula el cuadrado de un número
- Ejemplos de documentación con parámetros y valores de retorno

**Ejemplo de compilación**:
```bash
gcc -o comentarios Comentarios.c
./comentarios
```

### 3. Tipos.c
**Concepto principal**: Tipos de datos en C

**Lo que aprenderás**:
- Tipos básicos: `int`, `char`, `float`
- Arreglos de caracteres (strings)
- Punteros básicos (`int*`)
- Arreglos (`int[5]`)
- Definición de tipos personalizados (`typedef`)
- Concepto de `void`
- Gestión de memoria y direcciones

**Tipos que se ejemplifican**:
- Enteros (`int`)
- Caracteres (`char`)
- Arreglos de caracteres
- Números de punto flotante (`float`)
- Punteros (`int*`, `NULL`)
- Tipos personalizados (`typedef`)

**Ejemplo de compilación**:
```bash
gcc -o tipos Tipos.c
./tipos
```

### 4. Enteros.c
**Concepto principal**: Límites y comportamiento de enteros

**Lo que aprenderás**:
- Límites de los tipos enteros en C
- Desbordamiento de enteros (integer overflow)
- Comportamiento de bucles infinitos
- Estructuras de control básicas (`while`)
- Operadores de incremento (`+=`)

**Experimento incluido**:
- Bucle que incrementa un entero hasta alcanzar el límite del tipo
- Demostración práctica del desbordamiento de enteros

**Ejemplo de compilación**:
```bash
gcc -o enteros Enteros.c
./enteros
```

### 5. TiposEquivalencias.c
**Concepto principal**: Equivalencias entre tipos de datos

**Lo que aprenderás**:
- Relación entre caracteres y números (tabla ASCII)
- Representación de caracteres en diferentes bases (decimal, hexadecimal)
- Operaciones aritméticas con caracteres
- Conversión entre mayúsculas y minúsculas
- Estructuras condicionales (`if`)

**Conceptos demostrados**:
- Diferencia entre `'a'` y `'A'` (32 posiciones en ASCII)
- Asignación de valores decimales a variables `char`
- Asignación de valores hexadecimales a variables `char`
- Operaciones matemáticas con caracteres

**Ejemplo de compilación**:
```bash
gcc -o equivalencias TiposEquivalencias.c
./equivalencias
```

## 🚀 Cómo usar estos ejemplos

### Orden de estudio recomendado:
1. **EstructuraBasicaPrograma.c** - Comienza aquí para entender la estructura básica
2. **Comentarios.c** - Aprende a documentar tu código apropiadamente
3. **Tipos.c** - Comprende los diferentes tipos de datos disponibles
4. **TiposEquivalencias.c** - Entiende las relaciones entre tipos
5. **Enteros.c** - Explora los límites y comportamiento de los enteros

### Compilación general:
Para compilar cualquier archivo de ejemplo:
```bash
gcc -o nombre_programa archivo.c
./nombre_programa
```

### Experimentación:
- **Modifica los valores**: Cambia los números y caracteres en los programas
- **Agrega impresiones**: Usa `printf()` para ver valores intermedios
- **Comenta y descomenta**: Prueba diferentes secciones del código
- **Combina conceptos**: Intenta crear nuevos programas usando múltiples conceptos

## 💡 Consejos de aprendizaje

1. **Lee todos los comentarios**: Cada archivo tiene explicaciones detalladas
2. **Compila y ejecuta**: No solo leas el código, ejecútalo
3. **Experimenta**: Modifica los valores y observa los cambios
4. **Pregunta**: Si algo no está claro, investiga más sobre el concepto
5. **Practica**: Intenta escribir programas similares desde cero

## 🔍 Conceptos clave cubiertos

- ✅ Estructura básica de programas en C
- ✅ Directivas del preprocesador
- ✅ Función main() y valor de retorno
- ✅ Declaración y uso de variables
- ✅ Tipos de datos fundamentales
- ✅ Funciones definidas por el usuario
- ✅ Entrada y salida básica
- ✅ Documentación y comentarios
- ✅ Punteros básicos
- ✅ Arreglos básicos
- ✅ Operaciones con caracteres
- ✅ Límites de tipos de datos

---

**Recuerda**: La programación se aprende practicando. ¡Compila, ejecuta y experimenta con estos ejemplos!