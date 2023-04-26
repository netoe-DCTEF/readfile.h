#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#define BUFFER_LINE 1024

char *filename_dir = "dir.tmp";

bool file_exists(char *filename, char *ext)
{
    int size_of_all = (int)(strlen(filename) + strlen(ext));
    char nameof_file[size_of_all];
    nameof_file[size_of_all] = '\0';
    char *__ptr_nameof = &nameof_file[0];
    strncpy(__ptr_nameof, filename, sizeof(__ptr_nameof) - 1);
    strncat(__ptr_nameof, ext, sizeof(ext) - 1);
    nameof_file[sizeof(nameof_file)] = '\0';

    FILE *find = fopen(__ptr_nameof, "r");

    if (find == NULL)
    {
        puts("I didn't find the file!");
        return false;
    }
    puts("I did find the file!");
    return true;
}
char *get_directory()
{
    char cmm[100];
    char buf[BUFFER_LINE];
    char *ptr_buf = &buf[0];
    FILE *tmp;
    sprintf(cmm, "pwd >> %s", filename_dir);
    system(cmm);
    tmp = fopen(filename_dir, "r");
    fgets(buf, BUFFER_LINE - 1, tmp);
    return buf;
}