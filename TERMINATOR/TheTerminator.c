/**
 * <file>TheTerminator.c</file>
 * <brief>Herramienta para recolectar y copiar archivos de estudiantes</brief>
 * <author>Iker Llorens</author>
 * 
 * Este programa busca archivos específicos en los directorios de estudiantes,
 * los copia a un directorio local y los prepara para evaluación.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_file_in_directory(char file[], char student[]);
int copy_file(char file[], char student[], char local_dir_name[]);
int build_students_program(char directory[], char student[]);

/**
 * <brief>Función principal del programa</brief>
 * 
 * Procesa una lista de estudiantes, busca archivos específicos en sus
 * directorios y los copia a un directorio local.
 * 
 * <param name="argc">Número de argumentos de línea de comandos</param>
 * <param name="argv">Arreglo de argumentos: [1] lista de alumnos, [2] ruta del archivo, [3] nombre local</param>
 * <return>0 si el programa se ejecutó correctamente</return>
 */
int main(int argc, char *argv[])
{
    FILE *fp;

    char account[16] = "";
    char cmd[256] = "mkdir ";

    if (argc != 4)
    {
        printf("Uso: Terminator.out <lista alumnos> <ruta del archivo a calificar> <nombre local> \n");
        return 0;
    }

    printf("Creando directorio %s\n", argv[3]);
    strcat(cmd, argv[3]);
    system(cmd);

    fp = fopen(argv[1], "r");

    while (fscanf(fp, "%s", account) != EOF)
    {
        printf("\n\n--------------------------\n-> Procesando %s\n", account);
        if (is_file_in_directory(argv[2], account))
        {
            if (copy_file(argv[2], account, argv[3]) == 0)
            {
                printf("Se copio el archivo %s\n", argv[2]);
            }
            else
            {
                printf("No se pudo copiar el archivo %s\n", argv[2]);
            }
        }
        else
        {
            printf("No se encontro el archivo %s en el directorio de %s\n", argv[2], account);
        }
    }

    fclose(fp);

    return 0;
}

/*
 * Verifica si un archivo existe en un directorio
 * <param name="file">Directorio y nombre del archivo a buscar</param>
 * <param name="student">Cuenta del alumno a buscar</param>
 *
 * <return>1 si el archivo existe, 0 si no existe</return>
 */
int is_file_in_directory(char file[], char student[])
{
    char path[256] = "/home/";
    FILE *fp;

    strcat(path, student);
    strcat(path, "/");
    strcat(path, file);

    printf("Buscando %s en %s\n", file, path);

    fp = fopen(path, "r");
    if (fp == NULL)
    {
        return 0;
    }

    return 1;
}

/**
 * <brief>Copia un archivo del directorio del estudiante al directorio local</brief>
 * 
 * Construye el comando de copia y ejecuta la operación, reportando
 * cualquier error que ocurra durante el proceso.
 * 
 * <param name="file">Nombre del archivo a copiar</param>
 * <param name="student">Nombre de usuario del estudiante</param>
 * <param name="local_dir_name">Nombre del directorio local de destino</param>
 * <return>0 si la copia fue exitosa, longitud del mensaje de error si falló</return>
 */
int copy_file(char file[], char student[], char local_dir_name[])
{
    char cmd[256] = "cp /home/";
    char out[256] = "";
    FILE *fp;

    strcat(cmd, student);
    strcat(cmd, "/");
    strcat(cmd, file);
    strcat(cmd, " ./");
    strcat(cmd, local_dir_name);
    strcat(cmd, "/");
    strcat(cmd, student);
    strcat(cmd, ".c");

    printf("Copiando %s a %s\n", file, student);

    fp = popen(cmd, "r");

    fscanf(fp, "%s", out);

    pclose(fp);

    if (strlen(out) != 0)
    {
        printf("ERROR con %s : %s \n", student, out);
    }

    return strlen(out);
}

/**
 * <brief>Compila el programa de un estudiante</brief>
 * 
 * Construye y ejecuta el comando gcc para compilar el programa del estudiante,
 * reportando cualquier error de compilación.
 * 
 * <param name="directory">Ruta del archivo a compilar</param>
 * <param name="student">Nombre de usuario del estudiante</param>
 * <return>0 si la compilación fue exitosa, longitud del mensaje de error si falló</return>
 */
int build_students_program(char directory[], char student[])
{
    char out[256] = "";
    char cmd[512] = "gcc /home/";

    strcat(cmd, student);
    strcat(cmd, "/");
    strcat(cmd, directory);

    printf("%s\n", cmd);
    FILE *fp = popen(cmd, "r");

    fscanf(fp, "%s", out);

    pclose(fp);

    if (strlen(out) != 0)
    {
        printf("ERROR con %s : %s \n", student, out);
    }

    return strlen(out);
}