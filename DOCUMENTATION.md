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

### Generar Documentación

Desde el directorio raíz del proyecto:

```bash
doxygen Doxyfile
```

Esto generará la documentación en dos formatos:
- **HTML**: `docs/html/index.html` - Abre este archivo en tu navegador para documentación interactiva
- **XML**: `docs/xml/` - Archivos XML estructurados que pueden ser procesados por otras herramientas

### Formatos de Salida Disponibles

El archivo `Doxyfile` está configurado para generar:
1. **HTML** - Documentación navegable en el navegador web
2. **XML** - Formato estructurado para integración con otras herramientas (IDEs, sistemas de documentación, etc.)

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
- ✅ `ejemplo_xml_doc.c` - Ejemplo de documentación con formato XML

### EJERCICIOS/
- ✅ `Circulo.c` - Cálculos de círculo y esfera
- ✅ `ABECEDARIO/Abecedario.c` - Imprime el abecedario
- ✅ `ABECEDARIO/abecedario_bad.c` - Código con errores intencionales
- ✅ `SIMON_DICE/simon_dice.c` - Juego de memoria

### TOOLS/
- ✅ `calificacion.c` - Herramienta de recolección de archivos
- ✅ `the_putter.c` - Herramienta de distribución de archivos

## 📋 Etiquetas Doxygen Utilizadas

Este repositorio utiliza el formato XML para la documentación Doxygen:

### Formato XML (Usado en el repositorio)
- `<file>...</file>` - Nombre del archivo
- `<brief>...</brief>` - Descripción breve
- `<author>...</author>` - Autor del código
- `<param name="nombre">...</param>` - Descripción de parámetros
- `<return>...</return>` - Descripción del valor de retorno

### Formato @ (Alternativo)
Doxygen también soporta el formato con @ (por ejemplo: `@file`, `@brief`, `@param`, `@return`), pero este repositorio usa consistentemente el formato XML para mantener uniformidad.

## 🎓 Ejemplos de Documentación

### Ejemplo de documentación de archivo (Formato XML):
```c
/**
 * <file>ejemplo.c</file>
 * <brief>Descripción breve del archivo</brief>
 * <author>Iker Llorens</author>
 * 
 * Descripción detallada del propósito del archivo
 * y su funcionalidad.
 */
```

### Ejemplo de documentación de función (Formato XML):
```c
/**
 * <brief>Suma dos números enteros</brief>
 * 
 * Esta función toma dos números enteros como entrada
 * y devuelve su suma.
 * 
 * <param name="a">Primer número a sumar</param>
 * <param name="b">Segundo número a sumar</param>
 * <return>La suma de a y b</return>
 */
int suma(int a, int b)
{
    return a + b;
}
```

**Nota**: Todo el código en este repositorio utiliza consistentemente el formato XML de Doxygen. El formato XML proporciona una estructura clara y es familiar para desarrolladores con experiencia en XML.

## 📚 Referencias

- [Doxygen Manual](https://www.doxygen.nl/manual/)
- [Comandos Especiales de Doxygen](https://www.doxygen.nl/manual/commands.html)
- [Documentación para C](https://www.doxygen.nl/manual/docblocks.html)

---

**Nota**: La documentación Doxygen mejora la legibilidad del código y facilita la generación automática de manuales técnicos.
