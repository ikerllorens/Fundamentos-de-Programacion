#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int IsFileInDirectory(char directory[], char student[]);

int main(void)
{
    FILE *fp = fopen("./Lista.txt", "r");
    char account[16] = "";

    char cmd[256] = "/TAREAS/TAREA1/tarea1.c";
    system("mkdir TAREA1");

    while (fscanf(fp, "%s", account) != EOF)
    {
        printf("> %s\n", account);
        if (IsFileInDirectory(cmd, account) != 0)
        {
            printf("Hubo problema con %s \n", account);
        }
    }

    return 0;
}

int IsFileInDirectory(char directory[], char student[])
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
        printf("ERROR con %s : %s \n", student, out);

    return strlen(out);
}