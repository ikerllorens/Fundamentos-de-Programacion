#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int copy_to_students(char route[], char route_to_file[]);
void assemble_route(char student[], char route_in_students[], char final_route[]);
void assign_permissions(char route[], char filename[], char user[], char user_group[]);
void logger(char msg[], char local_dir_name[]);

int main(int argc, char *argv[])
{
    FILE *fp;

    char account[16] = "";
    char final_route[256] = "";

    if (argc != 4)
    {
        printf("Uso: the_putter.out <lista alumnos> <ruta del archivo a copiar> <ruta destino> \n");
        return 0;
    }

    fp = fopen(argv[1], "r");

    while (fscanf(fp, "%s", account) != EOF)
    {
        strcpy(final_route, "");
        printf("\n\n--------------------------\n-> Procesando %s\n", account);
        assemble_route(account, argv[3], final_route);
        copy_to_students(final_route, argv[2]);
        assign_permissions(final_route, argv[2], account, "usuarios");
    }

    fclose(fp);

    return 0;
}

void assemble_route(char student[], char route_in_students[], char final_route[])
{
    strcat(final_route, "/home/");
    strcat(final_route, student);
    strcat(final_route, "/");
    strcat(final_route, route_in_students);
}

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

    if (strlen(out) != 0)
    {
        printf("ERROR con %s : %s \n", route, out);
    }

    return 0;
}

void assign_permissions(char route[], char filename[], char user[], char user_group[])
{
    FILE *fp;
    char cmd[256] = "chown ";
    char cmd_perm[256] = "chmod 700 ";
    char out[512] = "";

    if (route[strlen(route) - 1] != '/')
        strcat(route, "/");
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

    if (strlen(out) != 0)
    {
        printf("ERROR con %s : %s \n", route, out);
    }

    fp = popen(cmd_perm, "r");
    fscanf(fp, "%s", out);
    pclose(fp);

    if (strlen(out) != 0)
    {
        printf("ERROR con %s : %s \n", route, out);
    }
}

/*
 * Escribe un mensaje en el archivo de log y en pantalla
 * @param msg Mensaje a escribir
 * @param local_dir_name Nombre del directorio local
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
