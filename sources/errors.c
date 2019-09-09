#include "auto_header.h"
#include <stdio.h>
#include <stdlib.h>

static int  instructions(void)
{
    printf("Usage: ./auto_header <output file> -S <sd1> <sd2> ... -I <header1.h> <header2.h> ...\n\n");
    printf("* <output file> — name of the output file (%%.h file)\n");
    printf("* -S — recursive search in directories (only %%.c files)\n");
    printf("* -I — add header files to the output file (only %%.h files)\n");
    return (0);
}

int         initialization_errors(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("auto_header: Not enough arguments\n\n"); 
        instructions();
        exit(0);
    }
    else if (!is_header_file(argv[1]))
    {
        printf("auto_header: Name of the output file must be ended with \".h\"\n\n");
        instructions();
        exit(0);
    }
    else if (argv[2][0] != '-' || argv[2][1] != 'S')
    {
        printf("auto_header: Error reading arguments (-S)\n\n");
        instructions();
        exit(0);
    }
    else if (argv[3][0] == '-')
    {
        printf("auto_header: Error reading argumners (source directory)\n\n");
        instructions();
        exit(0);
    }
    return (0);
}

int         parsing_errors(int error, char *name)
{
    if (error == ERROR_DIRECTORY)
        printf("auto_make: %s: No such file or directory\n", name);
    if (error == ERROR_HEADER)
        printf("auto_make: %s: Can't open or create file\n", name);
    exit(0);
}
