#include "auto_header.h"
#include <stdlib.h>

static int          parsing_includes(t_auto_header *core, int *i, int argc, char **argv)
{
    t_list          *temporary;

    if (*i + 1 == argc)
        return (0);
    if (!is_file(argv[*i + 1]))
        parsing_errors(ERROR_DIRECTORY, argv[*i + 1]);
    core->includes_files = add_include(argv[*i + 1]);
    is_slash(core->includes_files->data);
    temporary = core->includes_files;
    *i += 2;
    while (*i < argc)
    {
        if (!is_file(argv[*i]))
            parsing_errors(ERROR_DIRECTORY, argv[*i]);
        temporary->next = add_include(argv[*i]);
        is_slash(core->includes_files->data);
        temporary = temporary->next;
        *i += 1;
    }
    return (0);
}

static int          parsing_sources(t_auto_header *core, int argc, char **argv)
{
    int             i;
    t_folders       *temporary;

    if (!is_folder(argv[3]))
        parsing_errors(ERROR_DIRECTORY, argv[3]);
    core->sources_folders = add_folder(argv[3]);
    is_slash(core->sources_folders->data);
    i = 3;
    while (++i < argc)
    {
        if (argv[i][0] == '-' && argv[i][1] == 'I')
            return (parsing_includes(core, &i, argc, argv));
        else
        {
            if (!is_folder(argv[i]))
                parsing_errors(ERROR_DIRECTORY, argv[i]);    
            temporary->next = add_folder(argv[i]);
            is_slash(temporary->next->data);
            temporary = temporary->next;
        }
    }
    return (0);
}

t_auto_header       *parsing(int argc, char **argv)
{
    t_auto_header   *core;

    core = (t_auto_header *)malloc(sizeof(t_auto_header));
    core->file_name = argv[1];
    core->includes_files = NULL;
    parsing_sources(core, argc, argv);
    return (core);
}
