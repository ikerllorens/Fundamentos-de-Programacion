#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_file_in_directory(char file[], char student[]);
void log(char msg[], char local_dir_name[]);
int BuildStudentsProgram(char directory[], char student[]);

int main(int argc, char *argv[])
{
    FILE *fp;

    char account[16] = "";
    char cmd[256] = "";

    if (argc != 4)
    {
        printf("Uso: Terminator.out <lista alumnos> <ruta del archivo a calificar> <nombre local> \n");
        return 0;
    }

    strcat("mkdir ", argv[3]);

    fp = fopen(argv[1], "r");

    while (fscanf(fp, "%s", account) != EOF)
    {
        log("-> Evaluando %s", argv[3]);
        if (is_file_in_directory(argv[2], account) == 0)
        {
        }
        else
        {
            log("No se enocntro el archivo para ", argv[3]);
            log(account, argv[3]);
        }
    }

    fclose(fp);

    return 0;
}

/*
 * Escribe un mensaje en el archivo de log y en pantalla
 * @param msg Mensaje a escribir
 * @param local_dir_name Nombre del directorio local
 */
void log(char msg[], char local_dir_name[])
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

/*
 * Verifica si un archivo existe en un directorio
 * @param file Directorio y nombre del archivo a buscar
 * @param student Cuenta del alumno a buscar
 *
 * @return 1 si el archivo existe, 0 si no existe
 */
int is_file_in_directory(char file[], char student[])
{
    char path[256] = "/home/";
    FILE *fp;

    strcat(path, student);
    strcat(path, "/");
    strcat(path, file);

    fp = fopen(path, "r");
    if (fp == NULL)
    {
        return 0;
    }

    return 1;
}

int BuildStudentsProgram(char directory[], char student[])
{
    char ext[4] = ".c";
    char out[256] = "";
    char cmd[512] = "cp /home/";

    strcat(cmd, student);
    strcat(cmd, directory);
    strcat(cmd, " ./TAREA1/");
    strcat(cmd, student);
    strcat(cmd, ext);

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