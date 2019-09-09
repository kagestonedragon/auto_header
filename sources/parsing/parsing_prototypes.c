#include "auto_header.h"
#include <fcntl.h>
#include <stdio.h>

static t_prot   *find_prototypes(char *folder, char *name)
{
    int         fd;
    char        *path;
    char        *line;
    t_prot      *list;
    t_prot      *temporary;

    list = (void *)0;
    path = get_full_path(folder, name);
    if (!(fd = open(path, O_RDONLY)))
        parsing_errors(ERROR_HEADER, path);
    while (get_next_line(fd, &line))
    {
        if (is_prototype(line))
        {
            if (list)
            {
                temporary->next = add_prototype(temporary, line);
                temporary = temporary->next;
            }
            else
            {
                temporary = new_prototype(line);
                list = temporary;
            }
        }
    }
    return (list);
}

int             parsing_prototypes(t_auto_header *core)
{
    t_dir       *temporary_dir;
    t_list      *temporary_list;

    temporary_dir = core->sources_folders->directories;
    while (temporary_dir)
    {
        temporary_list = temporary_dir->files;
        while (temporary_list)
        {
            temporary_list->prototype = find_prototypes(temporary_dir->data, temporary_list->data);
            temporary_list = temporary_list->next;
        }
        temporary_dir = temporary_dir->next;
    }
    core->sources_folders->directories->max_tab = get_max_tabulation(core->sources_folders->directories);
    return (0);
}
