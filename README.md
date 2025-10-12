# Fundamentos de Programación

[![Build and Test All Programs](https://github.com/ikerllorens/Fundamentos-de-Programacion/actions/workflows/build-and-test.yml/badge.svg)](https://github.com/ikerllorens/Fundamentos-de-Programacion/actions/workflows/build-and-test.yml)

Este repositorio contiene ejemplos prácticos y ejercicios para aprender los **Fundamentos de Programación** en lenguaje C. Está diseñado específicamente para estudiantes principiantes que están dando sus primeros pasos en el mundo de la programación.

## 🎯 Objetivo

El objetivo de este repositorio es proporcionar una colección organizada de ejemplos de código, ejercicios prácticos y recursos que cubren los conceptos fundamentales de la programación en C, desde lo más básico hasta conceptos intermedios.

## 👥 ¿A quién está dirigido?

- **Estudiantes principiantes** que están aprendiendo su primer lenguaje de programación
- **Estudiantes de ingeniería** en cursos introductorios de programación
- **Autodidactas** que quieren aprender programación en C de forma estructurada
- **Cualquier persona** interesada en entender los fundamentos de la programación

## 📚 Contenido del Repositorio

### Orden del temario

1) **Fundamentos** - Conceptos fundamentales
2) **IO** - Entrada y salida de datos
3) **ARRAYS** - Arreglos y manejo de datos
4) **POINTERS** - Punteros y referencias
5) **PROGRAM FLOW** - Control de flujo
6) **MAKEFILE_EXAMPLE** - Compilación avanzada
7) **EJERCICIOS** - Ejercicios prácticos
8) **TOOLS** - Herramientas auxiliares

### Descripción de cada sección

#### 📖 Fundamentos
Conceptos fundamentales de programación en C:
- Estructura básica de un programa
- Tipos de datos (enteros, caracteres, flotantes)
- Comentarios y documentación
- Declaración de variables

#### 🔄 IO (Input/Output)
Manejo de entrada y salida de datos:
- Función `printf()` para mostrar información
- Función `scanf()` para recibir datos del usuario
- Caracteres individuales con `getchar()` y `putchar()`

#### 📊 ARRAYS
Trabajo con arreglos y estructuras de datos:
- Declaración e inicialización de arreglos
- Acceso a elementos
- Relación entre arreglos y punteros

#### 👉 POINTERS
Conceptos de punteros y referencias:
- Declaración y uso de punteros
- Paso de parámetros por referencia
- Relación entre punteros y arreglos

#### 🌊 PROGRAM FLOW
Control de flujo del programa:
- Estructuras condicionales (`if`, `else`)
- Bucles (`while`, `for`)
- Toma de decisiones en el programa

#### 🔧 MAKEFILE_EXAMPLE
Compilación y manejo de proyectos:
- Uso de Makefiles
- Compilación de múltiples archivos
- Organización de proyectos grandes

#### 💪 EJERCICIOS
Ejercicios prácticos para reforzar el aprendizaje:
- **ABECEDARIO**: Ejercicios con caracteres y strings
- **SIMON_DICE**: Juego interactivo
- **Circulo**: Cálculos matemáticos

## 🚀 Cómo empezar

### Prerrequisitos
- Un compilador de C (recomendado: GCC)
- Un editor de texto o IDE
- Terminal o línea de comandos

### Pasos para comenzar

1. **Clona o descarga** este repositorio en tu computadora
2. **Comienza con Fundamentos**: Explora los archivos en la carpeta `Fundamentos/` para entender la estructura básica
3. **Compila tu primer programa**:
   ```bash
   gcc -o mi_programa Fundamentos/EstructuraBasicaPrograma.c
   ./mi_programa
   ```
4. **Sigue el orden sugerido** del temario para un aprendizaje progresivo
5. **Practica con los ejercicios** en la carpeta `EJERCICIOS/`

### Compilación básica
Para compilar cualquier archivo `.c`:
```bash
gcc -o nombre_ejecutable archivo.c
./nombre_ejecutable
```

### Compilar todo el repositorio
Usa el Makefile en la raíz del proyecto:
```bash
# Compilar todos los programas
make all

# Compilar y verificar
make check

# Compilar solo una sección específica
make fundamentos    # o io, arrays, pointers, etc.

# Limpiar archivos generados
make clean

# Ver todos los comandos disponibles
make help
```

## ✅ Integración Continua (CI)

Este repositorio utiliza GitHub Actions para verificar automáticamente que todos los programas compilan correctamente. El badge de estado en la parte superior muestra si la última compilación fue exitosa.

- **CI automático**: Se ejecuta en cada push y pull request
- **Compilación por secciones**: Cada directorio se compila independientemente
- **Verificación completa**: Todos los programas válidos son compilados y verificados

Para más detalles sobre el sistema de CI, consulta [.github/README.md](.github/README.md).

## 📋 Recomendaciones de estudio

1. **Lee los comentarios**: Cada archivo tiene comentarios detallados que explican el código
2. **Experimenta**: Modifica los ejemplos para ver qué sucede
3. **Practica**: Intenta escribir tus propias variaciones de los ejercicios
4. **Pregunta**: Si algo no está claro, busca ayuda o documentación adicional

## 🤝 Contribuir

Si encuentras errores o tienes sugerencias para mejorar los ejemplos, ¡las contribuciones son bienvenidas!

---

**¡Bienvenido al mundo de la programación en C!** 🎉