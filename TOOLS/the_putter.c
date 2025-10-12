/**
 * <file>the_putter.c</file>
 * <brief>Herramienta para distribuir archivos a directorios de estudiantes</brief>
 * <author>Iker Llorens</author>
 * 
 * Este programa copia archivos a los directorios personales de los estudiantes
 * y asigna los permisos apropiados.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int copy_to_students(char route[], char route_to_file[]);
void assemble_route(char student[], char route_in_students[], char final_route[]);
void assign_permissions(char route[], char filename[], char user[], char user_group[]);
void logger(char msg[], char local_dir_name[]);

/**
 * <brief>Función principal del programa</brief>
 * 
 * Lee una lista de estudiantes y copia un archivo específico al directorio
 * de cada estudiante, asignando los permisos correspondientes.
 * 
 * <param name="argc">Número de argumentos de línea de comandos</param>
 * <param name="argv">Arreglo de argumentos: [1] lista alumnos, [2] ruta archivo a copiar, [3] ruta destino</param>
 * <return>0 si el programa se ejecutó correctamente</return>
 */
int main(int argc, char *argv[])
{
    FILE *fp;

    char account[16] = "";
    char final_route[256] = "";

    if (argc != 4) {
        printf("Uso: the_putter.out <lista alumnos> <ruta del archivo a copiar> <ruta destino> \n");
        return 0;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("ERROR: No se pudo abrir el archivo %s\n", argv[1]);
        return 1;
    }

    while (fscanf(fp, "%s", account) != EOF) {
        strcpy(final_route, "");
        printf("\n\n--------------------------\n-> Procesando %s\n", account);
        assemble_route(account, argv[3], final_route);
        copy_to_students(final_route, argv[2]);
        assign_permissions(final_route, argv[2], account, "student");
    }

    fclose(fp);

    return 0;
}

/**
 * <brief>Construye la ruta completa al directorio del estudiante</brief>
 * 
 * Ensambla la ruta completa concatenando /home/, el nombre del estudiante
 * y la ruta relativa especificada.
 * 
 * <param name="student">Nombre de usuario del estudiante</param>
 * <param name="route_in_students">Ruta relativa dentro del directorio del estudiante</param>
 * <param name="final_route">Buffer donde se almacenará la ruta completa construida</param>
 */
void assemble_route(char student[], char route_in_students[], char final_route[])
{
    strcat(final_route, "/home/");
    strcat(final_route, student);
    strcat(final_route, "/");
    strcat(final_route, route_in_students);
}

/**
 * <brief>Copia un archivo a la ruta especificada del estudiante</brief>
 * 
 * Ejecuta el comando cp para copiar el archivo y reporta cualquier
 * error que ocurra durante la operación.
 * 
 * <param name="route">Ruta de destino donde se copiará el archivo</param>
 * <param name="route_to_file">Ruta del archivo origen a copiar</param>
 * <return>0 si la copia fue exitosa, valor distinto si hubo error</return>
 */
int copy_to_students(char route[], char route_to_file[])
{
    char cmd[256] = "cp ";
    char out[512] = "";

    strcat(cmd, route_to_file);
    strcat(cmd, " ");
    strcat(cmd, route);

    printf("%s\n", cmd);

    FILE *fp = popen(cmd, "r");
    fscanf(fp, "%s", out);
    pclose(fp);

    if (strlen(out) != 0) {
        printf("ERROR con %s : %s \n", route, out);
    }

    return 0;
}

/**
 * <brief>Asigna permisos y propietario al archivo copiado</brief>
 * 
 * Ejecuta comandos chown y chmod para asignar el propietario correcto
 * y los permisos 755 al archivo especificado.
 * 
 * <param name="route">Ruta donde se encuentra el archivo</param>
 * <param name="filename">Nombre del archivo</param>
 * <param name="user">Usuario propietario del archivo</param>
 * <param name="user_group">Grupo propietario del archivo</param>
 */
void assign_permissions(char route[], char filename[], char user[], char user_group[])
{
    FILE *fp;
    char cmd[256] = "chown ";
    char cmd_perm[256] = "chmod 755 ";
    char out[512] = "";

    if (route[strlen(route) - 1] != '/') {
        strcat(route, "/");
    }
    strcat(route, filename);

    strcat(cmd, user);
    strcat(cmd, ":");
    strcat(cmd, user_group);
    strcat(cmd, " ");
    strcat(cmd, route);

    printf("%s\n", cmd);

    strcat(cmd_perm, route);
    printf("%s\n", cmd_perm);

    fp = popen(cmd, "r");
    fscanf(fp, "%s", out);
    pclose(fp);

    if (strlen(out) != 0) {
        printf("ERROR con %s : %s \n", route, out);
    }

    fp = popen(cmd_perm, "r");
    fscanf(fp, "%s", out);
    pclose(fp);

    if (strlen(out) != 0) {
        printf("ERROR con %s : %s \n", route, out);
    }
}

/**
 * <brief>Escribe un mensaje en el archivo de log y en pantalla</brief>
 * 
 * Registra mensajes tanto en la consola como en un archivo log.txt
 * ubicado en el directorio local especificado.
 * 
 * <param name="msg">Mensaje a escribir</param>
 * <param name="local_dir_name">Nombre del directorio local donde se encuentra log.txt</param>
 */
void logger(char msg[], char local_dir_name[])
{
    FILE *log;
    char path[256] = "./";
    strcat(path, local_dir_name);
    strcat(path, "/log.txt");

    log = fopen(path, "a");

    printf("> %s\n", msg);
    fprintf(log, "> %s\n", msg);

    fclose(log);
}
