# Documentación Doxygen

Este repositorio contiene código C completamente documentado en formato Doxygen.

## 📖 Sobre la Documentación

Todo el código fuente en este repositorio ha sido documentado siguiendo el estándar Doxygen, que incluye:

- **Descripciones de archivos**: Cada archivo `.c` y `.h` tiene un comentario de cabecera que describe su propósito
- **Documentación de funciones**: Todas las funciones incluyen:
  - Descripción breve (`@brief`)
  - Parámetros de entrada (`@param`)
  - Valores de retorno (`@return`)
  - Autor (`@author`)
- **Comentarios estructurados**: Uso de etiquetas Doxygen estándar

## 🔧 Generar la Documentación

### Instalar Doxygen

**Ubuntu/Debian:**
```bash
sudo apt-get install doxygen graphviz
```

**macOS:**
```bash
brew install doxygen graphviz
```

**Windows:**
Descargar desde [doxygen.nl](https://www.doxygen.nl/download.html)

### Generar HTML

Desde el directorio raíz del proyecto:

```bash
doxygen Doxyfile
```

Esto generará la documentación en el directorio `docs/html/`. Abre `docs/html/index.html` en tu navegador.

## 📂 Archivos Documentados

### Fundamentos/
- ✅ `EstructuraBasicaPrograma.c` - Estructura básica de un programa en C
- ✅ `Comentarios.c` - Ejemplos de comentarios y documentación
- ✅ `Tipos.c` - Tipos de datos en C
- ✅ `Enteros.c` - Límites de enteros y overflow
- ✅ `TiposEquivalencias.c` - Equivalencias entre tipos

### IO/
- ✅ `EjemploPrintf.c` - Uso de printf con diferentes tipos

### ARRAYS/
- ✅ `Arreglos101.c` - Introducción a arreglos
- ✅ `ArreglosYReferencias.c` - Relación entre arreglos y punteros

### POINTERS/
- ✅ `Pointers.c` - Conceptos básicos de punteros
- ✅ `ValoresPorReferencia.c` - Paso de parámetros por referencia
- ✅ `direcciones_memoria.c` - Direcciones de memoria y paso por valor vs referencia

### PROGRAM FLOW/
- ✅ `IfExample.c` - Uso de sentencias if

### MAKEFILE_EXAMPLE/
- ✅ `main.c` - Programa principal
- ✅ `suma.c` - Función de suma
- ✅ `resta.c` - Función de resta
- ✅ `biblioteca.h` - Declaraciones de funciones

### EJERCICIOS/
- ✅ `Circulo.c` - Cálculos de círculo y esfera
- ✅ `ABECEDARIO/Abecedario.c` - Imprime el abecedario
- ✅ `ABECEDARIO/abecedario_bad.c` - Código con errores intencionales
- ✅ `SIMON_DICE/simon_dice.c` - Juego de memoria

### TERMINATOR/
- ✅ `TheTerminator.c` - Herramienta de recolección de archivos
- ✅ `the_putter.c` - Herramienta de distribución de archivos

## 📋 Etiquetas Doxygen Utilizadas

- `@file` - Nombre del archivo
- `@brief` - Descripción breve
- `@author` - Autor del código
- `@param` - Descripción de parámetros
- `@return` - Descripción del valor de retorno

## 🎓 Ejemplos de Documentación

### Ejemplo de documentación de archivo:
```c
/**
 * @file ejemplo.c
 * @brief Descripción breve del archivo
 * @author Iker Llorens
 * 
 * Descripción detallada del propósito del archivo
 * y su funcionalidad.
 */
```

### Ejemplo de documentación de función:
```c
/**
 * @brief Suma dos números enteros
 * 
 * Esta función toma dos números enteros como entrada
 * y devuelve su suma.
 * 
 * @param a Primer número a sumar
 * @param b Segundo número a sumar
 * @return La suma de a y b
 */
int suma(int a, int b)
{
    return a + b;
}
```

## 📚 Referencias

- [Doxygen Manual](https://www.doxygen.nl/manual/)
- [Comandos Especiales de Doxygen](https://www.doxygen.nl/manual/commands.html)
- [Documentación para C](https://www.doxygen.nl/manual/docblocks.html)

---

**Nota**: La documentación Doxygen mejora la legibilidad del código y facilita la generación automática de manuales técnicos.
