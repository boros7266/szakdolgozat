#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <regex.h>

#define kereses "^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*|^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*|^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*|^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"

int main(int argc, char **argv)
{
    FILE *fp;
    char line[999999];
    int retval = 0;
    regex_t re;
    regmatch_t rm[2];
    const char *filename = "cube.obj";

    if (argc > 1)
        filename = argv[1];

    if (regcomp(&re, kereses, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Regex fordítás sikertelen '%s'\n", kereses);
        return EXIT_FAILURE;
    }

    fp = fopen(filename, "r,w");
    if (fp == 0)
    {
        fprintf(stderr, "Hiba az objektum megnyitása során %s (%d: %s)\n", filename, errno, strerror(errno));
        return EXIT_FAILURE;
    }
    FILE *frp;
    frp=fopen("output", "w");

    while ((fgets(line, 999999, fp)) != NULL)
    {
        line[strlen(line)-1] = '\0';
        if ((retval = regexec(&re, line, 2, rm, 0)) == 0)
        {
            printf("%.*s", (int)(rm[0].rm_eo - rm[0].rm_so), line + rm[0].rm_so);
            printf("\n");
            fprintf(frp,"%.*s", (int)(rm[0].rm_eo - rm[0].rm_so), line + rm[0].rm_so);
            fprintf(frp,"\n");
        }
    }
    return EXIT_SUCCESS;
}
