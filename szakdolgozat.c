#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <regex.h>

//#define kereses "^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*|^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*|^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*|^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"
#define kereses "^v[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"              //geometriai csúcsok listája
#define kereses1 "^vn[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"            //textúra koordinátáinak listája
#define kereses2 "^vt[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"            //normál csúcsok listája
#define kereses3 "^vp[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"            //tér csúcsok listája
#define kereses4 "^f[ \b]([ \t]*[+-]?[0-9]*.[0-9]*[ \t]*)*"             //arc elemek listája

int main(int argc, char **argv)
{
    FILE *fp;
    char line[999999];
    int retval = 0;
    regex_t re,re1,re2,re3,re4;
    regmatch_t rm[2];
    const char *filename = "cube.obj";
    int count=0,count1=0,count2=0,count3=0,count4=0;

    if (argc > 1)
        filename = argv[1];

    if (regcomp(&re, kereses, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Regex fordítás sikertelen '%s'\n", kereses);
        return EXIT_FAILURE;
    }
    if (regcomp(&re1, kereses1, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Regex fordítás sikertelen '%s'\n", kereses1);
        return EXIT_FAILURE;
    }
    if (regcomp(&re2, kereses2, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Regex fordítás sikertelen '%s'\n", kereses2);
        return EXIT_FAILURE;
    }
    if (regcomp(&re3, kereses3, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Regex fordítás sikertelen '%s'\n", kereses3);
        return EXIT_FAILURE;
    }
    if (regcomp(&re4, kereses4, REG_EXTENDED) != 0)
    {
        fprintf(stderr, "Regex fordítás sikertelen '%s'\n", kereses4);
        return EXIT_FAILURE;
    }
    fp = fopen(filename, "r");
    if (fp == 0)
    {
        fprintf(stderr, "Hiba az objektum megnyitása során %s (%d: %s)\n", filename, errno, strerror(errno));
        return EXIT_FAILURE;
    }
    FILE *frp;
    frp=fopen("output.txt", "w");

    while ((fgets(line, 999999, fp)) != NULL)
    {
        line[strlen(line)-1] = '\0';
        if ((retval = regexec(&re, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count++;
        }
        else if ((retval = regexec(&re1, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count1++;
        }
        else if ((retval = regexec(&re2, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count2++;
        }
        else if ((retval = regexec(&re3, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count3++;
        }
        else if ((retval = regexec(&re4, line, 2, rm, 0)) == 0)
        {
            //printf("%s",line + rm[0].rm_so);
            // printf("\n");
            fprintf(frp,"%s",line + rm[0].rm_so);
            fprintf(frp,"\n");
            count4++;
        }
    }
    printf("Geometriai csúcsok száma: %d\n",count);
    printf("Textúra koordinátáinak száma: %d\n",count1);
    printf("Normál csúcsok száma: %d\n",count2);
    printf("Tér csúcsok száma: %d\n",count3);
    printf("Arc elemek száma: %d\n",count4);

    return EXIT_SUCCESS;
}
