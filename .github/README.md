# Sistema de Integración Continua (CI)

Este repositorio utiliza GitHub Actions para verificar automáticamente que todos los programas compilan correctamente.

## 🔄 Workflows Activos

### `build-and-test.yml` - Workflow Principal ✅

Este es el workflow principal que se ejecuta automáticamente en:
- **Push** a la rama `main`
- **Pull Requests** hacia la rama `main`
- **Manualmente** desde la interfaz de GitHub Actions

#### Trabajos que ejecuta:

1. **build-all**: Compila todos los programas usando el Makefile raíz
   - Ejecuta `make check` para compilar todo
   - Verifica que los ejecutables se crearon correctamente
   - Limpia los archivos generados

2. **build-by-section**: Compila cada sección por separado
   - Usa una matriz para compilar cada directorio independientemente
   - Útil para identificar rápidamente qué sección tiene problemas
   - Secciones: fundamentos, io, arrays, pointers, program-flow, ejercicios, tools, makefile-example

## 📋 Workflows Deprecados (Solo Referencia)

Los siguientes workflows están deshabilitados pero se mantienen para referencia:
- `BASICS-Build.yml` (DEPRECATED)
- `EJERCICIOS-Build.yml` (DEPRECATED)
- `IO-Build.yml` (DEPRECATED)
- `POINTERS-Build.yml` (DEPRECATED)

Estos workflows solo se pueden ejecutar manualmente y han sido reemplazados por `build-and-test.yml`.

## 🛠️ Makefile

El archivo `Makefile` en la raíz del repositorio proporciona los siguientes targets:

### Targets Principales:
- `make all` - Compila todos los programas
- `make check` - Compila todo y muestra mensaje de verificación
- `make clean` - Elimina archivos generados (*.o, *.out, *.exe)
- `make help` - Muestra ayuda con todos los targets disponibles

### Targets por Sección:
- `make fundamentos` - Compila programas de Fundamentos
- `make io` - Compila programas de IO
- `make arrays` - Compila programas de ARRAYS
- `make pointers` - Compila programas de POINTERS
- `make program-flow` - Compila programas de PROGRAM FLOW
- `make ejercicios` - Compila programas de EJERCICIOS
- `make tools` - Compila programas de TOOLS
- `make makefile-example` - Compila el ejemplo de Makefile

## 🚀 Uso Local

Para compilar todos los programas localmente:

```bash
# Compilar todo
make all

# Compilar y verificar
make check

# Compilar solo una sección
make fundamentos

# Limpiar archivos generados
make clean
```

## 📝 Archivos Excluidos

Los siguientes archivos NO se compilan como ejecutables independientes:

- `IO/EjemploGetchar.c` - Archivo vacío (pendiente de implementación)
- `IO/EjemploPutchar.c` - Archivo vacío (pendiente de implementación)
- `MAKEFILE_EXAMPLE/ejemplo_xml_doc.c` - Solo documentación, se compila como objeto
- `EJERCICIOS/ABECEDARIO/abecedario_bad.c` - Código con errores intencionales para propósitos educativos

## ✅ Estado de CI

El badge de estado del CI se puede ver en el README principal del repositorio.

Para ver los resultados de las ejecuciones:
1. Ve a la pestaña "Actions" en GitHub
2. Selecciona el workflow "Build and Test All Programs"
3. Revisa los resultados de cada ejecución

## 🔧 Mantenimiento

### Agregar un nuevo programa:

1. Agrega el archivo `.c` en el directorio correspondiente
2. Actualiza el `Makefile` agregando el archivo a las variables correspondientes:
   - Agrega a `<SECCION>_SOURCES`
   - El Makefile generará automáticamente los targets para `.o` y `.out`
3. Ejecuta `make check` para verificar que compila
4. El CI se ejecutará automáticamente al hacer push

### Solucionar errores de compilación:

Si el CI falla:
1. Revisa los logs en la pestaña Actions
2. Reproduce el error localmente con `make check`
3. Corrige los errores de compilación
4. Verifica con `make check` nuevamente
5. Haz commit y push de los cambios

## 📚 Referencias

- [GitHub Actions Documentation](https://docs.github.com/en/actions)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [GCC Compiler Options](https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html)
