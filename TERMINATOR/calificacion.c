/**
 * <file>calificacion.c</file>
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
int copy_directory(char directory[], char student[], char local_dir_name[]);
int build_students_program(char directory[], char student[]);
void print_usage(void);
int parse_arguments(int argc, char *argv[], char *user_list, char *dest_dir, char *source_dir, int *copy_dir_mode);

/**
 * <brief>Muestra el mensaje de uso del programa</brief>
 * 
 * Despliega información sobre cómo usar el programa y sus opciones disponibles.
 */
void print_usage(void)
{
    printf("Uso: calificacion.out [opciones]\n\n");
    printf("Opciones obligatorias:\n");
    printf("  -ul [ruta]    Ruta al archivo de lista de usuarios (default: ./student_list.txt)\n");
    printf("  -d:{dir}      Directorio destino donde se copiarán los archivos\n");
    printf("  -s:{dir}      Directorio fuente donde se encuentran los archivos a copiar\n");
    printf("\nOpciones adicionales:\n");
    printf("  -dir          Copiar el contenido completo de la carpeta en vez de un archivo específico\n");
    printf("  -h            Mostrar este mensaje de ayuda\n");
    printf("\nEjemplos:\n");
    printf("  calificacion.out -ul students.txt -d:evaluaciones -s:tarea1.c\n");
    printf("  calificacion.out -ul -d:salida -s:proyecto -dir\n");
}

/**
 * <brief>Parsea y valida los argumentos de línea de comandos</brief>
 * 
 * Procesa los argumentos proporcionados y extrae las opciones necesarias
 * para la ejecución del programa.
 * 
 * <param name="argc">Número de argumentos</param>
 * <param name="argv">Arreglo de argumentos</param>
 * <param name="user_list">Buffer donde se almacenará la ruta de la lista de usuarios</param>
 * <param name="dest_dir">Buffer donde se almacenará el directorio destino</param>
 * <param name="source_dir">Buffer donde se almacenará el directorio/archivo fuente</param>
 * <param name="copy_dir_mode">Puntero a flag que indica si se debe copiar directorio completo</param>
 * <return>0 si los argumentos son válidos, -1 si hay error</return>
 */
int parse_arguments(int argc, char *argv[], char *user_list, char *dest_dir, char *source_dir, int *copy_dir_mode)
{
    int ul_found = 0, dest_found = 0, source_found = 0;
    int i;

    *copy_dir_mode = 0;
    strcpy(user_list, "");
    strcpy(dest_dir, "");
    strcpy(source_dir, "");

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            print_usage();
            return -1;
        }
        else if (strcmp(argv[i], "-ul") == 0) {
            ul_found = 1;
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                strcpy(user_list, argv[i + 1]);
                i++;
            }
            else {
                strcpy(user_list, "./student_list.txt");
            }
        }
        else if (strncmp(argv[i], "-d:", 3) == 0) {
            dest_found = 1;
            strcpy(dest_dir, argv[i] + 3);
        }
        else if (strncmp(argv[i], "-s:", 3) == 0) {
            source_found = 1;
            strcpy(source_dir, argv[i] + 3);
        }
        else if (strcmp(argv[i], "-dir") == 0) {
            *copy_dir_mode = 1;
        }
    }

    if (!ul_found || !dest_found || !source_found) {
        printf("ERROR: Faltan argumentos obligatorios\n\n");
        print_usage();
        return -1;
    }

    return 0;
}

/**
 * <brief>Función principal del programa</brief>
 * 
 * Procesa una lista de estudiantes, busca archivos específicos en sus
 * directorios y los copia a un directorio local.
 * 
 * <param name="argc">Número de argumentos de línea de comandos</param>
 * <param name="argv">Arreglo de argumentos</param>
 * <return>0 si el programa se ejecutó correctamente</return>
 */
int main(int argc, char *argv[])
{
    FILE *fp;
    char account[16] = "";
    char cmd[256] = "";
    char user_list[256] = "";
    char dest_dir[256] = "";
    char source_dir[256] = "";
    int copy_dir_mode = 0;

    if (argc < 2) {
        print_usage();
        return 0;
    }

    if (parse_arguments(argc, argv, user_list, dest_dir, source_dir, &copy_dir_mode) != 0) {
        return 1;
    }

    printf("Creando directorio %s\n", dest_dir);
    strcpy(cmd, "mkdir -p ");
    strcat(cmd, dest_dir);
    system(cmd);

    fp = fopen(user_list, "r");
    if (fp == NULL) {
        printf("ERROR: No se pudo abrir el archivo %s\n", user_list);
        return 1;
    }

    while (fscanf(fp, "%s", account) != EOF) {
        printf("\n\n--------------------------\n-> Procesando %s\n", account);
        
        if (copy_dir_mode) {
            if (copy_directory(source_dir, account, dest_dir) == 0) {
                printf("Se copio el directorio %s\n", source_dir);
            }
            else {
                printf("No se pudo copiar el directorio %s\n", source_dir);
            }
        }
        else {
            if (is_file_in_directory(source_dir, account)) {
                if (copy_file(source_dir, account, dest_dir) == 0) {
                    printf("Se copio el archivo %s\n", source_dir);
                }
                else {
                    printf("No se pudo copiar el archivo %s\n", source_dir);
                }
            }
            else {
                printf("No se encontro el archivo %s en el directorio de %s\n", source_dir, account);
            }
        }
    }

    fclose(fp);

    return 0;
}

/**
 * <brief>Verifica si un archivo existe en un directorio</brief>
 * 
 * Construye la ruta completa al archivo del estudiante y verifica
 * si existe intentando abrirlo para lectura.
 * 
 * <param name="file">Directorio y nombre del archivo a buscar</param>
 * <param name="student">Cuenta del alumno a buscar</param>
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
    if (fp == NULL) {
        return 0;
    }

    fclose(fp);
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

    if (strlen(out) != 0) {
        printf("ERROR con %s : %s \n", student, out);
    }

    return strlen(out);
}

/**
 * <brief>Copia un directorio completo del estudiante al directorio local</brief>
 * 
 * Construye el comando de copia recursiva y ejecuta la operación, reportando
 * cualquier error que ocurra durante el proceso.
 * 
 * <param name="directory">Nombre del directorio a copiar</param>
 * <param name="student">Nombre de usuario del estudiante</param>
 * <param name="local_dir_name">Nombre del directorio local de destino</param>
 * <return>0 si la copia fue exitosa, longitud del mensaje de error si falló</return>
 */
int copy_directory(char directory[], char student[], char local_dir_name[])
{
    char cmd[512] = "cp -r /home/";
    char out[256] = "";
    FILE *fp;

    strcat(cmd, student);
    strcat(cmd, "/");
    strcat(cmd, directory);
    strcat(cmd, " ./");
    strcat(cmd, local_dir_name);
    strcat(cmd, "/");
    strcat(cmd, student);

    printf("Copiando directorio %s de %s\n", directory, student);

    fp = popen(cmd, "r");

    fscanf(fp, "%s", out);

    pclose(fp);

    if (strlen(out) != 0) {
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

    if (strlen(out) != 0) {
        printf("ERROR con %s : %s \n", student, out);
    }

    return strlen(out);
}