# Cómo Desarrollar C en tu Máquina Local usando VSCode y SSH

Esta guía te mostrará cómo configurar Visual Studio Code (VSCode) en tu computadora local para desarrollar programas en C conectándote al servidor de la clase mediante SSH (Secure Shell).

## 📋 Tabla de Contenidos

1. [Requisitos Previos](#requisitos-previos)
2. [Instalación de Visual Studio Code](#instalación-de-visual-studio-code)
3. [Instalación de la Extensión Remote-SSH](#instalación-de-la-extensión-remote-ssh)
4. [Configuración de la Conexión SSH](#configuración-de-la-conexión-ssh)
5. [Conexión al Servidor](#conexión-al-servidor)
6. [Desarrollo en el Servidor Remoto](#desarrollo-en-el-servidor-remoto)
7. [Compilación y Ejecución de Programas en C](#compilación-y-ejecución-de-programas-en-c)
8. [Solución de Problemas Comunes](#solución-de-problemas-comunes)

---

## 📌 Requisitos Previos

Antes de comenzar, necesitarás:

- **Una computadora** con Windows, macOS o Linux
- **Conexión a Internet** para descargar e instalar el software necesario
- **Credenciales de acceso** al servidor de la clase:
  - **Host/Servidor**: `antares.dci.uia.mx`
  - **Usuario**: Tu nombre de usuario asignado
  - **Contraseña**: Tu contraseña asignada

---

## 💻 Instalación de Visual Studio Code

### Paso 1: Descargar VSCode

1. Ve al sitio oficial de Visual Studio Code: [https://code.visualstudio.com/](https://code.visualstudio.com/)
2. Haz clic en el botón **"Download"** (Descargar)
3. El sitio detectará automáticamente tu sistema operativo y te ofrecerá la versión correcta

### Paso 2: Instalar VSCode

**En Windows:**
- Ejecuta el archivo `.exe` descargado
- Sigue el asistente de instalación
- Se recomienda marcar las opciones:
  - ✅ "Add to PATH" (Agregar a PATH)
  - ✅ "Create a desktop icon" (Crear un icono en el escritorio)

**En macOS:**
- Abre el archivo `.dmg` descargado
- Arrastra el icono de VSCode a la carpeta "Applications"
- Abre VSCode desde tu carpeta de Aplicaciones

**En Linux (Ubuntu/Debian):**
```bash
# Descarga e instala usando el gestor de paquetes
sudo apt update
sudo apt install code
```

### Paso 3: Verificar la Instalación

1. Abre Visual Studio Code
2. Deberías ver la pantalla de bienvenida de VSCode

---

## 🔌 Instalación de la Extensión Remote-SSH

La extensión Remote-SSH te permite conectarte a servidores remotos y desarrollar como si estuvieras trabajando localmente.

### Paso 1: Abrir el Panel de Extensiones

1. Abre Visual Studio Code
2. Haz clic en el icono de **Extensiones** en la barra lateral izquierda (o presiona `Ctrl+Shift+X` en Windows/Linux o `Cmd+Shift+X` en macOS)

### Paso 2: Buscar e Instalar Remote-SSH

1. En la barra de búsqueda, escribe: **Remote - SSH**
2. Busca la extensión desarrollada por **Microsoft** (debería ser el primer resultado)
3. Haz clic en el botón **"Install"** (Instalar)

### Paso 3: Instalar Extensiones Complementarias (Recomendado)

Para una mejor experiencia, también instala:

- **Remote - SSH: Editing Configuration Files**: Para editar fácilmente archivos de configuración SSH
- **C/C++**: Extensión oficial de Microsoft para desarrollo en C/C++ (se instalará en el servidor remoto más adelante)

---

## ⚙️ Configuración de la Conexión SSH

### Paso 1: Abrir la Paleta de Comandos

1. Presiona `Ctrl+Shift+P` (Windows/Linux) o `Cmd+Shift+P` (macOS)
2. Escribe: **Remote-SSH: Open SSH Configuration File**
3. Selecciona el archivo de configuración (generalmente el primero en la lista):
   - Windows: `C:\Users\TuUsuario\.ssh\config`
   - macOS/Linux: `~/.ssh/config`

### Paso 2: Agregar la Configuración del Servidor

Si el archivo está vacío o no existe, agrega la siguiente configuración:

```ssh-config
Host antares
    HostName antares.dci.uia.mx
    User tu_usuario_aqui
    Port 22
```

**Importante**: Reemplaza `tu_usuario_aqui` con tu nombre de usuario real del servidor.

**Ejemplo completo:**
```ssh-config
Host antares
    HostName antares.dci.uia.mx
    User jperez
    Port 22
```

### Paso 3: Guardar el Archivo de Configuración

1. Guarda el archivo: `Ctrl+S` (Windows/Linux) o `Cmd+S` (macOS)
2. Cierra el archivo de configuración

---

## 🚀 Conexión al Servidor

### Paso 1: Iniciar la Conexión

1. Haz clic en el icono verde en la esquina inferior izquierda de VSCode (tiene un símbolo de `><`)
2. Se abrirá un menú en la parte superior. Selecciona: **"Connect to Host..."**
3. Verás una lista de hosts disponibles. Selecciona **antares** (el que configuraste anteriormente)

**Alternativa rápida:**
- Presiona `Ctrl+Shift+P` (o `Cmd+Shift+P` en macOS)
- Escribe: **Remote-SSH: Connect to Host...**
- Selecciona **antares**

### Paso 2: Autenticación con Usuario y Contraseña

1. VSCode abrirá una nueva ventana e intentará conectarse al servidor
2. En la parte superior aparecerá un cuadro de diálogo pidiendo tu contraseña
3. **Ingresa tu contraseña** (la que te proporcionaron para acceder al servidor `antares.dci.uia.mx`)
4. Presiona `Enter`

**Nota**: Es posible que la contraseña no se muestre mientras la escribes (por seguridad). Esto es normal, simplemente escribe tu contraseña y presiona Enter.

### Paso 3: Verificar la Conexión

1. Una vez conectado, verás en la esquina inferior izquierda el texto: **SSH: antares**
2. VSCode instalará automáticamente el "VS Code Server" en el servidor remoto (esto solo sucede la primera vez y puede tomar unos minutos)

---

## 💡 Desarrollo en el Servidor Remoto

Una vez conectado al servidor, puedes trabajar como si estuvieras en tu máquina local.

### Abrir una Carpeta en el Servidor

1. Ve a **File > Open Folder...** (Archivo > Abrir Carpeta...)
2. Verás el sistema de archivos del servidor remoto
3. Navega a tu directorio de trabajo (generalmente `/home/tu_usuario/`)
4. Selecciona la carpeta donde quieres trabajar o crea una nueva

**Crear una carpeta nueva desde la terminal:**
1. Abre la terminal integrada: **Ctrl+\`** (tecla acento grave) o **Terminal > New Terminal**
2. Crea una carpeta para tus proyectos:
   ```bash
   mkdir fundamentos-c
   cd fundamentos-c
   ```

### Instalar la Extensión de C/C++ en el Servidor Remoto

Para tener autocompletado, resaltado de sintaxis y otras características útiles:

1. Haz clic en el icono de **Extensiones** (`Ctrl+Shift+X`)
2. Busca: **C/C++** (de Microsoft)
3. Haz clic en **"Install in SSH: antares"** (Instalar en SSH: antares)

**Extensiones recomendadas para C:**
- **C/C++** (Microsoft): IntelliSense, depuración y navegación de código
- **C/C++ Extension Pack** (Microsoft): Paquete completo con temas y snippets

---

## 🔨 Compilación y Ejecución de Programas en C

### Crear tu Primer Programa

1. Crea un nuevo archivo: **File > New File** o `Ctrl+N`
2. Guarda el archivo con extensión `.c`: **File > Save As...** → `hola_mundo.c`
3. Escribe tu programa:

```c
/**
 * <file>hola_mundo.c</file>
 * <brief>Mi primer programa en C</brief>
 * <author>Tu Nombre</author>
 */

#include <stdio.h>

/**
 * <brief>Función principal del programa</brief>
 * <return>0 si el programa termina correctamente</return>
 */
int main(void)
{
    printf("¡Hola, Mundo desde el servidor antares!\n");
    return 0;
}
```

### Compilar el Programa

1. Abre la **Terminal Integrada** en VSCode:
   - **Ctrl+\`** (tecla acento grave)
   - O ve a **Terminal > New Terminal**

2. Compila tu programa usando GCC:
   ```bash
   gcc -o hola_mundo hola_mundo.c
   ```

   **Explicación del comando:**
   - `gcc`: El compilador de C
   - `-o hola_mundo`: Nombre del archivo ejecutable de salida
   - `hola_mundo.c`: Archivo fuente a compilar

3. Si no hay errores, verás un nuevo archivo ejecutable llamado `hola_mundo`

### Ejecutar el Programa

En la terminal, ejecuta:
```bash
./hola_mundo
```

Deberías ver la salida:
```
¡Hola, Mundo desde el servidor antares!
```

### Compilación con Warnings y Debugging

Para una mejor práctica de programación, compila con advertencias y símbolos de depuración:

```bash
gcc -Wall -Wextra -g -o hola_mundo hola_mundo.c
```

**Explicación de las banderas:**
- `-Wall`: Activa la mayoría de las advertencias
- `-Wextra`: Activa advertencias adicionales
- `-g`: Incluye información de depuración

---

## 🛠️ Solución de Problemas Comunes

### Problema 1: "Could not establish connection to antares"

**Solución:**
- Verifica que estás conectado a Internet
- Confirma que el servidor `antares.dci.uia.mx` esté disponible
- Intenta hacer ping desde tu terminal local:
  ```bash
  ping antares.dci.uia.mx
  ```

### Problema 2: "Permission denied (publickey,password)"

**Solución:**
- Verifica que tu usuario y contraseña sean correctos
- Asegúrate de que el puerto en la configuración SSH sea el correcto (normalmente 22)
- Contacta al administrador del sistema si el problema persiste

### Problema 3: La contraseña no se acepta

**Solución:**
- Recuerda que al escribir la contraseña en la terminal no se muestra (es invisible por seguridad)
- Escribe tu contraseña con cuidado y presiona Enter
- Si fallas 3 veces, puede que necesites esperar unos minutos antes de intentar de nuevo

### Problema 4: "gcc: command not found"

**Solución:**
- El compilador GCC no está instalado en el servidor
- Contacta al administrador del sistema para que instale GCC
- O verifica que estés en el directorio correcto

### Problema 5: La conexión SSH se desconecta constantemente

**Solución:**
- Agrega estas líneas a tu archivo de configuración SSH:
  ```ssh-config
  Host antares
      HostName antares.dci.uia.mx
      User tu_usuario
      Port 22
      ServerAliveInterval 60
      ServerAliveCountMax 3
  ```
- Esto enviará paquetes cada 60 segundos para mantener la conexión activa

### Problema 6: No puedo ver las extensiones instaladas en el servidor remoto

**Solución:**
- Asegúrate de estar conectado al servidor (verifica la esquina inferior izquierda: "SSH: antares")
- Las extensiones deben instalarse específicamente en el servidor remoto
- Busca el botón "Install in SSH: antares" al lado del botón "Install"

---

## 📚 Recursos Adicionales

### Comandos Útiles de Terminal

```bash
# Ver el contenido del directorio actual
ls -la

# Navegar a un directorio
cd nombre_directorio

# Regresar al directorio anterior
cd ..

# Ver la ruta del directorio actual
pwd

# Crear un directorio
mkdir nombre_directorio

# Eliminar un archivo
rm nombre_archivo

# Copiar un archivo
cp origen destino

# Ver el contenido de un archivo
cat nombre_archivo

# Editar un archivo con nano
nano nombre_archivo

# Compilar todos los archivos .c del directorio
gcc -Wall -Wextra -o programa *.c
```

### Atajos de Teclado Útiles en VSCode

- **Ctrl+\`** (tecla acento grave): Abrir/Cerrar terminal integrada
- `Ctrl+P`: Búsqueda rápida de archivos
- `Ctrl+Shift+P`: Paleta de comandos
- `Ctrl+/`: Comentar/Descomentar línea
- `Ctrl+S`: Guardar archivo
- `Ctrl+F`: Buscar en el archivo actual
- `Ctrl+H`: Buscar y reemplazar
- `F5`: Iniciar depuración (si está configurada)

### Documentación Oficial

- [Visual Studio Code - Remote Development](https://code.visualstudio.com/docs/remote/remote-overview)
- [Remote - SSH Extension](https://code.visualstudio.com/docs/remote/ssh)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [The C Programming Language](https://en.cppreference.com/w/c)

---

## ✅ Verificación Final

Para asegurarte de que todo está funcionando correctamente:

1. ✅ **VSCode instalado y funcionando**
2. ✅ **Extensión Remote-SSH instalada**
3. ✅ **Configuración SSH creada** con el host `antares.dci.uia.mx`
4. ✅ **Conexión exitosa al servidor** (ves "SSH: antares" en la esquina inferior izquierda)
5. ✅ **Puedes crear y editar archivos** en el servidor
6. ✅ **Puedes compilar programas en C** con `gcc`
7. ✅ **Puedes ejecutar tus programas compilados**

---

## 🎓 Consejos para Estudiantes

1. **Guarda tu trabajo frecuentemente**: Usa `Ctrl+S` constantemente para guardar tus cambios
2. **Usa Git para versionar tu código**: Aprende comandos básicos de Git para mantener un historial de cambios
3. **Compila con warnings**: Siempre usa `-Wall -Wextra` para detectar posibles problemas
4. **Prueba tu código**: Ejecuta tu programa con diferentes entradas para asegurarte de que funciona correctamente
5. **Lee los errores del compilador**: Los mensajes de error te dirán exactamente qué está mal
6. **Comenta tu código**: Escribe comentarios claros para explicar qué hace cada parte de tu programa
7. **Haz respaldos**: Copia tus archivos importantes regularmente

---

## 🆘 ¿Necesitas Ayuda?

Si encuentras problemas que no puedes resolver:

1. **Consulta esta guía nuevamente** - Muchas veces la solución está aquí
2. **Pregunta a tus compañeros** - El aprendizaje colaborativo es muy efectivo
3. **Busca en línea** - Stack Overflow y foros de programación son recursos valiosos
4. **Contacta a tu profesor o asistente** - Están ahí para ayudarte

---

**¡Buena suerte con tu desarrollo en C!** 🚀

*Recuerda: La programación se aprende practicando. No te desanimes si algo no funciona a la primera vez. Cada error es una oportunidad de aprendizaje.*
